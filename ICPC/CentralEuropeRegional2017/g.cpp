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
typedef long double ld;
typedef pair<ld, int> pldi;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define MINF -1000000000000
#define MOD(a,b) (a%b + b)%b

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 300005;
vector<int> adj[maxN];
ld active[maxN];
ld sumActive[maxN];
ld expectancy[maxN];
ld neighbors[maxN];
int n; int m;

/*
    observación clave: si tu esperanza es menor y tengo un boleto hacia ti, lo uso 

    sabemos que lo esperado si estás en N es gastar 0
    empezamos con N un conjunto de "activos"(de quienes ya conocemos
    la esperanza) y vamos expandiendo este conjunto hasta que 1 este en el


    lo que realmente llevamos es el registro del conjunto de nodos que están en la "frontera"
    de los activos (tienen un vecino activo) y en cada iteracion,
        sacamos el que tiene la "esperanza relativa a los activos" mas pequeña y decimos que 
        esa es su esperanza, per ahora hay que actualizar la "esperanza relativa a los activos" de los
        vecinos de este nodo

    la complejidad es mlog(n)

    porque se hace a lo mas una actualizacion por cada arista, y la actulizacion es de complejidad log(n)

    lo de la esperanza relativa a los activos se usa porque considero que mis vecinos no activos
    tienen una esperanza mayor a mi, aunque no sea el caso
    
    pero esta esperanza relativa a los activos coincide con la verdadera esperanza, si eres el que tiene menor
    esperanza ... entre los frontera

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>m;
    loop(i, 0, m){
        int a, b;
        cin>>a>>b;

        ++neighbors[a];
        ++neighbors[b];
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    set<pldi> border;
    border.insert( pldi(0, n) );

    while(expectancy[1] == 0){
        auto b = border.begin();
        int v = b -> second;
        ld exp = b -> first;
    
        expectancy[v] = exp;

        //lo elimino de los frontera y actualizo a todos sus vecinos
        border.erase(*b);
        
        for(int neighbor : adj[v]){
            if(expectancy[neighbor] > 0 || neighbor == n) continue;

            //si ya tiene vecinos activos
            //ya estaba en border, y te quito para actualizarte
            if(active[neighbor] > 0)
                border.erase(pldi( ((ld)(neighbors[neighbor] +sumActive[neighbor])) / active[neighbor], neighbor));
            
            //actualizo la inf del nodo
            ++active[neighbor];
            sumActive[neighbor] += exp;
            
            //lo meto de nuevo a los frontera
            border.insert( pldi( ((ld)(neighbors[neighbor] +sumActive[neighbor])) / active[neighbor], neighbor));
        }
    }

    cout<<setprecision(10)<<fixed<<expectancy[1]<<"\n";

}
