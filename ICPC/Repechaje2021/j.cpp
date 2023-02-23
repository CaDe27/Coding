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
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 1005;
int n; 

bool visited[maxN];
vector<int> adj[maxN];
int dfs(int v){
    int sons = 0;
    visited[v] = true;
    for(int u : adj[v]){
        if(!visited[u])
            sons += dfs(u);
    }
    return 1 + sons;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int p;
    cin>>n>>p;
    loop(i, 0, p){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> numbers;
    loop(i, 1, n+1){
        if(!visited[i])
            numbers.push_back(dfs(i));
    }
    bool generated[maxN];
    fill(generated, generated + maxN, 0);
    generated[0] = true;
    for(int v: numbers){
        for(int i = n; i >= 0; --i)
            if(generated[i])
                generated[i + v] = true;
    }

    int cont = 0;
    loop(i, 1, n+1){
        if(generated[i]) 
            ++cont;
    }
    cout<<cont<<"\n";
    
    return 0;

}