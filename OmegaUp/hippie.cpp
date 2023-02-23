#include <iostream>
#include <algorithm>

#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
const int maxN = 60000;
int izq, der, collar[maxN+2];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int c, n, mini;
    cin>>c>>n;

    loop(i, 0, n)
        cin>>collar[i];

    //duplicamos el arreglo
    loop(i, n, 2*n)
        collar[i] = collar[i-n];

    int suma = 0; //suma entre las las c cuentas
    //encontramos el primer cero
    izq = 0;
    while(collar[izq] != 0)
        ++izq;
    
    //encontramos el c-esimo cero
    int cont = c-1;
    der = izq;
    while(cont > 0){
        ++der;
        if(collar[der]==0)
            --cont;
        else
            suma+=collar[der];
    }

    mini = suma;
    //recorremos todo el arreglo con izq
    while(izq < n){
        //actualiza el derecho
        ++izq;
        while(izq < n && collar[izq] != 0){
            suma-=collar[izq];
            ++izq;
        }
        if(izq == n)
            break;
        
        //actualizamos el derecho
        ++der;
        while(collar[der] != 0){
            suma += collar[der];
            ++der;
        }
        mini = min(mini, suma);
    }

    cout<<mini<<'\n';

}

