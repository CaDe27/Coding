
//Repechaje ICPC Latinoamerica 2019
//Problema K, Disponible en : https://www.juezguapa.com/problemas/enunciado/keep-branches-ordered

//la idea es colocar cada uno del [n, ..., 1] tan pronto posible al final
//de manera que los números mas pequenos [1, ..., n] esten mas a la izquierda posible

//vamos colocando al antes del ultimo colocado al numero mas grande que ya no tiene "hijos" pendientes
//es decir, todos a los que puede ir ya estan en el orden topologico

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 100;

//vengo[i] tiene los nodos j que pueden llegar a i
//cantHijos[i] tiene la cantidad de nodos a los que se puede ir desde i
vector<int> vengo[maxN+1];
int n;
int cantHijos[maxN+1]; 
priority_queue <int> hojas;
int ordenamiento[maxN+1];
int total;  //total en el ordenamiento

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j){
		int aux;
		cin>>aux;
		if(aux){
			vengo[j].push_back(i);
        	++cantHijos[i];
		}
    }

    //meto a todos los que no tienen hijos al heap
    for(int i = 1; i <= n; ++i)
        if(cantHijos[i] == 0)
        	hojas.push(i);
    
    //vamos metiendo a los mas grandes al ordenamiento, actualizamos el numero de hijos de sus papas
    //y metemos al heap a los que solo tenian como hijo a ese que sacamos
    total = n+1;
    int mayor;
    while(!hojas.empty()){
        mayor = hojas.top(); hojas.pop();
        ordenamiento[--total] = mayor;
        for(int papa:vengo[mayor]){
            --cantHijos[papa];
            if(cantHijos[papa] == 0)
                hojas.push(papa);
        }
    }
    //si no se llego a total = 1, fue porque habia un ciclo
    //notemos que si hay un ciclo, ninguno de los nodos en el entrara al heap
    //porque siempre tienen hijos
    if(total != 1)
    	cout<<"-1\n";
    else{
        int renombramiento[n+1];
        for(int i = 1 ; i <= n; ++i)
            renombramiento[ordenamiento[i]] = i;
        
        cout<<renombramiento[1];
        for(int i = 2; i <= n; ++i)
            cout<<" "<<renombramiento[i];
        cout<<'\n';
    }
}

