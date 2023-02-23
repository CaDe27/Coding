#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MIN_VALUE =-1;
void extiendeIzq(vector<int> &arreglo, vector<int> &resp){
    //tiene una pareja que representa (valor, indice)
    stack<pair<int, int> > info;
    info.push(make_pair(MIN_VALUE, -1));
    int indicePrimeroALaIzqMasGrande;
    for(int i = 0; i < arreglo.size(); ++i){
        //borrar los del tope de la pila mas pequeños
        while(info.top().first >= arreglo[i]){
            info.pop();
        }
        //inserta a la pila
        //guardar la resp
        indicePrimeroALaIzqMasGrande = info.top().second;
        resp[i] += i - indicePrimeroALaIzqMasGrande - 1;
        info.push(make_pair(arreglo[i], i));
    }
}

void extiendeDer(vector<int> &arreglo, vector<int> &resp){
    //tiene una pareja que representa (valor, indice)
    stack<pair<int, int> > info;
    info.push(make_pair(MIN_VALUE, arreglo.size()));
    int indicePrimeroALaDerMasGrande;
    for(int i = arreglo.size()-1; i >= 0; --i){
        //borrar los del tope de la pila mas pequeños
        while(info.top().first >= arreglo[i]){
            info.pop();
        }
        //inserta a la pila
        //guardar la resp
        indicePrimeroALaDerMasGrande = info.top().second;
        resp[i] += indicePrimeroALaDerMasGrande - i - 1;
        info.push(make_pair(arreglo[i], i));
    }
}


int64_t areaMaxima(vector<int> &arreglo){
    int n = arreglo.size();
    vector<int> extiendoTotal(n, 1);
    //calcular los de la Izquierda  
    extiendeIzq(arreglo, extiendoTotal);
    //calcular los de la derecha

    extiendeDer(arreglo, extiendoTotal);
    int64_t areaMax = 0, area;

    for(int i =0; i <n; ++i){
        area = ((int64_t)arreglo[i])*extiendoTotal[i];
        areaMax = max(area, areaMax);
    }
    return areaMax;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> edificios(n);
    for(int i = 0, a; i < n; ++i){
        cin>>a;
        edificios[i] =a;
    }
    cout<<areaMaxima(edificios)<<"\n";
    return 0;
}