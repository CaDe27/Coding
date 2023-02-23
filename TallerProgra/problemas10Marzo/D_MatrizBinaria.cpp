/*
    nota que si haces una cantidad par de operaciones sobre un renglon
    es equivalente a no haber hecho ninguna
    y hacer una cantidad impar, es equivalente a hacer una

    asi solo hay que considerar una operacion o ninguna
    ademas, nos conviene que toda la primera columna este llena de unos

    por lo que aplicaremos operaciones renglon para cambiar las filas que tengan
    un cero en la primera columna

    despues de eso veremos columna a columna buscar tener la mayor cantidad de unos
    prendidos

    otra forma de tener la primera columna con puros unos es primro aplicar
    la operacion columna a esta, y luego volver a aplicar el mismo proceso
    pero esto es equivalente al caso uno

*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef int64_t ll;

int main(){
    int n, m;
    cin>>n>>m;
    int matriz[n][m];
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
        cin>>matriz[i][j];
    }

    //checo cada fila y si no tiene uno, le aplico operacion 
    for(int i = 0; i < n; ++i){
        if(matriz[i][0] == 0){
            for(int j = 0; j < m; ++j)
                matriz[i][j] = (matriz[i][j] + 1)%2;
        }   
    }

    int cantUnos;
    ll resp = 0;
    //para cada columna restante checo la maxima cantidad de unos que puedo tener en ella
    //y voy generando el numero
    for(int j = 0; j < m; ++j){
        cantUnos = 0;
        for(int i = 0; i < n; ++i)
            if(matriz[i][j] == 1)   
                ++cantUnos;
        cantUnos = max(cantUnos, n - cantUnos);
        resp = resp*2 + cantUnos;
    }  
    cout<<resp<<"\n";
    return 0;
}