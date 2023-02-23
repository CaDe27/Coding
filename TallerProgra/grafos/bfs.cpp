#include <queue>
using namespace std;

const int maxN = 1e5;
vector<int> adj[maxN];

void BFS(){
    queue<int> bfs;
    bool visited[maxN];

    int inicial = 0;
    visited[inicial] = true;

    bfs.push(inicial);

    int actual;
    while(!bfs.empty()){
        actual = bfs.front();
        bfs.pop();

        //procesa el nodo
        //(haz lo que quieras hacer)
        
        for(int son : adj[actual]){
            if(!visited[son]){
                visited[son] = true;
                bfs.push(son);
            }
        }

    }
}
