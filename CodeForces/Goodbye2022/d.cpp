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
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 998244353

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 100005;
int n;
int a[maxN], b[maxN], degree[maxN];
bool visited[maxN];
set<int> adj[maxN];
set<int> repetidos;
stack<int> pila;


void dfs(int v){
    if(visited[v]) return;
    visited[v] = true;
    for(int x : adj[v])
        if(!visited[x])
            dfs(x);
}

void solve(){
    cin>>n;
    fill(visited, visited + n, 0);
    fill(degree, degree + n,  0);
    loop(i, 0, n) adj[i].clear();
    while(!pila.empty()) pila.pop();
    repetidos.clear();
    
    loop(i, 0, n){ cin>>a[i]; --a[i];}
    loop(i, 0, n){ cin>>b[i]; --b[i];}
    loop(i, 0, n){
        if(a[i] != b[i]){
            adj[a[i]].insert(b[i]);
            adj[b[i]].insert(a[i]);
            ++degree[a[i]];
            ++degree[b[i]];
        }
    }

    loop(i, 0, n){
        if(a[i] == b[i]){
            if(repetidos.find(a[i]) != repetidos.end()){
                cout<<"0\n";
                return;
            }
            else{
                repetidos.insert(a[i]);
            }
        }
    } 
    //todos los numeros conectados a un repetido, ya estan definidos 
    for(int v : repetidos){
        dfs(v);
    }
    
    //de los restantes, solo nos interesan los de grado menor a 2
    //al tener grado de todos al menos dos, todos tendran dos. 
    //asi nos encargamos de los de grado cero y uno
    //primero de los de grado uno, pues estos deben definir su lugar 

    // mantenemos actualizada la cantidad de indices en los que aparece un numero 
    //para nuevos numeros que ya solo tengan un lugar
    loop(i, 0, n){
        if(visited[i]) continue;
        if(degree[i]==1)
            pila.push(i);
    }

    //todos los numeros en la pila tienen degree 1 o 0
    // inician con 1, pero si el que está conectado al numero se procesa primero, 
    // puede procesarse cuando este ya no tenga a nadie
    while(!pila.empty()){
        int v = pila.top();
        pila.pop();
        if(visited[v]) continue;
        visited[v] = true;

        //si ya no hay lugar, GG
        if(degree[v] == 0) {
            cout<<"0\n";
            return;
        }

        //del que queda conectado, actualizamos su degree
        for(int vecino : adj[v]){
            if(visited[vecino]) continue;
            --degree[vecino];
            if(degree[vecino] == 1)
                pila.push(vecino);
        }
    }

    //si el acomodo es valido, solo deberian quedar nodos de degree 2
    loop(i, 0, n){
        if(!visited[i] && degree[i] != 2){
            cout<<"0\n";
            return;
        }
    }

    int tienenOpcion = 0;
    loop(i, 0, n){
        if(!visited[i]){
            ++tienenOpcion;
            dfs(i);
        }
    }

    ll respDobles = 1, respOpcion = 1;
    loop(i, 0, repetidos.size())
        respDobles = (respDobles*n)%MOD;
    loop(i, 0, tienenOpcion)
        respOpcion = (respOpcion*2)%MOD;
    ll resp = (respDobles*respOpcion)%MOD;
    cout<<resp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}