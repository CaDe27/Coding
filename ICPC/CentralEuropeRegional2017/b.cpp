/*
    Hacemos el proceso al reves porque es mas facil dividir secciones que unirlas
    procesamos la division final con un sweep line 
    al final, del ultimo granjero al primero, imprimimos la respuesta del granjero
            y sumamos los buffalos al area a la que estaban antes de que llegara este 
            granjero
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
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 3*1e5 + 5;

int farmer[maxN], mergeTo[maxN], father[maxN];

//para hacer mas legible el manejo de los eventos 
// los buffalos y los granjetos
struct p{
    int x, y, arrival;
};

bool operator < (const p &a, const p &b){ 
    if(a.y == b.y)
        return a.x > b.x;
    else 
        return a.y > b.y;
}

//para encontrar el merge adecuado
//dentro de todos mis "papas de merge", el primero
//que llego antes que yo
int fatherMerge(int u, int v){
    if(u > v)
        return v;
    else
        return mergeTo[v]=fatherMerge(u, mergeTo[v]);

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<p> events;
    p aux;
    
    //los buffalos tendran arrival -1 como bandera 
    int n; cin>>n;
    aux.arrival = -1;
    loop(i, 0, n){
        cin>>aux.x>>aux.y;
        events.push_back(aux);
    }

    //leemos a los granjeros
    int m; cin>>m;
    loop(i, 0, m){
        cin>>aux.x>>aux.y;
        aux.arrival = i+1;
        events.push_back(aux);
    }

    events.push_back(aux);

    //ordenamos los eventos para hacer el sweep line 
    sort(events.begin(), events.end());

    //el pair es del tipo <x, arrival> para el set de farmers activos
    set<pii> activos;

    //insertamos un granjero que llega antes que todos
    activos.insert(pii(1e9+1, 0));

    //procesamos los eventos
    for(p e : events){ 
        auto it = activos.upper_bound(pii(e.x, e.arrival));
        
        //eres un buffalo
        if(e.arrival == -1)
            ++farmer[ it -> second ]; 
        // eres granjero
        // ves a quien te mergeas y eliminas a los que llegaron despues y menores en x
        // hasta topar con uno que llego antes
        else{

            mergeTo[ e.arrival ] = it -> second;

            //elimino a los menores
            vector<pii> eliminar;
            while(it != activos.begin()){
                --it;
                if(it->second < e.arrival)
                    break;
                eliminar.push_back(*it);
            }
            for(pii elimino : eliminar)
                activos.erase(elimino);

            //agrego al granjeto
            activos.insert(pii(e.x, e.arrival));
        }
    }

    
    //obtenemos la respuestas de cada granjero del final hacia adelante
    int resp[maxN];
    invli(i, m, 1){
        resp[i] = farmer[i];
        mergeTo[i] = fatherMerge(i, mergeTo[i]);
        farmer[ mergeTo[i] ] += farmer[i];
    }

    //imprimimos la respuesta
    loopi(i, 1, m)
        cout<<resp[i]<<"\n";
    return 0;
}
