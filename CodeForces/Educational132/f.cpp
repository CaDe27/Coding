#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>
#include <complex>
#define INF 1000000000000
#define MOD 998244353
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)
using namespace std;
typedef int64_t ll;

const int MAXN = 200005;
// =============== NNT  ======================================
const ll mod = 998244353;
const ll root = 15311432; // which is basically 3 ^ 119 
const ll root_1 = 469870224;
const ll root_pw = (1 << 23);

ll fact[MAXN + 1], ifact[MAXN + 1], sum_pow[MAXN + 1];
vector<ll> P(MAXN); // this will be the first few terms of e^(x + (x^2)/2).

ll fxp(ll a, ll n){ // returns a ^ n modulo mod in O(log(mod)) time
	if(!n){
		return 1;
	}else if(n & 1){
		return a * fxp(a, n ^ 1) % mod;
	}else{
		ll v = fxp(a, n >> 1);
		return v * v % mod;
	}
}

inline ll inverse(ll a){ // returns the modular inverse of 
	return fxp(a % mod, mod -2);
}

void init_fact(){ // initializes fact[ ] and ifact[ ]
	fact[0] = ifact[0] = 1;
	for(int i = 1; i <= MAXN; ++i){
		fact[i] = fact[i - 1]  * i% mod;
		ifact[i] = inverse(fact[i]);
	}
}

ll C(ll n, ll r){ // returns nCr in O(1) time
	return (r > n || r < 0) ? 0 : (ifact[r] * ifact[n - r] % mod * fact[n] % mod);
}

// code for fft in O(nlogn)
void fft(vector<ll>& a, bool invert){
	int n = a.size();

	/// this does the bit inversion 
	for(int i = 1, j = 0; i < n; ++i){
		int bit = n >> 1;
		for(; j & bit; bit >>= 1){
			j ^= bit;
		}
		j ^= bit;
		if(i < j){
			swap(a[i], a[j]);
		}
	}

	for(int len = 2; len <= n; len <<= 1){
		ll wlen = invert ? root_1: root;
		for(int i = len; i < root_pw; i <<= 1){
			wlen = wlen * wlen % mod;
		}
		for(int i = 0; i < n; i += len){
			ll w = 1;
			for(int j = 0; j < len / 2; ++j){
				ll u = a[i + j], v = a[i + j + len / 2] * w % mod;
				a[i + j] = u + v < mod ? u + v : u + v - mod;
				a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
				w = w * wlen % mod;
			}
		}
	}

	if(invert){
		ll n_1 = inverse(n);
		for(ll& x : a){
			x = x * n_1 % mod;
		}
	}
}

//multiplying two polynomials a and b using ntt in O(max(A, B)log(max(A, B))), where A, B are degrees of a, b respectively
vector<ll> mul(vector<ll> const& a, vector<ll> const& b){

	vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while(n < (int)a.size() + (int)b.size()){
		n <<= 1;
	}
	fa.resize(n);
	fb.resize(n);

	fft(fa, false);
	fft(fb, false);
	for(int i = 0; i < n; ++i){
		fa[i] = fa[i] * fb[i] % mod;
	}
	fft(fa, true);
	while(fa.size() > 1 && fa[fa.size() - 1] == 0){
		fa.pop_back();
	}

	return fa;
}
// =============== NNT  ======================================

int n, f, k;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>k>>f;
	
	if(f > 2*k){
		cout<<0<<"\n";
		return 0;
	}

	vector<ll> dp(k+1);
	vector<ll> convolucion(2*k+1);
	vector<ll> acumConv(2*k+1);

	//nivel 1
	fill(dp.begin(), dp.end(), 1);
	convolucion = mul(dp, dp);
	for(int i = 0; i < 2*k; ++i)
		convolucion[i]%=MOD;
	
	acumConv[0] = convolucion[0];
	for(int i = 1; i < 2*k+1; ++i)
		acumConv[i] = (convolucion[i]+acumConv[i-1])%MOD;

	//siguientes niveles
	for(int it_n = 1; it_n < n; ++it_n){
		//calcula nueva dp
		
		for(int i = 0; i <= k; ++i){
			dp[i] = acumConv[2*k];
			if(i>0)
				dp[i] = ((dp[i] - acumConv[i-1])%MOD + MOD)%MOD;
			ll aux = (((ll)(k-i))*convolucion[i])%MOD;
			dp[i] = (dp[i] + aux)%MOD;
		}
		convolucion = mul(dp, dp);
		for(int i = 0; i < 2*k; ++i)
			convolucion[i]%=MOD;

		acumConv[0] = convolucion[0];
		for(int i = 1; i < 2*k+1; ++i)
			acumConv[i] = (convolucion[i]+acumConv[i-1])%MOD;
	}

	cout<<convolucion[f]<<"\n";
}