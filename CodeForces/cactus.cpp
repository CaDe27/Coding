 /*
    como es un cactus
    podemos agrupar los ciclos en un vértice azul
    los vértices solitarios los pintamos de rojo 

    el grafo se convierte en un árbol de vértices rojos y azules

    sea cant[u] = cantidad de vertices azules desde u a la raiz 
    entonces el numero de caminos entre u y v es 
    pow(2, (cant[u] - cant[lca(u,v)]) + (cant[v] - cant[lca(u,v)]) 
    y esto se multiplica por 2 si el lca es azul

 */
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
#define invl(i,a,b) for(int i = a; i > b; --i)


const int maxN = 100005;
int n, m;

vi adj[maxN];
bool visited[maxN];
int level[maxN];
int cant[maxN];
bool enCiclo[maxN];
int papaCiclo[maxN];

const int LogN = 18;
int table[LogN+1][maxN+1];

// =========== Puentes 
/*  
    dp[u] = numero de back edges que van de un "hijo" de u a un "ancestro" de u
    puente entre a y b syss 
    dp[u] = 0

    calculo de dp[u] = Suma(dp[hijos]) - backedgesQueLLeganAU + backEdgedSalenU 
*/


void dfs(int f, int nd){
    visited[nd] = true;
    table[0][nd] = f;
    papaCiclo[nd] = nd;
    level[nd] = level[f] + 1;

    for(int son : adj[nd]){
        if(son != f)
        {
            //si eres back edge
            if(visited[son])
            {
                enCiclo[nd] = true;
                //si hacia arriba
                if(level[son] < level[nd])
                    papaCiclo[nd] = son;
            }
            //si eres front edje
            else
            {
                dfs(nd, son);
                if(enCiclo[son] && papaCiclo[son]!=son){
                    enCiclo[nd] = true;
                    papaCiclo[nd] = papaCiclo[son];
                }
            }
        }
    }
    
}

void asignaCant(int f, int nd){
    visited[nd] = true;
    cant[nd] = cant[f];
    if(enCiclo[nd] && papaCiclo[nd] == nd)
        ++cant[nd];
    for(int son : adj[nd])
        if(son != f && !visited[son])
            asignaCant(nd, son);
}

//=================== LCA
//asumiento que los nodos van de 1 a n
// si van de 0 a n-1 cambia el create LCA Table en el for nd = 1; nd < n
//siempre asigna a la raiz como su propio padre

//creates LCA Binary Lifting table
void createLCATable(){
    int mid;
	for(int k = 1; k<=LogN; ++k){
		for(int nd = 2; nd <= n; ++nd){
           mid = table[k-1][nd];
           table[k][nd] = table[k-1][mid];
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

int lca(int i, int j){
	//to put i and j in the same level
    if(level[i] < level[j])
        j = jump(j,level[j]-level[i]);
    else
        i = jump(i, -level[j]+level[i]);
    
    //these happens if one of them was lca of them
    if(i==j)
        return i;
        
	//these is to put both just below the LCA
    for(int d = LogN; d>=0; --d){
        if(table[d][i] != table[d][j]){
            i = table[d][i];
            j = table[d][j];
        }
    }
    //as they were just below the LCA, the LCA is the parent of either of the nodes
    return table[0][i];
}

//=============== Exponenciacion bianria
ll binPow(ll base, ll exp){
	ll r = 1;
	while (exp > 0){
		if(exp & 1)
			r = (r*base) % MOD;
		exp >>= 1;
		base = (base * base) % MOD;
	}
	return r%MOD;
} 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    loop(i, 0, m){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    

    //con esta dfs identificamos a los vértices azules como enCiclo[u] = true
    //y también identificamos con papaCiclo[u] el vertice que tiene menor nivel
    //de ese ciclo (el mismo vértice si no está en un ciclo)
    dfs(0, 1);

    //hacemos un nuevo recorrido en una dfs para asignar cant[u] 
    fill(visited, visited+maxN, 0);
    asignaCant(0, 1);
    
    //creamos la matriz para el LCA
    createLCATable();

    //loop(i, 1, n+1)
    //    cout<<i<<" "<<table[0][i]<<" "<<cant[i]<<" "<<enCiclo[i]<<endl;

    int k;
    cin>>k;
    loop(i, 0, k){
        int x,y;
        cin>>x>>y;
        int l = lca(x, y);
        //cout<<"query\n"<<"x: "<<x<<" "<<cant[x]<<"\ny: "<<y<<" "<<cant[y]<<"\nl: "<<l<<" "<<cant[l]<<endl;
        cout<<binPow(2, cant[x] + cant[y] - 2*cant[l] + (enCiclo[l]? 1:0) )<<"\n";
    }
    
}
