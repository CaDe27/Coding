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
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 100005;
ll n;

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


ll inv6 = binPow(6, MOD-2);
void solve(){
    cin>>n;
    ll resp = (n*(n+1));
    resp %= MOD;
    resp *= (4*n-1);
    resp %= MOD;
    resp *= 2022;
    resp %= MOD;
    resp *= inv6;
    resp %= MOD;
    resp = (resp + MOD)%MOD;
    cout<<resp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}