#include <iostream>
#include <vector>
#include <stack>

#define loop(i, a, b) for(int i = a; i < b; ++i)
using namespace std;
int n, m; 
int totalEvents = 0; 

int counter = 0;
vector<vector<int> > events;

const int maxN = 2*1e5 + 5;
vector<int> adj[maxN];
int visited[maxN];
int level[maxN];

bool dfs(int node, int predecessor){
    visited[node] = true;
    level[node] = level[predecessor] + 1;
    stack<int> cities;
    bool needsMe;
    for(int son : adj[node]){
        if(son != predecessor){
            if(!visited[son]){
                needsMe = dfs(son, node);
                if(needsMe) 
                    cities.push(son);    
            }
            else if(level[son] < level[node])
                cities.push(son);
        }
    }

    while(cities.size() > 1){
        vector<int> activeEvent;
        ++counter;
        activeEvent.push_back(cities.top());
        cities.pop();
        activeEvent.push_back(node);
        activeEvent.push_back(cities.top());
        cities.pop();
        events.push_back(activeEvent);
    }

    if(!cities.empty() && predecessor != 0){
        ++counter;
        vector<int> activeEvent;
        activeEvent.push_back(cities.top());
        cities.pop();
        activeEvent.push_back(node);
        activeEvent.push_back(predecessor);
        events.push_back(activeEvent);
        return false;
    }
    else
        return true;
}

int main (){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>m;
    int a, b;
    loop(i, 0, m){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    level[0] = 0;
    loop(i, 1, n+1){
        if(!visited[i]){
            dfs(i, 0);
        }
    }
    
    cout<<counter<<"\n";
    for(auto event : events){
        cout<<event[0]<<" "<<event[1]<<" "<<event[2]<<"\n";
    }
}