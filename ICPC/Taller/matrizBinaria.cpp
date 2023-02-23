/*
    nos conviente que toda la primera columna este llena de 1's
    porque si hay un 0, al cambiar ese renglon obtenemos una mas optima

    con operacion renglon hacemos todos 1,
    y vamos checando las columnas restantes para ver si hacemos o no operacion

    pudimos haber hecho primero operaciones sobre los renglones que empiezan con 1 y luego 
    hacer operacion columna, y nuevamente checar las columnas restantes, pero tiene el mismo efecto

    notemos que si en una columna (no la primera)
    despues de volver la primera columna a 1's con operaciones renglones 
    quedan m 1's y n 0's
    
    con el otro metodo de volver la primera columna a 1's quedan 
    en esa columna m 0's y n 1's,

    al final, la operacion columna puede decidir con cual de los dos estados quedarte

*/

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

typedef int64_t ll;

//lo que podemos demostrar es esto
// si en un momento tienes las monedas a1, a2, ... , ak y puedes gastar 
// 1, 2, ..., b
// y te dan una moneda con valor menor o igual a 1+2+...+b , sea de valor m,
// entonces puedes gastar hasta 1+2+...+b+m 

int main(){
    ll n, m;
    cin>>n>>m;
    
    //contabiliza cant de 1's y 0's en columna
    ll bucket[2][m];
    fill(bucket[0], bucket[0]+m, 0);
    fill(bucket[1], bucket[1]+m, 0);

    bool a, x; 
    for(int i = 0; i < n; ++i){
        cin>>a;
        for(int j = m-2; j >= 0; --j){
            
            cin>>x;
            if(a)
                ++bucket[x][j];
            else
                ++bucket[!x][j];
        }
    }

    ll resp = n*( (ll)(pow(2, m-1)) );
    for(int i = 0; i <= m-2; ++i)
        resp  +=  max(bucket[1][i], bucket[0][i])*( (ll)(pow(2, i)) );

    cout<<resp<<"\n";
    return 0;
}