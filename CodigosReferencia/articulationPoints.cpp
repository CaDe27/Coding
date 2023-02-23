#include<iostream>
#include <vector>
#include <algorithm>

#define optimize() ios_base::sync_with_stdio(0); cin.tie(0);
#define readMyCase() if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin)
#define loop(i, a, b) for(int i = a; i < b; ++i)
#define endl '\n'
#define vi vector<int>

using namespace std;

const int maxN = 10000;
int n, m;

vi adj[maxN+1];
int visited[maxN+1], ancestor[maxN+1];
int articulationPoints, indxVisited, root;

void cleanStuff(){
    loop(i, 1, n+1)
        adj[i].clear();
    fill(visited, visited+n+1, 0);
    fill(ancestor, ancestor+n+1, 0);
    articulationPoints = 0;
    indxVisited = 0;
    root = 1;
}

void dfs(int f, int nd){
    ancestor[nd] = f;
    visited[nd] = ++indxVisited;
    bool band = false;
    int scc = 0;
    for(int son : adj[nd]){
        if(son != f){
            if(visited[son] == 0){
                ++scc;
                dfs(nd, son);
                if( ancestor[son] == nd)
                    band = true;
                if(visited[ancestor[son]] < visited[ancestor[nd]])
                    ancestor[nd] = ancestor[son];
            }
            else if(visited[son] < visited[ancestor[nd]])
                ancestor[nd] = son;
        }
    }
    if(nd == root)
        band = scc>1;
    
    if(band){
        ++articulationPoints;
    }
}


int main(){
    optimize();
    readMyCase();
    
    cin>>n>>m;
    while(!(n == 0 && m == 0)){
        cleanStuff();
        loop(i, 0, m){
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //we can transverse all graph through 1 because we know it's all connected
        dfs(1, 1);
        cout<<articulationPoints<<endl;
        cin>>n>>m;
    }
}