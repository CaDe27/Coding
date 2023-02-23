#include <iostream>
#include <cstdint>
#define mod 1000000007
typedef int64_t ll;
using namespace std;


ll binPow(ll base, ll exp){
    //by Fermat's Little Theorem, a^(q*mod + r) congruent to a^(q+r)
    exp += -(exp/mod)*mod+(exp/mod);
	ll r = 1;
	while (exp > 0){
		if( exp & 1)
			r = (r*base) % mod;
		exp >>= 1;
		base = (base * base) % mod;
	}
	return r;
} 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	if(fopen("case.txt","r")) freopen("case.txt","r",stdin);
    int T;
    cin>>T;
    ll n, resp;
    for(int t = 0; t < T; ++t){
        cin>>n;
        resp = binPow(n, n+1);
        resp += -n+1;
        if(resp < 0)
            resp+=mod;
        cout<<resp<<"\n";
    }
}