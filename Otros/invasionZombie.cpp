//busqueda binaria sobre los segundos s
//el total infectados es
//lo que me expando - lo que sale por cada lado + lo que sale por las "esquinas" (que quito doble)
// O(binaria * calculo de lo que afecto) 
//O( (log n) * (O(1)) ) = O(log n)

#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;
typedef int64_t ll;

int n; //tamanio de la matriz
int x, y; // posicion de la bacteria (lo asumo como en el plano cartesiano)

//calcula cuantos cuadritos infecto en s segundos
ll infecto(ll s);

//calcula cuantos cuadritos de mi expansion se salen por un lado
ll sale1(ll a);

//calcula cuantos cuadritos de mi expansion salen por dos lados 
ll sale2(ll a, ll b);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll objetivo;    
    cin>>n>>x>>y>>objetivo;

    int inf = 0, sup  = n, mitad;
    while(inf != sup){
        mitad = (inf + sup)/2;
        ll infectados = infecto(mitad);
        if(infectados < objetivo) 
            inf = mitad + 1;
        else
            sup = mitad;
    }
    cout<<inf<<endl;

}

ll infecto(ll s){
    ll total;
    total = s*s + (s+1)*(s+1);
    //quito lo que se sale por cada lado
    total -= sale1( s - (n-x)); //der
    total -= sale1( s - (x-1)); //izq
    total -= sale1( s - (y-1)); //abajo
    total -= sale1( s - (n-y)); //arriba

    //sumo lo que se sale por las esquinas (lo quite doble)
    total += sale2( s - (n-x), s - (y-1)); //der abajo
    total += sale2( s - (n-x), s - (n-y)); //der arriba
    total += sale2( s - (x-1), s - (y-1)); //izq abajo
    total += sale2( s - (x-1), s - (n-y)); //izq arriba
    return total;
}

ll sale1(ll a){
    if (a <= 0)
        return 0;
    else
        return a*a;
}

ll sale2(ll a, ll b){
    if(a <= 0 || b<=0)
        return 0;
    else
        return a*b - b*(b+1)/2;
}