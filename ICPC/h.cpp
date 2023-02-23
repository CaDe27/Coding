#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <queue>
#include<algorithm>
 
//Ponle coordenadas! 
// Checa que tiene que pasar para que te ganen coordenada a coordenada
// y solo manten los importantes, en este caso, que propiedades tienen estos
// activos
 
// Idea: despues de tener con Djikstra las distancias, ordenalo 
//       lexicograficamente (x,y,z)
// Ignora x, checa el plano 2D (y, z) y fijate en lo que tiene 
// que pasar en las coordenadas y, z
// para que no seas "peor" que otro
// Solo manten en el plano los importantes, los que te pueden ayudar
// a descartar otros puntos despues. Si ya alguien es "mejor" que tu
// ignorando a la coordenada x, entonces quitalo
// 
// de este modo, siempre mantienes algo como un "Hull " en escalera
//  al introducir el siguiente punto, solo debes buscar el punto con coordenada
// y menor o igual a ti, y checar si su z es mayor. Si es mayor, entonces cuentas
//  Nota que por esta "escalera", todos los y menores a este primero menor o igual a ti, 
// tienen su z mayor a el, asi que si no te gana este en z, no te gana ningun otro 
 
 
 
using namespace std;
 
typedef pair<int,int> pii;
 
#define loop(i,a,b) for(int i = a; i < b; ++i)
 
const int maxN = 1e5+5, maxE = 5e5 + 5;
int n;
 
int dist[maxN][3];
vector<pii> adj[maxN];
 
//para los djikstras
bool v[maxN];
priority_queue<pii, vector<pii>, greater<pii> > d;
 
typedef pair<int, pii> ip;
 
void djikstra(int o){
    fill(v, v+maxN, 0);
 
    d.push(pii(0, o));
 
    int act, cost;
    while(!d.empty()){
        cost = d.top().first; act =d.top().second;
        d.pop();
        
        if(v[act]) continue;
        
        v[act] = 1;
        dist[act][o] = cost;
        for(pii hijo : adj[act]){
            if(v[hijo.first]) continue;
            d.push( pii(cost + hijo.second, hijo.first));
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int e, a, b, w;
    cin>>n>>e;
    loop(i, 0, e){
        cin>>a>>b>>w;
        adj[a].push_back(pii(b, w));
        adj[b].push_back(pii(a, w));    
    }
    loop(i, 0, 3) djikstra(i);
 
    vector<ip> v;
    loop(i, 0, n) v.push_back(ip(dist[i][0], pii(dist[i][1], dist[i][2])));
    sort(v.begin(), v.end());
    
    map<int, int> m;
    map<int, int> :: iterator it;
    vector<int> elimina;
    bool cuento[n+5];
    fill(cuento, cuento + n + 5, 0);
    int x, y, z, resp;
 
    resp = 1;
    m.insert(v[0].second);
    cuento[0] = true;
 
    loop(i, 1, n){
        
        x = v[i].first;
        y = v[i].second.first;
        z = v[i].second.second;
 
        //checo el elemento con y menor o igual a mi 
        it = m.upper_bound(y); 
        if(it!=m.begin()) --it;
        
        //si soy igual a uno de los activos, cuento
        if(v[i-1] == v[i] && cuento[i-1]){
            cuento[i] = true;
            ++resp;
        }
        // o si mi y es menor o mi z es menor, si cuento
        else if(it->first > y || it->second > z){
            ++resp;
            cuento[i] = true;
 
            //ahora saco a los que les gano
            //los que tienen una Y mayor o igual y 
            //una z mayor o igual            
            if(it->first < y) ++it;
 
            while(it!=m.end() && it->second >= z){
                elimina.push_back(it->first);
                ++it;
            }
            for(int yp : elimina){m.erase(yp);}
            elimina.clear();
            
 
            //me inserto
            m.insert(pii(y, z));
        }
 
    }
    cout<<resp<<"\n";
 
    return 0;
 
}