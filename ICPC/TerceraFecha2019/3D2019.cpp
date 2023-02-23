#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
// tercera fecha Gran Premio Mexico 2019
// problema diponible en https://www.urionlinejudge.com.br/judge/en/runs/code/15933991

// la solucion se basa en que cada subramificacion tiene una rama mas grande, de 
// modo que, como se quiere maximizar el numero de nodos cortados, las subramas 
// que no son la mas grande se pegan a la raiz, asi, si quieres tomar esas subramas
// se asegura que antes tomes la mas grande de entre ellas
// asi, al final, el unico nodo con ramificaciones es la raiz, se ordenan las
// ramas por su altura y asi la cant maxima que puedes quitar es las ramas mas
// grandes mas la raiz
// por ejemplo si tienes el arbol ...
//						1
//					2		3
//				4				5
//			6		7			
//		8
// y quieres tomar 2, el proceso hace que el nodo con 7 se suba a la raiz, se
// ordenan las ramas (rama del 2, rama del 3, rama del 7), se toman las primeras
// dos y se suma la raiz, dando que puedes quitar un maximo de 7 nodos del arbol
*/

/*
//level lleva va a guardar la altura desde el nodo a la hoja mas alejada (inclusive)
//adj la lista de adyacencia
*/
const int maxN = 100000;
int level[maxN+1];
vector<int> adj[maxN+1];

//h nodo hijo p nodo padre
void sube(int h, int p){ 
	//maxi va a guardar, de los hijos de h, el que tenga el nivel mayor
	int maxi = 0;
	
	//se encarga de que todos los hijos de h no tengan ramificaciones (entran a sube())
	//y se obtiene el maxi
	for (int v : adj[h]){
		if(v != p){
			sube(v, h);
			if(level[v] > level[maxi])
				maxi = v;
		}
	}
	
	//si no tienes hijos...
	if(maxi == 0)
		level[h] = 1;
	
	//si tienes hijos, sube a la raiz a los que no sean tu padre ni tu hijo maximo
	//y asigna el nivel de h
	else{
		for(int v : adj[h])
			if(v != maxi && v!=p)
				adj[1].push_back(v);
		level[h] = level[maxi] + 1;
	}
} 

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	//n el numero de nodos y k la cantidad de ramas que se cortan
	//vAux funciona como la lista del 1 antes de que se le aniadan las subramas
	int n, k;
	vector<int> vAux;
	cin>>n>>k;
	
	//construye el arbol
	int aux;
	for(int i = 2; i <= n; ++i){
		cin>>aux;
		adj[aux].push_back(i);
		adj[i].push_back(aux);
		if(aux == 1)
			vAux.push_back(i);
	}
	
	//se usa la funcion para cada hijo del 1 para subir todas las subramas no maximas a 1
	for(int v : vAux)
		sube(v, 1);
	
	//se ordena la lista de 1 de acuerdo con sus alturas
	sort(adj[1].begin(), adj[1].end(), [](int a , int b){return level[a]>level[b];} );
	
	//se toman las k alturas mas grandes y la raiz
	int resp = 0;
	for(int i = 0; i < k; ++i)
		resp+=level[(adj[1]).at(i)];
	resp+=1;
	
	cout<<resp<<"\n";
	return 0;
}
