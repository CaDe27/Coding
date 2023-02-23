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
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;
bool visited[maxN];
int father[maxN];
int n, m;
vector<int> adj[maxN];

void dfs(int nd, int f){
    visited[nd] = true;
    father[nd] = f;
    for(int son : adj[nd]){
        if(!visited[son]){
            dfs(son, nd);
        }
    }
}

void imprime(int nd){
    if(visited[nd])
        return;
    
    visited[nd] = true;
    cout<<nd<<" ";
    for(int i = adj[nd].size() - 1; i > -1; --i){
        if(father[ adj[nd][i] ] == nd){
            imprime(adj[nd][i]);
        }
    }
}   



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>m;
    int a, b;
    loop(i, 0, m){
        cin>>a>>b;
        adj[b].push_back(a);
    }
    

    stack<int> primeros;
    loop(i, 1, n+1){
        if(!visited[i]){
            dfs(i, 0);
            primeros.push(i);
        }
    }

    fill(visited, visited + n+1, 0);
    while(!primeros.empty()){
        imprime(primeros.top());
        primeros.pop();
    }
    cout<<"\n";
    return 0; 
}
