#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> pll;
const int maxN = 1e6+5; //equivale a 10^6 + 5
ll altura[maxN];
ll areaMax;

//solución a destruyendo edificios con la idea de encontrar 
// encontrar cuantos me extiendo a la izquierda y cuantos a la derecha con la observación de 
// que si me extiendo a ti hacia la izquierda, entonces me extiendo a todos a los que 
// tu ya te extendiste

// stack del tipo <altura del edificio, cuánto se extiende el edificio a la izquierda>
stack<pll> s; 

// está función calcula cuánto se extiene un edificio a la izquierda
// y aprovecha para contestar la altura derecha
void agrega(ll h){
    //como guarda cuántos se extiende la altura h a la izquierda
    int como = 0; 

    //mientras sea menor al del tope, me extiendo a todos los que él, y los agrego a como
    while(!s.empty() && h <= s.top().first ){
        como += s.top().second + 1;

        //observación importante: lo que yo me he extendido hasta ahora a la izquierda
        // es TODO lo que tú te extiendes
        //así que aquí mismo calculo el área del rectángulo que tiene altura s.top().first
        areaMax = max(areaMax, s.top().first*como);

        //como ya nadie choca esa altura, la quito de la pila
        s.pop();
    }
    //meto a la pila la altura h con su extensión total hacia la izquierda
    s.push(pll(h, como));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll altura;
    areaMax = 0;
    for(int i = 0; i < n; ++i){
        cin>>altura;
        //agrego la altura a la pila
        agrega(altura);
    }
    //agrego un edificio que sque a todos los que quedaron pendientes
    agrega(0);

    cout<<areaMax<<"\n";

}