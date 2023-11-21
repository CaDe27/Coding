#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

typedef pair<int, int> pii;
void eliminaIntermedias(vector<int> &height , vector<int> &izq, vector<int> &der){
    int n = height.size(), indxMax;
    int mayorIzq[n], mayorDer[n];
    mayorIzq[0] = -1;
    for(int i = 1; i < n; ++i){
        mayorIzq[i] = max(mayorIzq[i-1], height[i-1]);  
    }

    mayorDer[n-1] = -1;
    for(int i = n-2; i >= 0; --i){
        mayorDer[i] = max(mayorDer[i+1], height[i+1]);
    }

    for(int i = 0; i < n; ++i){
        //si mayor al mayor a su derecha, nos sirve para los del lado derecho
        if(height[i] > mayorDer[i])
            der.push_back(i);
        if(height[i] > mayorIzq[i])
            izq.push_back(i);
    }
}  

int main(){
    //leer 
    int n; cin>>n;
    vector<int> height(n), izq, der;

    for(int i = 0; i < n; ++i){
        cin>>height[i];
    }
    
    //eliminar las lineas que tienen un mayor igual de cada lado
    eliminaIntermedias(height, izq, der);

    // por cada linea de la izq, encontrar la linea en la derecha 
    // mayor o igual a ella
    int resp = 0; 
    int indxDer = der.size() - 1;
    for(int i = 0; i < izq.size(); ++i){
        while(indxDer >= 0 && height[der[indxDer]] < height[izq[i]]){
            --indxDer;
        }
        if(indxDer == -1)
            break;
        
        resp = max(resp, height[izq[i]]*(der[indxDer] - izq[i]));
    }

    int indxIzq = 0;
    for(int i = der.size()-1; i>=0; --i){
        while(indxIzq < izq.size() && height[izq[indxIzq]] < height[der[i]]){
            ++indxIzq;
        }
        if(indxIzq == izq.size())
            break;
        resp = max(resp, height[der[i]]*(der[i]-izq[indxIzq]));
    }

    cout<<resp<<"\n";
    return 0;
}