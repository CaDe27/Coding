//hacemos busqueda binaria sobre la cantidad maxima de camiones
// para probar si puedes hacer que k camiones te mande, solo hay que hacer un reccorido sobre el arreglo
// sobre cada posible k-tupla de campos consecutivos

// debes demostrar que el mejor lugar para tomar una k tupla es entre los dos campos centrales o en el campo 
//central esto lo puedes hacer con una desigualdad, viendo lo que aporta por parejas los más lejanos de cada 
//lado si tienes dos, cualquier lugar entre ellos conviene
// si tienes 4, lo que te aportan el mas a la izq y el mas a la der es minimo la distancia entre ellos
// y si estas fuera de ellos la distancia entre ellos mas otra cosa
// entonces lo pones entre ellos, y luego te fijas en cuanto aportan el segundo mas a la derecha
// y el segundo mas a la izquierda en conjunto, igual es minimo la distancia entre ellos

// con esos dos datos ya tenemos una solucion O(r log(r)) y es suficiente
#include <iostream>
#include <algorithm>
using namespace std;

typedef int64_t ll;

const int maxR = (int)1e5;
int campos[maxR], r;
ll b;



//funcion que calcula si se puede que k campos te manden arroz
bool sePuede(int k){
    int pt, izq, der;
    ll costoDer = 0, costoIzq = 0, mini;
    
    pt = (k-1)/2;
    izq = pt;
    der = (k-1) - pt;

    for(int i = 0; i < pt; ++i)
        costoIzq += campos[pt] - campos[i];
    
    for(int i = pt+1; i < k; ++i)
        costoDer += campos[i] - campos[pt];
    
    mini = costoDer + costoIzq;
    for(; pt + der < r-1; ++pt){
        costoIzq += (izq+1)*(campos[pt+1]-campos[pt]);
        costoIzq -= campos[pt+1] - campos[pt-izq];
        costoDer -= der*(campos[pt+1]-campos[pt]);
        costoDer += campos[pt+der+1] - campos[pt+1];
        if(costoDer + costoIzq < mini)
            mini = costoDer + costoIzq;
    }
    return mini <= b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int aux;
    cin>>r>>aux>>b;
    for(int i = 0; i < r; ++i)
        cin>>campos[i];
    
    int inf = 1, sup = r, mitad;
    //busqueda binaria sobre el max de camiones que t epueden mandar
    while(inf != sup){
        mitad = (inf + sup)/2 +1;
        if(sePuede(mitad))
            inf = mitad;
        else
            sup = mitad - 1;
    }
    cout<<inf<<'\n';
}

