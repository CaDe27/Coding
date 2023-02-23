#include<iostream>
#include<queue>

using namespace std;

const int maxN = 2*(1e5) + 5;
int n; 
vector<int> adj[maxN];
int minLeaf;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > sonsMinLeaf[maxN];
vector<int> order; 

void dfs(int v, int fa){
    int sonsCount = 0;
    for(int son : adj[v]){
        ++sonsCount;
        if(son != fa)
            dfs(son, v);
    }
    if(sonsCount == 1)
        minLeaf = min(minLeaf, v);
}

pii fillHeaps(int node, int blocked){
    for(int son : adj[node]){
        if(son == blocked)
            continue;
        sonsMinLeaf[node].push(fillHeaps(son, node));   
    }
    if(!sonsMinLeaf[node].empty())
        return pii(sonsMinLeaf[node].top().first, node);
    else
        return pii(node, node);
}

void print1(int node, int blocked){
    int nextSon;
    while(!sonsMinLeaf[node].empty()){
        nextSon = sonsMinLeaf[node].top().second;
        sonsMinLeaf[node].pop();
        if(nextSon == blocked) continue; //think its not neccesary?
        print1(nextSon, node);
    }
    order.push_back(node);
}

void print2(int node, int blocked){
    int nextSon;
    while(sonsMinLeaf[node].size() >= 2){
        nextSon = sonsMinLeaf[node].top().second;
        sonsMinLeaf[node].pop();
        if(nextSon == blocked) continue;
        print1(nextSon, node);
    }
    //I decide whether I print this node or my sons subtree
    if(sonsMinLeaf[node].size() == 1){
        if(node < sonsMinLeaf[node].top().first){
            order.push_back(node);
            print2(sonsMinLeaf[node].top().second, node);
        }
        else{
            print1(sonsMinLeaf[node].top().second, node);
            order.push_back(node);
        }
    }
    else
        order.push_back(node);
}

int solve(){
    minLeaf = 1e6;
    order.clear();
    cin>>n;
    for(int i =1 ; i <= n; ++i){
        adj[i].clear();
        while(!sonsMinLeaf[i].empty())
            sonsMinLeaf[i].pop();
    }
    for(int i = 0, a, b; i < n-1; ++i){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);

    order.push_back(minLeaf);
    fillHeaps(adj[minLeaf][0], minLeaf);
    print2(adj[minLeaf][0], minLeaf);

    cout<<order[0];
    for(int i = 1; i < n; ++i){
        cout<<" "<<order[i];
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}