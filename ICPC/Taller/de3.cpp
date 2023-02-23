#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef int64_t ll;
const int maxN = 1e6+5; //equivale a 10^6 + 5
int altura[maxN];
int indxIzq[maxN];
int indxDer[maxN];


//stack del tipo <indice> 
stack<int> s; 
int extremo;
//función que regresa el índice izquierdo de mi edificio  (o derecho)
int agrega(int indx){    

    //si eres mas grande que yo, nadie choca contigo, 
    //sólo pueden chocar conmigo y te quito de la pila
    while(!s.empty() && altura[indx] <= altura[s.top()] ){
        s.pop();
    }

    //genro mi respuesta antes de meter a la pila
    int indxChoco;
    //y está vacía, no choco con nadie y el indx es el extremo
    if(s.empty())
        indxChoco = extremo;
    //si no está vacía, choqué con el del tope
    else
        indxChoco = s.top();

    s.push(indx);
    return indxChoco;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>altura[i];
    
    //calculo el indice izquierdo de cada uno
    //si no choco con nadie, mi extremo es -1
    extremo = -1;
    for(int i = 0; i < n; ++i)
        indxIzq[i] = agrega(i);

    while(!s.empty())
        s.pop();

    //ahora calculo el índice derecho de cada uno
    // si ahora no choco con nadie, mi extremo es n
    extremo = n;
    for(int i = n-1; i >= 0; --i)
        indxDer[i] = agrega(i);
    
    //calculo el area del rectangulo de cada altura/edificio y
    // guardo el máximo
    // (inicio areaMax con un mínimo adecuado) en este caso 0 está bien
    ll areaMax = 0;
    for(int i = 0; i < n; ++i){
        ll area = ((ll)altura[i])* ((ll)(indxDer[i]-1 - indxIzq[i]));
        areaMax = max(areaMax, area);
    }

    cout<<areaMax<<"\n";
}