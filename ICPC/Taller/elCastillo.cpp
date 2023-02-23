/*
    plan:
        por cada celda:
            si no visitada: visita toda su cuarto
            papa = next_indx
    
    
    //total de cuartos = next_indx;
    //recorremos arreglo para ver el que tiene el mas grande

    por cada celda
    //vemos con quien se puede unir y guardamos el maximo
    

*/


#include <iostream>
#include <stack>
#include <queue>
#include <set>

using namespace std;
typedef pair<int,int> pii;
typedef pair<pii, char> piic;
typedef pair<pii, int> piii;

//variables utiles para el problema
const int maxR = 55, maxC = 55;
int mat[maxR][maxC];
int id[maxR][maxC];
int tamanioId[maxR*maxC];
int r, c;

//utiles para la busqueda
bool visitado[maxR][maxC];
int currId;

//funcion que visita toda la recamara de un modulo
void visita(int x, int y){

    queue<pii> pila;
    pila.push( pii(x, y) );

    int i, j;
    while(!pila.empty()){
        i = pila.front().first; 
        j = pila.front().second;
        pila.pop();

        if(visitado[i][j]) continue;
        
        //actualizamos informacion sobre el nodo y su Id
        visitado[i][j] = true;
        id[i][j] = currId;
        ++tamanioId[currId];

        int valor = mat[i][j];

        //deje la idea de Rodrigo
        //si el bit no esta prendido, no hay pared y te meto a la pila
        if( !(valor & 8) )
            pila.push(pii(i+1, j));

        if( !(valor & 4) )
            pila.push(pii(i, j+1));
        
        if( !(valor & 2) )
            pila.push(pii(i-1, j));
        
        if( !(valor & 1) )
            pila.push(pii(i, j-1));
        
    }
}

bool somosVecinos(int i, int j, int i2, int j2){
    return id[i][j] == id[i2][j2];
}

int tamanioUnion(int i, int j, int i2, int j2){
    return tamanioId[ id[i][j] ] + tamanioId[ id[i2][j2] ];
}

int valida(int i2, int j2){
    return 1<=i2 && i2<=r && 1<=j2 && j2<=c;
}

int main(){
    cin>>r>>c;
    
    //leo a matriz
    for(int i = 1; i <= r; ++i)
    for(int j = 1; j <= c; ++j){
        cin>>mat[i][j];
    }

    //visito cada cuarto
    currId = 0;
    for(int i = 1; i <= r; ++i)
    for(int j = 1; j <= c; ++j){
        if(!visitado[i][j]){
            ++currId;
            visita(i, j);
        }
    }
    
    //imprimimos el total de cuartos
    cout<<currId<<" ";

    //vemos que recamara tiene mas cuartos
    int maxTamanio = 0;
    for(int i = 1; i <= currId; ++i)
        maxTamanio = max(maxTamanio, tamanioId[i]);
    cout<<maxTamanio<<"\n";

    //vemos que union es mejor
    int unionMaxi = 0;
    char dir;
    int x, y;
    for(int i = 1; i <= r; ++i)
    for(int j = 1; j <= c; ++j){
        
        vector<piic> vecinos;
        vecinos.push_back( piic( pii(i-1, j), 'N'));
        vecinos.push_back( piic( pii(i, j-1), 'O'));
        vecinos.push_back( piic( pii(i+1, j), 'S'));
        vecinos.push_back( piic( pii(i, j+1), 'E'));

        int miID = id[i][j];
        for(piic v : vecinos){
            int i2 = v.first.first, j2 = v.first.second;
            char c2 = v.second;

            if(valida(i2, j2) && !somosVecinos(i,j, i2,j2) && unionMaxi < tamanioUnion(i,j, i2,j2)){
                unionMaxi = tamanioUnion(i,j, i2,j2);
                dir = c2;
                x = i; y = j;
            }
        }
    }
    cout<<x<<" "<<y<<" "<<dir<<"\n";

    return 0;
}