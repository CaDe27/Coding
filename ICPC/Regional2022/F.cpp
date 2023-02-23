#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define loop(i, a, b) for(int i = a; i <b; ++i)

const int maxN = 3*1e5 + 5;
int n, arre[maxN];
vector<int> adj[maxN];
bool visited[maxN];
char resp[maxN];


void dfsB(int u, int fa){
    visited[u] = true;
    resp[u] = 'B';
    for(int h : adj[u]){
        if(visited[h]|| h == n) continue;
        dfsB(h, u);
    }
}

void dfsA(int u, int fa){
    visited[u] = true;
    resp[u] = 'A';
    for(int h : adj[u]){
        if(visited[h]) continue;
        dfsA(h, u);
    }
}


void solve(){
    int m;
    cin>>n>>m;
    int a,b ;
    loop(i, 0, m){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    dfsB(n-1, 0);
    dfsA(n, 0);

    loop(i, 1, n+1)
        cout<<resp[i];
    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1; //cin>>t;
    loop(i, 0, t){
        solve();
    }   
    return 0;

}