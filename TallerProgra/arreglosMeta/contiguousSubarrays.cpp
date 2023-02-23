#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX_VALUE = 1000000000;
void aumentaArreglosIzq(vector<int> &arreglo, vector<int> &resp){
    //tiene una pareja que representa (valor, indice)
    stack<pair<int, int> > info;
    info.push(make_pair(MAX_VALUE + 1, -1));
    int indicePrimeroALaIzqMasGrande;
    for(int i = 0; i < arreglo.size(); ++i){
        //borrar los del tope de la pila mas pequeños
        while(info.top().first <= arreglo[i]){
            info.pop();
        }
        //inserta a la pila
        //guardar la resp
        indicePrimeroALaIzqMasGrande = info.top().second;
        resp[i] += i - indicePrimeroALaIzqMasGrande - 1;
        info.push(make_pair(arreglo[i], i));
    }
}

void aumentaArreglosDer(vector<int> &arreglo, vector<int> &resp){
    //tiene una pareja que representa (valor, indice)
    stack<pair<int, int> > info;
    info.push(make_pair(MAX_VALUE + 1, arreglo.size()));
    int indicePrimeroALaDerMasGrande;
    for(int i = arreglo.size()-1; i >= 0; --i){
        //borrar los del tope de la pila mas pequeños
        while(info.top().first <= arreglo[i]){
            info.pop();
        }
        //inserta a la pila
        //guardar la resp
        indicePrimeroALaDerMasGrande = info.top().second;
        resp[i] += indicePrimeroALaDerMasGrande - i - 1;
        info.push(make_pair(arreglo[i], i));
    }
}


vector<int> subArreglosContiguos(vector<int> &arreglo){
    int n = arreglo.size();
    vector<int> resp(n, 1);
    //calcular los de la Izquierda  
    aumentaArreglosIzq(arreglo, resp);
    //calcular los de la derecha
    aumentaArreglosDer(arreglo, resp);
    return resp;
}

int main(){
    i
    int arre[8] = {7, 6, 8, 5, 7, 6, 7, 20};
    vector<int> a(arre, arre+8);
    vector<int> resp = subArreglosContiguos(a);
    for(int v : resp){
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}