/*
    hacemos bin sobre el tamanio de la escalera
    para saber si puede llegar hacemos un ¿backtracking?
    el recorrido es tarda n asi que la complejidad es nlogn
*/

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;

#define MINF -1000000000000
#define MOD 

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)


const int maxN =55,  maxM = 55;
int n, m, r, c;
char mat[maxN][maxM];
bool visited[maxN][maxM];

bool backTrack(int x, int y, int l){
    visited[x][y] = 1;

    if(x == n-1)
        return true;
    
    bool band = false;
    int i;

    //para los hijos hacia abajo
    i = 1;
    while(!band && i <= l){
        if( x+i < n && mat[x+i][y] == 'X' && !visited[x+i][y])
            band = backTrack(x+i, y, l);
        ++i;
    }
    
    //para los hijos hacia arriba
    i = 1;
    while(!band && i <= l){
        if( x-i >= 0 && mat[x-i][y] == 'X' && !visited[x-i][y])
            band = backTrack(x-i, y, l);
        ++i;
    }
    
    //para los hijos hacia la der
    i = 1;
    while(!band && y+i<m && mat[x][y+i]=='X'){
        if(!visited[x][y+i])
            band = backTrack(x, y+i, l);
        ++i;
    }
    
    //para los hijos hacia la izq
    i = 1;
    while(!band && y-i>=0 && mat[x][y-i]=='X'){
        if(!visited[x][y-i])
            band = backTrack(x, y-i, l);
        ++i;
    }
    return band;
}

int bin(int ini, int fin){
    int mitad;
    
    while(ini!=fin){
        
        loop(i, 0, n)
            fill(visited[i], visited[i]+m, 0);
        mitad = (ini+fin)/2;
        if(backTrack(r, c, mitad))
            fin = mitad;
        else
            ini = mitad + 1;
    }

    return ini;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>r>>c;
    --r; --c;

    loop(i,0,n)
    loop(j,0,m)
        cin>>mat[i][j];

    cout<<bin(0, n-r)<<'\n';
    return 0;
}