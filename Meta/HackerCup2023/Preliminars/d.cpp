// to run it locally, I had to run ulimit -s 65520 to increment the
// stack limit
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <queue>
#define INF 1000000000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;
const int maxN = 3e5+5;
int n, m;

vector<int> adj[maxN];
vector<int> adjReduced[maxN];
int distanceToOdd[maxN], sizeReduced, level[maxN];
bool isOdd[maxN], visited[maxN];
//backEdgesUp tells the number of edges that go from a node from its subtree (including it)
// to a node that is above that node
int backEdgesUp[maxN], componentID[maxN];
int currentID;
void dfsSpreadComponent(int v, int fa){
    componentID[v] = currentID;
    for(int son : adj[v]){
        if(son == fa) continue;
        if(componentID[son] == -1)
            dfsSpreadComponent(son, v);
        else if(componentID[son] != currentID){
            adjReduced[currentID].push_back(componentID[son]);
            adjReduced[componentID[son]].push_back(currentID);
        }
    }
}

void dfsBackEdges(int v, int fa){
    visited[v] = true;
    for(int son : adj[v]){
        if(son == fa) continue;
        if(visited[son]){
            if(level[son] > level[v]) continue;
            --backEdgesUp[son];
            ++backEdgesUp[v];
        }
        else{
            level[son] = level[v] + 1;
            dfsBackEdges(son, v);
            backEdgesUp[v] += backEdgesUp[son];
        }
    }
    //if there are no back edges, the edge connecting to fa
    // is a bridge
    if(backEdgesUp[v] == 0 || v == 0){
        componentID[v] = ++currentID;
        dfsSpreadComponent(v, fa);
    }
}

//determines if a component has an odd cycle (i.e. is a not bipartite subgraph)
void dfsOddCycle(int v, int fa){
    visited[v] = true;
    for(int son : adj[v]){
        if(son == fa) continue;
        if(componentID[son] != componentID[v]) continue;
        //there is a back edge
        if(visited[son] && level[son] > level[v]){
            if( ((level[son]-level[v])&1) == 0){
                isOdd[componentID[v]] = true;
                return;
            }
        }
        else{
            dfsOddCycle(son, v);
        }
    }
}

void computeClosestOddNode(){
    //here the meaning of visited changes 
    // visited[v] = true if it had been enqued to the bfs. 
    fill(visited, visited + sizeReduced, 0);
    queue<pii> bfs; 
    loop(i, 0, sizeReduced){
        if(isOdd[i]){
            bfs.push(pii(i, 0));
            visited[i] = true;
        }
    }

    while(!bfs.empty()){
        int node = bfs.front().first;
        int distance = bfs.front().second;
        bfs.pop();

        distanceToOdd[node] = distance;
        for(int son : adjReduced[node]){
            if(!visited[son]){
                visited[son] = true;
                bfs.push(pii(son, distance + 1));
            }
        }
    }
}

//=================== LCA
//asumiento que los nodos van de 1 a n
// si van de 0 a n-1 cambia el create LCA Table en el for nd = 0; nd < n
//siempre asigna a la raiz como su propio padre
// y su nivel como 1 o 0 dependiendo de que te convenga

//en main agrega
//  assignParents(raiz, raiz);
// createLCATable();

struct nodo{
	int level = 0;
}nodes[maxN+1];
const int LogN = 19;
int table[LogN+1][maxN+1], minOddDistance[LogN+1][maxN+1];
void lcaDfs(int nd, int fa = -1){
    if(fa == -1) 
        fa = nd;
    for(int son: adjReduced[nd]){
        if(son != fa){
            nodes[son].level = 1 + nodes[nd].level;
            table[0][son] = nd;
            minOddDistance[0][son] = min(distanceToOdd[nd], distanceToOdd[son]);
            //aqui puedes aprovechar para agregar funcionalidad que ocupes para el
            //problema especifico
            lcaDfs(son, nd);
        }
    }
}

//creates LCA Binary Lifting table
void createLCATable(){
    int mid;
	for(int k = 1; k<=LogN; ++k){
		for(int nd = 0; nd < n; ++nd){
           mid = table[k-1][nd];
           table[k][nd] = table[k-1][mid];
           minOddDistance[k][nd] = min(minOddDistance[k-1][mid], minOddDistance[k-1][nd]);
        }
    }
}

//to get the k-th father of node i
int jump(int i, int k){
    int x=0;
	while(k > 0){
		if(k&1)
			i = table[x][i];
		++x;
		k>>=1;
	}
	return i;
}

int jumpMinDistance(int i, int k){
    int resp = distanceToOdd[i];
    int x=0;
	while(k > 0){
		if(k&1){
            resp = resp == -1? minOddDistance[x][i] : min(resp, minOddDistance[x][i]);
            i = table[x][i];
        }
		++x;
		k>>=1;
	}
	return resp;
}

int minOddDistancePath(int i, int j){
	//to put i and j in the same level
    int resp = distanceToOdd[i];
    if(nodes[i].level< nodes[j].level){
        resp = min(resp, jumpMinDistance(j, nodes[j].level-nodes[i].level));
        j = jump(j, nodes[j].level-nodes[i].level);
    }
    else{
        resp = min(resp, jumpMinDistance(i, nodes[i].level-nodes[j].level));
        i = jump(i, nodes[i].level-nodes[j].level);
    }

    //these happens if one of them was lca of them
    if(i==j)
        return resp;
        
	//these is to put both just below the LCA
    for(int d = LogN; d>=0; --d){
        if(table[d][i] != table[d][j]){
            resp = min(resp, min(minOddDistance[d][i], minOddDistance[d][j]));
            i = table[d][i];
            j = table[d][j];
        }
    }
    //they are both just below the LCA
    return min(resp, min(minOddDistance[0][i], minOddDistance[0][j]));
}
//===================  FIN LCA

ll solve(){
    cin>>n>>m;
    
    loop(i, 0, n){
        adjReduced[i].clear();
        adj[i].clear();
    }
    for(int i = 0, a, b; i < m; ++i){
        cin>>a>>b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    fill(visited, visited + n, 0);
    fill(componentID, componentID + n, -1);
    fill(backEdgesUp, backEdgesUp+n, 0);
    currentID = -1;
    level[0] = 0;
    //identifies bridges and identifies the maximal connected components 
    // using no bridges 
    // it also stores the edges of the reduced graph in adjReduced
    // a maximal component is a single node in the reduced graph
    dfsBackEdges(0, -1);
    sizeReduced = currentID + 1;
    fill(isOdd, isOdd + sizeReduced, false);
    fill(visited, visited + n, 0);
    loop(i, 0, n){
        if(!visited[i] && !isOdd[componentID[i]]){
            dfsOddCycle(i, 0);
        }   
    }
    bool atLeastOne = false;
    loop(i, 0, sizeReduced){
        if(isOdd[i]){
            atLeastOne = true;
            break;
        }
    }

    computeClosestOddNode();
    table[0][0] = 0;
    minOddDistance[0][0] = distanceToOdd[0];
    lcaDfs(0, 0);
    createLCATable();

    int q; cin>>q;
    ll sumResp = 0;
    for(int i = 0, a, b; i < q; ++i){
        cin>>a>>b;
        --a;--b;
        sumResp += atLeastOne? minOddDistancePath(componentID[a], componentID[b]) : -1;
    }
    return sumResp;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    for(int i = 1; i <= t; ++i){
        cout<<"Case #"<<i<<": "<<solve()<<"\n";
    }
    return 0;
}