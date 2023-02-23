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
#define M_PI 3.14159265358979323846264338327950288

using namespace std;
 
typedef int64_t ll;

typedef pair<int,ll> pill;
typedef pair<int,int> pii;

#define INF 1e13
#define MOD ((ll)1000003)

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 200000 + 5;
ll n, a, b, c; 

// ============== bin pow
ll binPow(ll base, ll exp){
    ll r = 1;
    while (exp > 0){
        if( exp & 1)
            r = (r*base) % MOD;
        exp >>= 1;
        base = (base * base) % MOD;
    }
    return r;
} 

//======= factorials
ll fact[2*maxN], invFact[2*maxN], potA[2*maxN], potB[2*maxN];
ll comb(int num, int k){
    if (num < 0 || num < k) return 0;
	if(k == 0) return 1;
    return (((fact[num]*invFact[k])%MOD)*invFact[num-k])%MOD;
}
void fillFact(){
	fact[0] = invFact[0] = potA[0] = potB[0] =  1;
    for(int i = 1; i < 2*n; ++i){
        fact[i] = (fact[i-1]*i)%MOD;
        invFact[i] = binPow(fact[i], MOD-2);
    }

	for(int i = 1; i < n;++i){
		potA[i] = (potA[i-1]*a)%MOD;
		potB[i] = (potB[i-1]*b)%MOD;
	}
	
}


// ============ FFT
typedef complex<double> base;

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();

	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}

	for (int len=2; len<=n; len<<=1) {
		double ang = 2*(M_PI)/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1<<20;
ll reverse(int x, int y){
    return (ll) binPow(x, y-2);
}

void fft (vector<ll> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		int wlen = invert ? root_1 : root;
		for (int i=len; i<root_pw; i<<=1)
			wlen = int (wlen * 1ll * wlen % mod);
		for (int i=0; i<n; i+=len) {
			int w = 1;
			for (int j=0; j<len/2; ++j) {
				int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = int (w * 1ll * wlen % mod);
			}
		}
	}
	if (invert) {
		ll nrev = reverse (n, mod);
		for (int i=0; i<n; ++i)
			a[i] = ll (a[i] * 1ll * nrev % mod);
	}
}

void multiply (const vector<ll> & a, const vector<ll> & b, vector<ll> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);

	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);

	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = (ll) round(fa[i].real());
}
// ============ ============  FFT
void fillF(vector<ll> & f, int a){
	f.resize(n-1);
	f[0] = 1;
	loop(i, 1, n-1){
		f[i] = (potA[i] * invFact[i]) %MOD;
	}
}

void fillG(vector<ll> & g, int b){
	g.resize(n-1);
	g[0] = 1;
	loop(i, 1, n-1){
		g[i] = (potB[i] * invFact[i]) %MOD;
	}
}

ll coefC(){
	vector<ll> f, g, conv;
    fillF(f, a);
	fillG(g, b);

	multiply(f, g, conv);
	
	ll cCoef = 0;
	loop(i, 0, 2*n-3)
		cCoef = (cCoef + (fact[i]*conv[i])%MOD) %MOD;
	return (cCoef*c)%MOD;
}

void solve(){
    cin>>n>>a>>b>>c;
	fillFact();
	
	vector<ll> l(n+1), t(n+1);
	loop(i, 1, n+1) cin>>l[i];
	loop(i, 1, n+1) cin>>t[i];

	ll resp = coefC();
	ll aux;
	loop(i, 2, n+1){
		aux = t[i];
		aux = (aux * potB[n-1])%MOD;
		aux = (aux * potA[n-i])%MOD;
		aux = (aux * comb(n-2 + n-i, n-2))%MOD;
		resp= (resp + aux)%MOD;
	}

	loop(i, 2, n+1){
		aux = l[i];
		aux = (aux * potA[n-1])%MOD;
		aux = (aux * potB[n-i])%MOD;
		aux = (aux * comb(n-2 + n-i, n-2))%MOD;
		resp= (resp + aux)%MOD;
	}

	cout<<resp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}