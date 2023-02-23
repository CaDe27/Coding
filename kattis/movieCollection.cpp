#include <iostream>
#include <algorithm>
#define loop(i, a, b) for(int i = a; i < b; ++i)
#define inverseLoop(i, a, b) for(int i = a; i > b; --i)
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);
#define readMyCase() if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin)
using namespace std;
const int maxN = 100000, maxR = 1000000;
int n, r;
int bit[maxN + maxR + 1];
int indx[maxN+1];

//Problema disponible: https://open.kattis.com/problems/moviecollection
//la idea es contar cuantos hay hacia abajo en lugar de hacia arriba
//como el total no cambia totalArriba = n-1 - totalAbajo
//contar abajo es muy facil con un BIT
// y para actualizar lo que hacemos es quitar el indice donde estaba del BIT, de modo que 
// proximas queries no aparezca en las sumas, y le asignamos una nueva posicion adelante de todos

void update(int pos, int x){
    while(pos <= n+r){
        bit[pos] += x;
        pos += pos&-pos;
    }

}

int  query(int pos){
    int suma = 0;
    while(pos > 0){
        suma += bit[pos];
        pos -= pos&-pos;
    }
    return suma;
}

void initializeIndex(){
    fill(bit, bit+n+r+2,0);
    inverseLoop(i, n, 0){
        indx[i] = n - i + 1;
        update(n-i+1, 1);
    }
}

int main(){
    optimize();
    readMyCase();

    int testCases; cin>>testCases;
    loop(t, 0, testCases){
        cin>>n>>r;

        initializeIndex();
        int movie, resp, lastIndx;
        loop(pos, n+1, n+r+1){
            cin>>movie;
            //we look its last appereance
            lastIndx = indx[movie];
            //we look how many movies are below it
            resp = n-1 - query(lastIndx - 1);
            //we update its index in index array and in BIT
            indx[movie] = pos;
            update(pos, 1);
            update(lastIndx, -1);
            cout<<resp<<" ";
        }
        cout<<endl;
    }
    return 0;
}
