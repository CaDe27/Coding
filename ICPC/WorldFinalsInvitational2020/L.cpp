/*
    Camino solucion:
    1. puedes usar MST de maximos
    2. si el arbol tiene raiz, te conviene visitar primero todo el subarbol de un
        nodo, antes que a el
    3. de todas las hojas, visito la que tiene arista con costo minimo
    4. considerar la arista de costo mínimo 
        es igual de optimo visitar primero todo un subarbol y luego el otro
        
        el max ancho en el que me como primero es mayor que el ancho por cuando paso
            por la arista de costo minimo 
            entonces me importa saber cual es el max ancho si caigo en el segundo 
            subarbol y si ya antes me habia comido todos los otros nodos
    5. ver que si sabes la respuesta de ambos subarboles, puedes calcular de todo el arbol
    6. como calcular estas respuestas? 
        para saber la de un subarbol, tendria que ver la arista minima de ese, y hacer lo mismo
        hasta llegar a subarboles con dos nodos, esta ultima division seria con una arista maxima

        entonces procesas de la arista de peso max a la min
        y vas uniendo subarboles y sus respuestas
`        
    
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
#include <iomanip>

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef pair<int, pii> edge;

#define MINF -1000000000000
#define MOD 1000000007

#define m(a,b) (a%b + b)%b
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)

const int maxN = 100005;
int n, m;
int c[maxN];
ll sumaCostos;


int repre[maxN];
ll respSubArbol[maxN], sumaSubArbol[maxN];

int repreMayor(int v){
    if(repre[v] == v)
        return v;
    else
        return repre[v] = repreMayor(repre[v]);
}

void unite(int a, int b, int ancho){
    a = repreMayor(a);
    b = repreMayor(b);

    ll respNuevoArbol, nuevaSuma;
    nuevaSuma = sumaSubArbol[a] + sumaSubArbol[b];

    ll respComoSubArbolBPrimero, respComoSubArbolAPrimero;
    respComoSubArbolBPrimero = min(respSubArbol[a], ancho - (sumaCostos - sumaSubArbol[a]));
    respComoSubArbolAPrimero = min(respSubArbol[b], ancho - (sumaCostos - sumaSubArbol[b]));
    respNuevoArbol = max(respComoSubArbolAPrimero, respComoSubArbolBPrimero);

    repre[a] = b;
    sumaSubArbol[a] = sumaSubArbol[b] = nuevaSuma;
    respSubArbol[a] = respSubArbol[b] = respNuevoArbol;
}

bool unidos(int a, int b){
    return repreMayor(a) == repreMayor(b);
}

ll solve(){
    cin>>n>>m;
    
    sumaCostos = 0;
    loop(i, 0, n){
        cin>>c[i];
        sumaSubArbol[i] = c[i];
        respSubArbol[i] = 1e9; 
        sumaCostos += c[i];
    }

    //uso kruskal para construir MST con costos maximos
    vector<edge> edges;
    edge aux;
    loop(i, 0, m){
        cin>>aux.second.first>>aux.second.second>>aux.first;
        --aux.second.first;
        --aux.second.second;
        edges.push_back(aux);
    }
    sort(edges.begin(), edges.end(), greater<edge>());

    int a, b;
    loop(i, 0, n)
        repre[i] = i;

    //uno los subarboles, calculando la respuesta del nuevo subarbol
    for(edge e : edges){
        a = e.second.first;
        b = e.second.second;
        if(!unidos(a, b)){
            unite(a, b, e.first);
        }
    }

    int rep = repreMayor(0);
    return respSubArbol[rep] <= 0? -1 : respSubArbol[rep];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cout<<solve()<<"\n";
    return 0; 
}
