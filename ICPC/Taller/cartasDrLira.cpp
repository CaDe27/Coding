#include <iostream>

//podemos checar ambas opciones e imprimir la que cambias
//menos cartas

//aveces es mejor checar todas las opciones que crear un algoritmo 
//complicado que intente descifrar cual es mejor de las dos sin checarlas


using namespace std;

int main(){
    
    int n;
    cin>>n;

    int totalB, totalW;
    char aux;
    totalB = 0;
    totalW = 0;

    for(int i = 0; i < n; i++){
        cin>>aux;
        if(aux == 'B'){
            if(i%2 == 0)
                ++totalW;
            else
                ++totalB;
            
        }
        if(aux == 'W'){
            if(i%2 == 0)
                ++totalB;
            else
                ++totalW;
        }
    }
    cout<<min(totalB, totalW)<<"\n";

    return 0;
}