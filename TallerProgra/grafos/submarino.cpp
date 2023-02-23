#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

int n, e, t;
vector< vector<int> > adj;
int BFS(){
    queue<pii> cola;
    cola.push(pii(n-1, 0));

    int nodo, tiempo, salvados = 0;
    bool encola[n];
    fill(encola, encola + n, false);
    encola[n-1] = true;
    while(!cola.empty() && cola.front().second < t){
        nodo = cola.front().first;
        tiempo=cola.front().second;
        cola.pop();
        
        ++salvados;
        for(int nodoAdyacente : adj[nodo]){
            if(!encola[nodoAdyacente]){
                cola.push(pii(nodoAdyacente, tiempo + 1));
                encola[nodoAdyacente] = true;
            }
        }
    }
    return salvados-1;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>e>>t;
    adj.resize(n);
    for(int i = 0, a, b; i < e; ++i){
        cin>>a>>b;
        --a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<BFS()<<"\n";
}