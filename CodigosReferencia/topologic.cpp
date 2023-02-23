
//Ordenamiento topologico lexicograficamente menor
//Disponible en : https://omegaup.com/arena/problem/Ordenamiento-topologico/#problems

//la idea es colocar cada al principio el nodo mas pequeno posible, en cada "iteracion"
//de manera que siempre ponemos primero al elemento mas pequeno posible y disponible

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 100000;

//voy[i] tiene a los nodos que puedo ir desde i
//cantPapas[i] tiene la catidad de nodos que pueden llegar a i
vector<int> voy[maxN];
int n;
int cantPapas[maxN];
priority_queue <int, vector<int>, greater<int> > raices;
int ordenamiento[maxN];
int total = 0; //total en el ordenamiento

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int m;
    cin>>n>>m;
    for(int i = 0; i < m; ++i){
        int j, k;
        cin>>j>>k;
        voy[j].push_back(k);
        ++cantPapas[k];
    }

    //si no hay nadie que llegue a ti eres una "raiz"
    //ya estas listo para entrar al ordenmiento y lo metemos al heap
    for(int i = n-1; i >= 0; --i)
        if(cantPapas[i] == 0)
        	raices.push(i);
    
    //vamos sacando el nodo mas pequeno, actualizamos la cantidad de papas de sus hijos
    //y si estos ya no tienen "papas" fuera del ordenamiento, los metemos al heap
    int menor;
    while(!raices.empty()){
        menor = raices.top(); raices.pop();
        ordenamiento[total++] = menor;
        for(int hijo:voy[menor]){
            --cantPapas[hijo];
            if(cantPapas[hijo] == 0)
                raices.push(hijo);
        }
    }
    
    //si al final no visitamos n fue porque hubo un ciclo
    if(total != n)
    	cout<<"-1\n";
    else{
        cout<<ordenamiento[0];
        for(int i = 1; i < n; ++i)
            cout<<" "<<ordenamiento[i];
        cout<<'\n';
    }
}