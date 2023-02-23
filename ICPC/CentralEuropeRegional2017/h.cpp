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

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef pair<pii, int> piii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 100005;

struct file{
    string name;
    ll memo;
    
};

struct dir{
    string nombre;
    ll memo;
    int subDirs;
    bool subDirMayorT;
    dir(){nombre = ""; memo = 0; subDirs = 0; subDirMayorT = false;}
};

bool operator < (const file &a, const file &b){return a.name < b.name;}

vector<file> files;
vector<dir> impresora;

int n, t;

//indxFile - archivo que estoy analizando en este momento
//indxImp  - indice actual vacio en el que puedo imprimir lo siguiente
int indxFiles, indxImp;

//dirName  - nombre del directorio actual
//s        - tamanio de dirName
// la funcion procesa todo lo que esta adentro de un directorio
// manda a procesar a sus hijos, de modo que actualiza 
//
//regreso indxFiles y indxImp para llevar un control de hasta donde he leido hasta el momento

void procesaDir(string dirName, int s){
    ll myIndxImp = indxImp++;
    impresora.push_back( dir() );
    impresora[myIndxImp].nombre = dirName;

    while(indxFiles < n){
        //checamos que este file esta dentro del directorio
        if(files[indxFiles].name.find(dirName) != 0)
            break;
        
        //checamos si es file o directory
        int aux = files[indxFiles].name.find("/", s+1);

        //si es file ya no hay "/" despues del nombre del dir
        if(aux == -1){
            impresora[myIndxImp].memo += files[indxFiles].memo;
            ++indxFiles;
        }
        //si sigue un subdir
        else{
            int indxSubDir = indxImp;

            //termina en la posicion aux, entonces tiene tamanio aux+1
            procesaDir( files[indxFiles].name.substr(0, aux+1), aux+1);
            
            //actualizo mi memoria y mi contencion de subDir >= a t
            impresora[myIndxImp].memo += impresora[indxSubDir].memo;
            if(impresora[indxSubDir].memo >= t)
                impresora[myIndxImp].subDirMayorT = true;
        }
    }

    //actualizo el total de subdirs dentro de mi
    impresora[myIndxImp].subDirs = (indxImp-1) - myIndxImp;
}

void imprime(int t){
    //asigno simbolo 
    //imprimo nombre y memoria
    //si el simbolo es +, adelanto para que no se impriman mis subdirs
    loop(i, 0, indxImp){
        string simbolo = impresora[i].subDirs ==0? " " : impresora[i].subDirMayorT? "-": "+";
        cout<<simbolo<<" "<<impresora[i].nombre<<" "<<impresora[i].memo<<"\n";
        if(simbolo=="+")
            i += impresora[i].subDirs;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin>>n;
    files.resize(n);

    loop(i, 0, n)
        cin>>files[i].name>>files[i].memo;
    
    cin>>t;

    sort(files.begin(), files.end());
    indxFiles = 0;
    indxImp = 0;
    procesaDir("/", 1);
    
    
    imprime(t);

    return 0;
}
