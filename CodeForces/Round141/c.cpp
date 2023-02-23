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

using namespace std;

typedef int64_t ll;
typedef pair<ll,ll> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(ll i = a; i < b; ++i)
#define iloop(i,a,b) for(ll i = a; i > b; --i)

const int maxN = 500005;
ll n, m, arre[maxN], lugar[maxN], numeroLugar[maxN];
pii pares[maxN];

bool sePuede(ll t){
    if(t == n+1)
        return true;
    ll ganale = n-t+1;
    if( arre[ganale - 1] <= m)
        return true;
    ganale = n-t;
    //cout<<t<<" "<<lugar[t]<<" "<<numeroLugar[lugar[t]]<<endl;
    if(lugar[t] <= n-t){
        if(arre[ganale - 1] <= m)
            return true;
    }
    else
        {
            ll sumaSinEl = n-t==1? 0 : arre[n-t-1 -1];
            if(sumaSinEl + numeroLugar[lugar[t]] <= m)
                return true;
        }
        
    return false;
}
ll binaria(){
    ll ini = 1, fin = n+1, mitad;
    while(ini != fin){
        mitad = (ini + fin)/2;
        if(sePuede(mitad)){
            fin = mitad;
        }
        else
            ini = mitad+1;
    }
    return ini;
}

void solve(){
    cin>>n>>m;
    loop(i, 1, n+1){
        cin>>arre[i];
        pares[i] = pii(arre[i], i);
    }
    sort(arre+1, arre+n);
    loop(i, 2, n){
        arre[i] += arre[i-1];
    }

    sort(pares+1, pares+n+1);
    ll indxL = 1, indx = 1;
    while(indx < n){
        ++indxL;
        lugar[pares[indx].second] = indxL;
        numeroLugar[indxL] = pares[indx].first;
        ++indx;
        while(indx < n && pares[indx].first == pares[indx-1].first){
            lugar[pares[indx].second] = indxL;
            ++indx;
        }
    }
    
    cout<<binaria()<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    ll t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}