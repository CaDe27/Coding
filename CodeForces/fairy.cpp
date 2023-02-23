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
typedef pair<int, pair<int,int> > piii; 

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)

void swap(int &a, int &b){
	int aux;
	aux = a;
	a = b;
	b = aux;
}

const int maxN = 100005;
int n, m;

vi adj[maxN];
bool visited[maxN];
int level[maxN];
int buenas[maxN], malas[maxN], totalMalas;


void dfs(int f, int nd){
    visited[nd] = true;
    level[nd] = level[f] + 1;

    for(int son : adj[nd]){
        if(son == f) continue;  

        //es una frontEdge
        if(!visited[son])
        {
            dfs(nd, son);
            malas[nd] += malas[son];
            buenas[nd] += buenas[son];
        }
        //si eres backEdge
        else
        {
           //si es hacia arriba
            if(level[son] < level[nd])
            {
                //si tienen la misma paridad es mala 
                if( (level[nd] - level[son])%2 == 0){
                    ++malas[nd];
                    ++totalMalas;
                }
                //si no es buena
                else
                    ++buenas[nd];
            }
            //si es hacia abajo
            else{
                // lo mismo que arriba pero la resto
                if( (level[nd] - level[son])%2 == 0)
                    --malas[nd];
                else
                    --buenas[nd];
            } 
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    vii edges;
    loop(i, 0, m){
        int a, b;
        cin>>a>>b;
        edges.push_back(pii(a,b));

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    //con esta metemos a posibles las que no tengan backEdges
    // buenas que pasen por encima de ellas
    loop(i, 0, n)
        if(!visited[i])
            dfs(i, i);

    if(totalMalas == 0){
        cout<<m<<"\n";
        loopi(i, 1, m) 
            cout<<i<<" ";
        cout<<"\n";
        return 0;
    }
    
    int tot = 0;
    vi resp;
    int father, son;
    loop(i, 0, m){

        father = edges[i].first;
        son = edges[i].second;

        

        if(level[father] > level[son])
            swap(father, son);
        
        //cout<<father<<" "<<son<<" "<<malas[son]<<" "<<buenas[son]<<" "<<level[father]<<" "<<level[son]<<endl;
        //si es una  back edge y eres la unica mala
        if(level[son] != level[father]+ 1){
            if(totalMalas == 1 &&  (level[son]-level[father])%2 == 0)
            {
                ++tot;
                resp.push_back(i+1);
            }
        }
        //si eres front edge, cubres a todas las malas y a ninguna buena
        else if( malas[son] == totalMalas && buenas[son] == 0 ){
            ++tot;
            resp.push_back(i+1);
        }
    }

    cout<<tot<<"\n";
    if(tot > 0){
        loop(i, 0, tot)
            cout<<resp[i]<<" ";
        cout<<"\n";
    }
}
