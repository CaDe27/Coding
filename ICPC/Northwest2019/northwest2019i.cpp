#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)

#define noOne maxN+1
#define LEFT 0
#define RIGHT 1


const int maxN = 505;
string words[maxN];
int n, sizeW, finalNode;
int visited[maxN], side[maxN], match[maxN], parent[maxN];
vi adj[maxN];


//las conecto si solo las separa un swap
bool connected(string a, string b){
    int cont = 0;
    loop(i, 0, sizeW){
        if(a.at(i) != b.at(i))
            ++cont;
    }
    return cont == 2;
}

void dfs(int v, int parity){
    visited[v] = true;
    side[v] = parity&1? LEFT : RIGHT;
    for(int son : adj[v]){
        if(!visited[son])
            dfs(son, parity^1);
    }
}

// ================ MAX BIPARTITE MATCHING

//instrucciones:
// al lado izquierdo los representa con indices [0,n-1] 
// al lado derecho con indices [n, n+m-1]
// solo tienes que crear la lista de adjacencia con
// addEdge y correr maxBPM()

// indicaciones de adEdge(i, j)
// i pertence al conjunto izq y j al derecho
// si en un problema es al revés (n el der y m el izq)
// no importa, solo haz el addEdge(der, izq)

// variables gloables
//n tamanio lado izq, m tamnio ladoDer


bool BFS(){
    queue<int> bfs;
    bool newPath = false;

    for(int i = 0; i < n; ++i) parent[i] = i;
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
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);


    cin>>n;
    loop(i, 0, n)
        cin>>words[i];

    sizeW = words[0].size();

    loop(i, 0, n)
    loop(j, i+1, n){
        if( connected(words[i], words[j]) ){
            adj[i].push_back(j);
            adj[j].push_back(i);
        }   
    }

    //color bipartite graph
    loop(i, 0, n)   
        if(!visited[i])
            dfs(i, 1);
    
    cout<<n - maxBPM()<<endl;
    return 0;
}