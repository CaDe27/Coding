#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
const int maxi = 100000;
int papa[maxi+1];
bool protegido[maxi+1];
vector<int> adjlist[maxi+1];
int64_t g;

//Repechaje ICPC Latinoamerica 2019
//Disponible en: https://www.juezguapa.com/problemas/enunciado/guarding-the-museum

// la observacion central es que, al ser un arbol, forzosamente tiene
//que haber un guardia en la hoja, o en el papa de la hoja
//pero como el papa siempre tiene mas conexiones que la hoja, conviene prender al papa
//cuando se van eliminando hojas, esto se generaliza y asi puede volverse a "prender"
//los papas de las nuevas hojas cada vez, hasta cubrir todo el arbol

//la funcion se basa en que si uno de los hijos no fue protegido despues de recorrer 
//a sus respectivos hijos, el unico que puede protegerlo, es poniendo a un guardia en su papa
//si no hay tal hijo, no se pone un guardia en si
int recorre(int v){
    int solicitudes = 0;
    for(int hijo : adjlist[v]){
        if(hijo != papa[v]){
            papa[hijo] = v;
            solicitudes += recorre(hijo);
        }
    }
    if(solicitudes > 0){
        ++g;
        protegido[v] = true;
        protegido[papa[v]] = true;
    }
    //como la raiz no tiene papa, verificamos aqui si si fue protegido o no al final
    //del proceso
    if(v == 1 && !protegido[v])
       ++g;
    return protegido[v]? 0:1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    g = 0;
    int n;
    int64_t c;
    cin>>n>>c;

    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    recorre(1);
    cout<<g*c<<'\n';
}