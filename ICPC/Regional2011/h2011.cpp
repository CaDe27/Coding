#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxR = 10005;
int r;

vector<int> adj[maxR];
int discovered[maxR], low[maxR], father[maxR];
int nextIndx;


int find(int u){
    return father[u] == u? u: father[u] = find(father[u]);
}

void unite(int u, int v){
    int fu = find(u), fv = find(v);
    if(fu != fv)
        father[fu] = fv;
}


void dfs(int f, int nd){
    low[nd] = discovered[nd] = ++nextIndx;

    for(int son : adj[nd]){
        if (son == f) continue;

        if(discovered[son] == 0){
            dfs(nd, son);
            low[nd] = min(low[nd], low[son]);
        }
        else 
            low[nd] = min(low[nd], discovered[son]);


        if(low[son] > discovered[nd])
            unite(nd, son);
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int c, q;
    cin>>r>>c>>q;
    while(!(r == 0 && c == 0 && q == 0)){
        for(int i = 1; i <= r; ++i){
            adj[i].clear();
            father[i] = i;
            discovered[i] = 0;
            low[i] = 0;
        }

        for(int i = 0; i < c; ++i){
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        nextIndx = 0;
        //we use a dfs to find bridges, and unite with union find
        for(int i = 1; i<=r; ++i){
            if(discovered[i] == 0)
                dfs(i, i);
        }

       for(int i = 0; i < q; ++i){
            int s,t;
            cin>>s>>t;
            if(find(s) == find(t))
                cout<<"Y\n";
            else
                cout<<"N\n";
        }
        cout<<"-\n";
        cin>>r>>c>>q;
    }
}