#include<iostream>
using namespace std;

int main(){
    int k, p; 
    cin>>k>>p;
    
    int prod[p];
    for(int i = 0; i < p; ++i){
        cin>>prod[i];
    }

    int maxk = 5e4 + 100 + 1;
    bool generados[maxk];
    fill(generados, generados + maxk, false);

    for(int i = 0; i < p; ++i){
        generados[ prod[i] ] = true;
    }

    for(int z = 1; z < maxk; ++z){
        for(int i = 0; i < p; ++i){
            if(z>=prod[i] && generados[ z - prod[i] ]){
                generados[z] = true;
            }
        }    
    }

    int n;
    for(int i = 0; i < k; ++i){
        cin>>n;
        int residuo = 0;
        while( ! generados[n + residuo] )
            ++residuo;
        cout<<residuo<<"\n";
    }

    return 0;
}