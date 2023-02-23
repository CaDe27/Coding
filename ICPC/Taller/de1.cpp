#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> pll;
const int maxN = 1e6+5; //equivale a 10^6 + 5
ll altura[maxN];
int indxIzq[maxN];
ll areaMax;

//solución a destruyendo edificios con la idea de encontrar 
//el primer índice izq y el primer índice derecho donde hay una altura menor


// stack del tipo <altura del edificio, índice del edificio>
stack<pll> s; 


//esta función agrega una altura a la pila
//contesto todas las preguntas de índice derecho mientras sean mayores que yo
// y al final siempre contesto mi índice izquierdo
void agrega(ll h, ll indx){

    //mientras mi altura sea menor o igual, ya nadie choca contigo
    // y además yo mismo soy el primer índice a la derecha al que te extiendes
    while(!s.empty() && h <= s.top().first ){
        ll h2 = s.top().first; 
        ll indx2 = s.top().second;

        //aquí mismo podemos calcular el área que delimita este edificio al que me extiendo
        //como ya está en la pila, ya antes calculé su índice izquierdo, y yo soy índice
        //derecho
        //el área del rectángulo máximo  es la que ya teníamos o el área que da este edificio
        areaMax = max(areaMax, h2 * (indx - indxIzq[indx2] - 1));
        
        //quito elemento de la pila
        s.pop();
    }

    // asigno mi indx izquierdo
    // si la pila está vacía, mi índice izquierdo es -1, sino es el del tope de la pila
    if(!s.empty())
        indxIzq[indx] = s.top().second;
    else
        indxIzq[indx] = -1;
    
    //meto el edificio a la pila
    s.push(pll(h, indx));
}




int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll altura;
    areaMax = 0;
    
    for(int i = 0; i < n; ++i){
        cin>>altura;
        //meto la altura y su índice a la pila
        agrega(altura, i);
    }
    //agrego un último edificio de altura cero para contestar la pregunta del índice derecho
    //de todos los que quedan 
    agrega(0, n);

    //imprimos el área máxima
    cout<<areaMax<<"\n";

}