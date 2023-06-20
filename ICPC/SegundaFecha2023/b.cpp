#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef int64_t ll;
#define MOD 1000000007
int n, k;
int const maxN = 1e6+1;
int arre[maxN];
ll fact[maxN], invFact[maxN];
unordered_map<int, int> bucket;

ll binPow(ll base, ll power){
    ll resp = 1, multi = base;
    while(power > 0){
        if(power & 1){
            resp = (resp*multi)%MOD;
        }
        power >>= 1;
        multi = (multi*multi)%MOD;
    }
    return resp;
}

void precalcula(){
    fact[0] = fact[1] = invFact[1] = 1;
    for(int i = 2; i < maxN; ++i){
        fact[i] = (fact[i-1] * i)%MOD;
        invFact[i] = binPow(fact[i], MOD-2);
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(int i =0; i < n; ++i){
        cin>>arre[i];
    }
    precalcula();
    
    for(int i = 0; i < n; ++i){
        ++bucket[arre[i]];
    }

    ll resp = invFact[n];
    for( pair<int, int> keyValue : bucket){
        resp = (resp*fact[keyValue.second])%MOD;       
    }
    cout<<resp<<"\n";

    int a, b;
    for(int i = 0; i < k; ++i){
        cin>>a>>b;
        --a;
        resp = (resp*invFact[bucket[arre[a]]])%MOD;
        --bucket[arre[a]];
        resp = (resp*fact[bucket[arre[a]]])%MOD;

        arre[a] = b;
        ++bucket[b];
        resp = (resp*bucket[b])%MOD;
        cout<<resp<<"\n";
    }
    return 0;
}