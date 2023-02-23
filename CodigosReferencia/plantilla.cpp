//estas son librerias
//no las necesito todas pero es comun tener un header con todas las que posiblemente uses
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>

#define MINF -1000000000000
#define MOD 1000000007


using namespace std;

//int llega como hasta 10^9, si siente que van a usar numeros mas grandes que eso, pueden usar ll
typedef int64_t ll;

//si quieren declarar un arreglo antes del main, (esto sirve para usarlo en las otras funciones sin tener  
// que mandarlo como paramatro (como los atributos de la clase en java))
// tienen que declararlo usando variables constantes para su dimension

//en este ejemplo estoy creand un arreglo de 100005 numeros
// los indices van de 0 a 100005-1 = 100004
// si no tuviera const, la declaracion del arreglo marcaria error
const int maxN = 100005;
ll arre[maxN];


int main(){
    //siempre usen esta linea en progra competitiva SIEMPRE!
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    //voy a hacer un programa que lea un numero n, y luego lea n numeros
    //e imprime la suma de esos numeros
    // n va hasta 100000
    // y los numeros van de 0 a 100000
    // si se fijan, en el peor de los casos todas las entradas van a tener 10^5
    // y eso daria una suma de 10^5 * 10^5 = 10^10, que no cabe en un int
    //por eso voy a usar ll

    //no necesitan un arreglo pero lo usare para que se familiaricen

    int n;
    cin>>n; //sirve para leer la n 

    //este es un for como el que ya conocian
    for(int i = 0; i < n; ++i){
        //leo el numero y lo meto directamente al arreglo, no tienes que usar un auxiliar
        cin>>arre[i];
    }

    //calculo la suma
    //insisto en que para esto no necesitas un arreglo
    ll suma = 0;

    for(int i = 0; i < n; ++i)
        suma += arre[i];
    //esta linea equivale a suma = suma + arre[i];
    // puedes hacer lo mismo con *=,  /=, -=
    
    //cout siver para imprimir, '\n' sirve para imprimir un salto de linea
    cout<<suma<<'\n';
}