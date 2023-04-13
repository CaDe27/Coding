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

const int maxN = 200005;
int n; 
ll x;
int arre[maxN];

bool v[maxN][25][2];
ll dp[maxN][25][2];
ll DP(int i, int k, int e){
    if(i == n)
        return k == 0? 0 : -1e15;
    if(k < 0) return -1e15;
    if(n-i < k) return -1e15;
    if(e == 2) return 0;

    if(!v[i][k][e]){
        v[i][k][e] = 1;
        if(e == 1){
            //lo cierro o no
            dp[i][k][e] = max( max(DP(i+1, k, 2), DP(i+1, k-1, 2)), arre[i]+max(x+DP(i+1, k-1, 1), -x+DP(i+1, k, 1)));
        }  
        else{
            //lo inicio o no
            dp[i][k][e] = max(
                arre[i]+max(x + DP(i+1, k-1, 1), -x + DP(i+1, k, 1)),
                max(DP(i+1, k-1, 0), DP(i+1, k, 0))
            );
        }
    }
    return dp[i][k][e];
}

void solve(){
    
    int k;
    cin>>n>>k>>x;

    loop(i, 0, n+1){
    loop(ki, 0, k+1)
    loop(j, 0, 2){
        v[i][ki][j] = 0;
    }
    }

    loop(i, 0, n)
        cin>>arre[i];

    cout<<DP(0, k, 0)<<"\n";
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