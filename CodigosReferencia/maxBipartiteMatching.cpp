#include <iostream>
#include <queue>

using namespace std;

// ================ MAX BIPARTITE MATCHING

//instructions:
// create bipartite graph normally
// run dfs to determine the side of each vertex
// run maxBPM()


// global variable
// n total size of both sides

const int maxN = 505;
int n, finalNode;
int visited[maxN], side[maxN], match[maxN], parent[maxN];
vector<int> adj[maxN];

#define noOne maxN+1
#define LEFT 0
#define RIGHT 1

void dfs(int v, int parity){
    visited[v] = true;
    side[v] = parity&1? LEFT : RIGHT;
    for(int son : adj[v]){
        if(!visited[son])
            dfs(son, parity^1);
    }
}

bool BFS(){
    queue<int> bfs;
    bool newPath = false;

    fill(visited, visited+n, 0);

    //free vertex from left side into the bfs
    for(int i = 0; i < n; ++i){
        if(match[i] == noOne && side[i] == LEFT){
            bfs.push(i);
            visited[i] = true;
        }
    }
      
    //perform bfs
    while(!bfs.empty()){    
        int v = bfs.front();
        bfs.pop();

        // we are on the right side looking for 
        // a matching edge
        if(side[v] == RIGHT){
            //if its a free vertex I've already finished
            if(match[v] == noOne){
                newPath = true;
                finalNode = v;
                break;
            }
            else{
                int myMatch = match[v];
                
                //I mark it as visited and add it to bfs
                //I'm the only one who can visit it in bfs
                visited[myMatch] = true;
                parent[myMatch] = v;
                bfs.push(myMatch);
            }
        }
        // we are on the left side looking for
        // a non-matching edge
        else{   
            for(int son : adj[v]){
                //if it's visited already, I don't visit it
                // i don't check whether it's my match or not because
                // only my match can push me to bfs and it's already visited
                if(visited[son]) continue;

                //I mark it as visited and add it to bfs
                visited[son] = true;
                parent[son] = v;
                bfs.push(son);
            }
        }
    }
    return newPath;
}


int maxBPM(){
    int sizeMatching = 0;
    fill(match, match+n, noOne);

    while(BFS()){
        ++sizeMatching;
        int v = finalNode;
        int parity = 1;
        while(parent[v] != v){
            //we reassign matching nodes in odd number steps
            if(parity){
                match[v] = parent[v];
                match[parent[v]] = v;
            }
            parity &= 1;
            v = parent[v];
        }
    }
    
    return sizeMatching;
}

//=================== FIN MAXIMUM BIPARTITE MATCHING

int main(){

    for(int i = 0; i < n; ++i)
        if(!visited[i]) 
            dfs(i, 1);
    cout<<maxBPM()<<endl;
    
    return 0;
}