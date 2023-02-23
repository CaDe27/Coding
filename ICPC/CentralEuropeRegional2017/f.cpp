
#include <iostream>
using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;
ll n, p;
ll binPow(ll base, ll exp){
	ll r = 1;
	while (exp > 0){
		if(exp & 1)
			r = (r*base) % p;
		exp >>= 1;
		base = (base * base) % p;
	}
	return r%p;
} 


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll r;
    cin>>n>>p>>r;

    pii resp;
    if(r == 0){
        if(n==2 || n<p)
            resp = pii(-1,-1);
        else if(p == 2)
            resp = pii(3,1);
        else
            resp = pii(2,1);
    }
    else{
        if(n>=2*p)
            resp = pii(-1,-1);
        else if(n>=p){
            ll nfact = p-1;
            for(ll i = p+1; i <= n; ++i)
                nfact = (nfact*(i-p))%p;

            // sustituimos a p por r* (n!/p)^-1
            ll aux = (r*binPow(nfact, p-2) )%p;
            resp = pii(p,aux);
        }
        else{
            ll fact = 1;
            for(ll i = 2; i <= n; ++i)
                fact = (fact*i)%p;

            // guardamos c = r*(n!)^-1 mod p
            ll c = (r*binPow(fact, p-2))%p;

            //buscamos el primer a entre 1 y n tal que a*c mod p < a
            ll a = 2;
            while(a<n+1 && (c*a)%p >= a)
                ++a;

            if(a == n+1)
                resp = pii(-1,-1);
            else
                resp = pii(a,(c*a)%p);
            
            }
    }
    cout<<resp.first<<" "<<resp.second<<"\n";

    return 0;
}
