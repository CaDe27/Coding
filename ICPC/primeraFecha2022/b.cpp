#include<iostream>
#include <vector>
#include <queue>

using namespace std;
#define loop(i, a, b) for(int i = a; i < b; ++i)
priority_queue<int, vector<int>, greater<int> > minHeap;

const int maxN = 1e5 +5;
int f[maxN];
bool visited[maxN]; 

vector<int> adj[maxN];
void dfs(int v, int fa){
    f[v] = fa;
    for(int u : adj[v])
        if(u != fa)
            dfs(u, v);
} 

int n, k;
vector<int> unlock[maxN];
void cadenaUnlock(int v){
    int ancestor = f[v];
    int lvl = 1;
    while(lvl != k && ancestor != 1){
        ancestor = f[ancestor];
        ++lvl;
    }

    while(!visited[v]){
        visited[v] = true;
        unlock[ancestor].push_back(v);
        v = f[v];
        ancestor = f[ancestor];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    int a, b;
    loop(i, 0, n-1){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    visited[1] = true;

    loop(i, 2, n+1)
        cadenaUnlock(i);

    vector<int> resp;
    minHeap.push(1);
    while(!minHeap.empty()){
        a = minHeap.top();
        minHeap.pop();

        resp.push_back(a);
        for(int v : unlock[a])
            minHeap.push(v);
    }
    cout<<resp[0];
    loop(i, 1, n)
        cout<<" "<<resp[i];
    cout<<"\n";
    return 0;
}