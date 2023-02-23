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

typedef pair<int,ll> pill;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 998244353 

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 18, maxNodos = (1<<18)-1;
int n, cantNodos;
string s;
string claseEquivalencia[maxNodos+5];
void calculaEquiv(int id){
    if(id<<1 < cantNodos){
        calculaEquiv(id<<1);
        calculaEquiv( (id<<1) +1);
        if(claseEquivalencia[id<<1] < claseEquivalencia[ (id<<1)+1])
            claseEquivalencia[id] = s[id-1] + claseEquivalencia[id<<1] + claseEquivalencia[(id<<1)+1];
        else
            claseEquivalencia[id] = s[id-1] + claseEquivalencia[(id<<1)+1] + claseEquivalencia[id<<1];
    }
    else{
        claseEquivalencia[id] = s[id-1];
    }
}

ll dp[maxNodos+5];
void calculaDP(int id){
    if( (id<<1) > cantNodos){
        dp[id] = 1;
    }
    else{
        calculaDP(id<<1);
        calculaDP((id<<1) + 1);
        if(claseEquivalencia[id<<1] == claseEquivalencia[(id<<1)+1])
            dp[id] = (dp[id<<1]*dp[id<<1])%MOD;
        else{
            dp[id] = (dp[id<<1]*dp[(id<<1)+1])%MOD;
            dp[id] = (2*dp[id])%MOD;
        }
    }
}

void solve(){
    cin>>n>>s;
    cantNodos = (1<<n)-1;
    //calcula claseEquivalencia
    calculaEquiv(1);
    //calculaDP
    calculaDP(1);
    cout<<dp[1]<<"\n";
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
