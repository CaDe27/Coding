#include <iostream>
#include <algorithm>
using namespace std;
typedef int64_t ll;

ll n, x;
const int maxN = 200000+5;
ll a[maxN];
ll waterNeeded(ll h){
    ll resp = 0;
    for(ll i = 0; i < n; ++i)
        resp += max((ll)0, h-a[i]);
    return resp;
}

void solve(){
    cin>>n>>x;
    for(ll i = 0; i <n; ++i)
        cin>>a[i];
    
    ll ini = 1, fin = 2e9+1, mid;
    while(ini != fin){
        mid = (ini + fin + 1)/2;
        if(waterNeeded(mid) > x) //¿eres un menos?
            fin = mid-1;
        else // eres un más
            ini = mid;
    }
    cout<<ini<<"\n";
}

ll main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    ll t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}