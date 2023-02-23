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

const int maxR = 55, maxC = 55;
int mat[maxR][maxC];
int id[maxR][maxC];
int tamanioId[maxR*maxC];
int r, c;

bool visitado[maxR][maxC];
int currId;
void visita(int x, int y){
    //f
    stack<pii> pila;
    pila.push( pii(x, y) );

    int i, j;
    while(!pila.empty()){
        i = pila.top().first; 
        j = pila.top().second;
        pila.pop();

        if(visitado[i][j]) continue;
        
        visitado[i][j] = true;
        id[i][j] = currId;
        ++tamanioId[currId];

        int valor = mat[i][j];

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


int main(){
    cin>>r>>c;
    
    //leo a matriz
    for(int i = 1; i <= r; ++i)
    for(int j = 1; j <= c; ++j){
        cin>>mat[i][j];
    }

    currId = 0; //índice de la dfs
    for(int i = 1; i <= r; ++i)
    for(int j = 1; j <= c; ++j){
        if(!visitado[i][j]){
            ++currId;
            visita(i, j);
        }
    }



    
    //imprimimos el total de cuartos
    cout<<currId<<" ";

    int maxTamanio = 0;
    for(int i = 1; i <= currId; ++i)
        maxTamanio = max(maxTamanio, tamanioId[i]);
    cout<<maxTamanio<<"\n";

    int unionMaxi = 0;
    char dir;
    int x, y;
    for(int i = 1; i <= r; ++i)
    for(int j = 1; j <= c; ++j){
        int miID = id[i][j];
        //checamos N
        if(i > 1 && id[i-1][j]!= miID && unionMaxi < tamanioId[miID] + tamanioId[id[i-1][j]]){
            unionMaxi = tamanioId[miID] + tamanioId[id[i-1][j]];
            dir = 'N';
            x = i; y = j;
        }

        //checamos O
        if(j > 1 && id[i][j-1]!= miID && unionMaxi < tamanioId[miID] + tamanioId[id[i][j-1]]){
            unionMaxi = tamanioId[miID] + tamanioId[id[i][j-1]];
            dir = 'O';
            x = i; y = j;
        }

        //checamos S
        if(i < r && id[i+1][j]!= miID && unionMaxi < tamanioId[miID] + tamanioId[id[i+1][j]]){
            unionMaxi = tamanioId[miID] + tamanioId[id[i+1][j]];
            dir = 'S';
            x = i; y = j;
        }

        //checamos E
        if(j < c && id[i][j+1]!= miID && unionMaxi < tamanioId[miID] + tamanioId[id[i][j+1]]){
            unionMaxi = tamanioId[miID] + tamanioId[id[i][j+1]];
            dir = 'E';
            x = i; y = j;
        }
    }
    cout<<x<<" "<<y<<" "<<dir<<"\n";


    return 0;
}