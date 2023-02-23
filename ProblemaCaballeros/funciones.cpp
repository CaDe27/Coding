#include <iostream>
#include <vector>
#include <map>
using namespace std;

//jugadores tiene la lista de indices de jugadores
//sizeJ tiene el tamanio de jugadores
//ini el indice "real" donde inicia el juego 
// k el parametro del juego
int juego(int n, int k){
    int restantes = n;
    bool vivo[n];
    fill(vivo, vivo+n, 1);
    int it = 0, cont = 0;
    while(restantes != 1){
        if(vivo[it] == 1){
            ++cont;
            if(cont == k){
                vivo[it] = 0;
                cont = 0;
                --restantes;
            }
        }
        ++it;
        if(it == n) it = 0; 
    }
    for(int i = 0; i < n; ++i)
        if(vivo[i])
            return i+1;
} 

int main(){
    int ganador, ganadorPasado;
    int k = 3;
    map<int, int> bucket;
    int d;
    for(int cantJugadores = 1; cantJugadores<= 1000; ++cantJugadores ){
        ganador = juego(cantJugadores, k);
        //cout<<cantJugadores<<" "<<(3*cantJugadores)-ganador <<endl;
        d = k*cantJugadores - ganador;
        if(bucket.find(d) == bucket.end()){
            bucket[d] = 1;
        }
        else
            ++bucket[d];
    }
    for(auto p : bucket){
        cout<<p.first<<" "<<p.second<<"\n";
    }
    return 0;
}