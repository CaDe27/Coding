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

const int maxN = 2e5 + 5;
ll n, k;
vector<int> adj[maxN];
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

ll fact[maxN], invF[maxN];
void preCalcula(int n){
    fact[0] = fact[1] = 1;
    invF[0] = invF[1] = 1;
    loop(i, 2, n+1){
        fact[i] = (fact[i-1]*i) % MOD;
        invF[i] = binPow(fact[i], MOD-2);
    }
}

int sizeSubTree[maxN];
void dfsSizeSubTree(int v, int pre){
    sizeSubTree[v] = 1;
    for(int son : adj[v]){
        if(son == pre) 
            continue;

        dfsSizeSubTree(son, v);
        sizeSubTree[v] += sizeSubTree[son];
    }
}

ll comb(int a, int b){
    return b > a? 0 : (((fact[a]*invF[b])%MOD)*invF[a-b])%MOD;
}

ll resp = 1, invCombNK;
// E[good nodes] = E[1 + good edges]
void dfsResp(int v, int pre){
    ll respCase;
    if(v != 0){
        respCase = comb(sizeSubTree[v], k>>1)*comb(n-sizeSubTree[v], k>>1);
        respCase %= MOD;
        respCase*= invCombNK;
        respCase %= MOD;

        resp += respCase;
        resp %= MOD;
    }
    
    for(int son : adj[v]){
        if(son == pre)
            continue;
        dfsResp(son, v);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n>>k;
    if(k&1){
        cout<<1<<"\n";
        return 0;
    }

    preCalcula(n);
    invCombNK = binPow(comb(n, k), MOD-2);
    loop(i, 0, n-1){
        int a, b;
        cin>>a>>b;
        --a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfsSizeSubTree(0, 0);
    dfsResp(0, 0);
    cout<<resp<<"\n";
    return 0;
}