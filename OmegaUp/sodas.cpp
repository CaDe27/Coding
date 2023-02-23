//Problema en: https://omegaup.com/arena/problem/Maquina-de-sodas#problems
//la idea es ver tanto el inicio como el fin de un rango como un evento
// ordenamos estos eventos y vamos actualizando el maximo de rangos que se traslapan

#include <iostream>
#include <algorithm>
#define endl '\n'
#define optimiza() ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
struct evento{
    int donde, valor;   
};

int main(){
    optimiza();
    int n; cin>>n;
    
    evento e[2*n];
    for(int i = 0; i < n; ++i){
        cin>>e[i].donde>>e[n+i].donde;
        e[i].valor = 1;
        e[n+i].valor = -1;   
    }
    sort(e, e+2*n, [](evento a, evento b){return a.donde < b.donde;} );

    int maxT = 0, traslapados = 0;
    for(int i = 0; i < 2*n; ++i){
        if(e[i].valor == 1){
            ++traslapados;
            if(traslapados > maxT) 
                maxT = traslapados;
        }
        else
            --traslapados;
    }

    cout<<maxT<<endl;
}