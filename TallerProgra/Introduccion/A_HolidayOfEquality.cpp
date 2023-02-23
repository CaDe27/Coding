/*
    Pensemos en cuánto va a tener cada persona despues de darles el dinero
    Como quiero dar lo menos posible, quiero que esta altura sea minima
    esta altura puede ser la de la persona con mas dinero

    no puede ser menos porque tendria que quitarle dinero a esta persona
    y si fuera mayor que esta, involucraría dar más dinero
    
    Reto: hazlo con memoria O(1), es decir, sin usar el arreglo
*/
#include <iostream>
 
using namespace std;
 
int main(){
    
    int n;
    cin>>n;
 
    int welfare[n], maxWelfare;
    maxWelfare = 0;
    for(int i = 0; i < n; i++){
        cin>>welfare[i];
        maxWelfare = max(maxWelfare, welfare[i]);
    }

    //calculamos la cantidad de monedas que debemos dar
    int monedas, totalQueDoy = 0;
    for(int i = 0; i < n; ++i){
        monedas = maxWelfare - welfare[i];
        totalQueDoy += monedas;
    }

    cout<<totalQueDoy<<"\n";
 
    return 0;
}