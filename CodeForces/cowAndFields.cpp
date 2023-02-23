/*
    BFS desde el inicio y el fin
    ordenar arreglo segun ai-bi
    recorrer el arreglo desde el final al inicio
        guardando la b max hasta ese momento
    regresar min(min camino sin puetes, camino encontrando)
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> pii;
const int maxN = 200005;
int n, m, k;

vector< pii > specials;
vector<int> adj[maxN];
int dn[maxN], special[maxN], dnMin;
bool visited[maxN];

void bfs(int i){
    queue<pii> c;
    c.push(pii(i,0));
    int nd, v;

    fill(visited, visited + n + 5, 0);
    while(!c.empty()){
        nd = c.front().first; v = c.front().second;
        c.pop();
        if(!visited[nd]){
            visited[nd] = true;
            
            // si eres el nodo n me interesa tu distancia minima a n
            if(i == 1 && nd == n)
                dnMin = v;

            //si eres especial, quiero guardar tu distancia
            if(special[nd] == 1){ 
                if(i == 1)
                    dn[nd] = v;
                else
                   specials.push_back(pii(dn[nd], v)); 
            }

            //meto a mis hijos con distancia mas uno
            for(int h: adj[nd])
                c.push(pii(h, v+1));
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    dnMin = 0;
    cin>>n>>m>>k;

    int aux;
    for(int i = 0 ; i < k; ++i){
        cin>>aux;
        special[aux] = 1;
    }
    
    int x,y;
    for(int i = 0; i < m; ++i){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bfs(1);
    bfs(n);

    //
    sort(specials.begin(), specials.end(), [&] (const pii x,const pii y){return x.first - x.second < y.first - y.second;});
    int bM = specials[k-1].second, maxi = 0;

    for(int i = k - 2; i >= 0; --i){
        maxi = max(maxi, specials[i].first + bM + 1);
        bM = max(bM, specials[i].second);
    }


    dnMin = min(dnMin, maxi);
    cout<<dnMin<<endl;

    return 0;
}