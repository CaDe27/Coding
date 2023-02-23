#include <iostream>

using namespace std;

typedef __int128 ll;

ll binPow(ll base, ll exp, ll MOD){
    base%= MOD;
	ll r = 1;
	while (exp > 0){
		if( exp & 1)
			r = (r*base) % MOD;
		exp >>= 1;
		base = (base * base) % MOD;
	}
	return r;   
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll b,d;
    
    int64_t aux1, aux2;
    cin>>aux1>>aux2;
    b = (ll)aux1;
    d = (ll)aux2;


    bool band;
    // p dividea b
    if(b%d == 0)
        band = false;
    else if (d == 2)
        band = true;
    else{
        ll order = (d-1)/2;
        while( (binPow(b, order, d)==1) &&  (order%2==0) )
            order >>= 1;
        band = (binPow(b, order, d) == d-1);
    }
    if(band)
        cout<<"yes";
    else
        cout<<"no";
}