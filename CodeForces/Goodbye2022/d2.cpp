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
#define MOD 998244353

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 1e5 + 5;
int n, a[maxN], b[maxN];
vector<int> adj[maxN];
bool visited[maxN]; 

int edges, vertices, self_loops, connected_components;
void dfs(int i){
    if(visited[i]) return;
    visited[i] = true;
    ++vertices;
    for(int v : adj[i]){
        ++edges;
        dfs(v);
        if(v == i) ++self_loops;
    }
}

void solve(){
    cin>>n;

    self_loops = connected_components = 0;
    fill(visited, visited + n, 0);
    loop(i, 0, n){
        adj[i].clear();
    }
    
    loop(i, 0, n) cin>>a[i];
    loop(i, 0, n) cin>>b[i];

    loop(i, 0, n){
        --a[i]; --b[i];
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    
    loop(i, 0, n){
        if(!visited[i]){
            ++connected_components;
            edges = vertices = 0;
            dfs(i);
            if( edges != (vertices<<1) ){
                cout<<"0\n";
                return;
            }
        }
    }

    self_loops>>=1;
    ll respSelfLoops=1, respNonSelf=1;
    loop(i, 0, self_loops){
        respSelfLoops = (n * respSelfLoops)%MOD; 
    }
    int limit2 = connected_components - self_loops;
    loop(i, 0, limit2){
        respNonSelf = (2 * respNonSelf)%MOD;
    }
    cout<< (respSelfLoops*respNonSelf)%MOD <<"\n";
     

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