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
#include <set>
#include <iomanip>

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxW = 8;
int w,h,t;

int porArreglar;
char matriz[maxW][maxW];
int bucket[27];
map<char, map<int, int> >activosFilas, activosColumnas; 
map<char, map<int, bool> > fijoFila, fijoColumna;
bool borrados[maxW][maxW];
int borradosCaso, limiteBorra;

pii dir [4] = {pii(0, 1), pii(1, 0), pii(-1, 0), pii(0, -1)};
bool noPuedoBorrarme(int f, int c){
    int x, y;
    loop(i, 0, 4){
        x = f + dir[i].first;  y = c + dir[i].second; 
        if(x >= 0 && x< w && y>=0 && y < h && borrados[x][y])
            return true;
    }
    return false;
}
// letra, fila, columna 
bool backTrack(char x, int f, int c){
    //cout<<x<<" "<<f<<" "<<c<<endl;
    if(f == w){
        if(x < 'Z')
            return backTrack(x+1, 0, 0);
        else 
            return porArreglar > 0;
    }

    if(borradosCaso == limiteBorra && porArreglar>0)
        return false;

    //si esta celda no es de esta letra me voy a la siguiente
    if(matriz[f][c] != x){
        if(c < h-1)
            return backTrack(x, f, c+1);
        else
            return backTrack(x, f+1, 0);   
    }

    //sí hay letras activas en esta fila
    
    //borro o no borro
    //borro
    if(!noPuedoBorrarme(f, c)){
        ++borradosCaso;
        borrados[f][c] = true;
        --activosColumnas[x][c];
        --activosFilas[x][f];
        if(activosColumnas[x][c] == 1)
            --porArreglar;
        if(activosFilas[x][f] == 1)
            --porArreglar;
        if(porArreglar == 0)
            return true;

        //procedo al back track
        //si funciona, return true
        if(c < h-1){
            if(backTrack(x, f, c+1)) return true;
        }
        else{
            if(backTrack(x, f+1, 0)) return true;
        }

        //deshago los cambios
        if(activosColumnas[x][c] == 1)
            ++porArreglar;
        if(activosFilas[x][f] == 1)
            ++porArreglar;
        ++activosColumnas[x][c];
        ++activosFilas[x][f];
        borrados[f][c] = false;
        --borradosCaso;   
    }
    //si ya hay otro en fila o col que no borre2 y no puedo borrarme 
    else if(fijoFila[x][f] || fijoColumna[x][c])
        return false;

    //no la borro
    if(fijoFila[x][f]== false && fijoColumna[x][c] == false){
        fijoColumna[x][c] = true;
        fijoFila[x][f] = true;
        if(c < h-1){
            if(backTrack(x, f, c+1)) return true;
        }
        else{ 
            if(backTrack(x, f+1, 0)) return true;
        }
        //deshago los cambios
        fijoColumna[x][c] = false;
        fijoFila[x][f] = false;
    }
    //si no se pudo en ningun caso
    return false;
}


bool sePuede(){
    char x;
    loop(i, 0, w)
        fill(borrados[i], borrados[i] + h, 0);
    activosColumnas.clear();
    activosFilas.clear();
    

    loop(i, 0, w){
    loop(j, 0, h){
        x = matriz[i][j];
        ++activosColumnas[x][j];
        ++activosFilas[x][i];
    }
    }
    porArreglar = 0;
    for(x = 'A'; x <= 'Z'; ++x){
        loop(i, 0, w){
            fijoFila[x][i] = 0;
            if(activosFilas[x][i] > 1)
                ++porArreglar;
        }
        loop(i, 0, h){
            fijoColumna[x][i] = 0;
            if(activosColumnas[x][i] > 1)
                ++porArreglar;
        }
    }
    if(porArreglar == 0)
        return true;
    borradosCaso = 0;
    return backTrack('A', 0, 0);
}

void lee(){
    char x;
    cin>>h>>w>>t;
    
    loop(i, 0, w){
    loop(j, 0, h){
        cin>>x;
        matriz[i][j] = x;
        ++activosColumnas[x][j];
        ++activosFilas[x][i];
        ++bucket[x-'A'];
    }
    }
}

void solve(){
    lee();
    
    //cota inferior
    int borroCols, borroFilas;
    char x;
    int ini = 0, mitad, fin = (w*h+1)/2;
    while(ini != fin){
        mitad = (ini+fin)/2;
        limiteBorra = mitad;
        //cout<<"entro con "<<mitad<<endl;
        if(sePuede()){
            //cout<<"se puede con "<<mitad<<"\n";
            fin = mitad;
        }
        else{
            //cout<<"no se puede con "<<mitad<<"\n";
            ini = mitad + 1;
        }
        
    }
    cout<<ini<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
