#include <vector>
using namespace std;

const int maxN = 1e5;
vector<int> adj[maxN];
bool visited[maxN];

void dfs(int f, int nd){
    visited[f] = true;
    for(int son : adj[nd]){
        if(son == f) continue;
        else if(!visited[son]){
            dfs(nd, son);

        }
    }
}

