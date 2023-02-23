#include <iostream>
#include <vector>

using namespace std;

const int maxNodos = 1e6;
vector< vector<int> > adj;
vector<int> camino;
int inicio, destino, cantNodos;
bool encontrado = false;
int *predecesorCamino;

void dfs(int nodo, int predecesor){
    //si soy el que buscan 
    if(nodo == destino){
        encontrado = true;
    }

    //si no soy, busco entre mis adyacentes
    int i = 0, sigNodo;
    while(!encontrado && i < adj[nodo].size()){
        sigNodo = adj[nodo][i++];
        if(sigNodo != predecesor)
            dfs(sigNodo, nodo);
    }

    if(encontrado)
        camino.push_back(nodo);
}


int main(){
    //leo la cantidad de nodos y de aristas
    int cantAristas; 
    cin>>cantNodos>>cantAristas;
    predecesorCamino = new int[cantNodos];
    adj.resize(cantNodos+1);
    
    for(int i = 0, a, b; i < cantAristas; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //leo los dos nodos entre los que quiero el camino
    cin>>inicio>>destino;

    //lanzo dfs desde el inicio 
    dfs(inicio, 0);

    //imprimir el camino al destino 
    reverse(camino.begin(), camino.end());
    for(int v : camino)
        cout<<v<<" ";
    cout<<"\n";

    return 0;
}