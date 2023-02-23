#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

#define entra 1
#define sale 0
using namespace std;

typedef int64_t ll;
typedef pair<ll,int> pii;

#define loop(i, a, b) for(int i = a; i <b;++i)
/*
    Para cada celda solo es necesario saber la última vez que fue visitada
    Si deben visitarte, se debe convertir en borrador en un momento mayor o igual a tu ultima visita
    si no, se debe convertir en un momento menor a tu ultima visita

    hago un ¿sweep line? para cada dirección up, down, right, left
    
    Por ejemplo, para right
        para cada fila hago lo siguiente:
            para cada columna: proceso todos los intervalos que inician ahi, "activandolos"
            y "desactivo" los que terinan en esa columna/celda. 
            Despues checo de los activos cual es el mas grande y actualizo la ultima visita a esa celda

    para tomar en cuenta que se van incrementando los valores activos por cada celda que avanzo, 
    llevo un valor que le llamo offset
    asi, cuando saco el activo mas alto, solo debo sumarle offset, y esta la incremento uno a uno

    No a todos se les debe sumar lo mismo, depende de cuanto llevan activos, pero al momento de insertarlos los ajusto, 
    para que a todos deba sumarles lo mismo. Por eso inserto (valor - offset)
    Para que si es elegido ese valor en ese momento, sí valga valor, 
    si es elegido al siguiente, offset aumenta en uno y valor + offset ya es valor+1, y sucesivamente... 

    Despues recorro la matriz para actualizar la cota minima o maxima sgun la ultima visita a la celda e imprimo la respuesta

*/
int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int w, h, n;
    char c;

    cin>>h>>w>>n;
    int mat[h][w];
    vector<pii> up[h][w], down[h][w], lef[h][w], righ[h][w];
    ll last[h][w];
    loop(i, 0, h){
        loop(j, 0, w){
            last[i][j] = 0;
            cin>>c;
            mat[i][j] = c=='#'? 1 : 0;
        }
    }

    string p;
    ll tiempo = 1, duracion, offset;
    int fila= h-1, col = 0;
    loop(i, 0, n){
        cin>>p>>duracion;
        if(p == "up") {
            offset = h-1 - fila;
            up[fila][col].push_back(pii(tiempo - offset, entra));
            fila -= duracion;
            if(fila != 0) up[fila-1][col].push_back(pii(tiempo - offset, sale));   
        }
        else if(p == "down"){
            offset = fila;
            down[fila][col].push_back(pii(tiempo - offset, entra));
            fila += duracion;
            if(fila != h-1) down[fila+1][col].push_back(pii(tiempo - offset, sale));
        }
        else if(p == "left"){
            offset = w-1 - col;
            lef[fila][col].push_back(pii(tiempo - offset, entra));
            col -= duracion;
            if(col != 0) lef[fila][col-1].push_back(pii(tiempo - offset, sale));
        }
        else{
            offset = col;
            righ[fila][col].push_back(pii(tiempo - offset, entra));
            col += duracion;
            if(col != w-1) righ[fila][col+1].push_back(pii(tiempo - offset, sale));
           
        }
        tiempo += duracion;
    }

    ll cotaMin = 0, cotaMax = tiempo;
    multiset<ll> activos;

    //recorrido columnas down
    loop(j, 0, w){
        offset = 0;
        activos.clear();
        for(int i = 0; i < h; ++i){
            //proceso entradas y salidas
            for(pii q : down[i][j])
                if(q.second == entra)
                    activos.insert(q.first);
                else
                    activos.erase(activos.find(q.first));

            //actualizo cota
            if(activos.size() > 0)
                last[i][j] = max(last[i][j], *(--activos.end()) + offset);
            ++offset;
        }
    }
    
    //recorrido columnas up
    loop(j, 0, w){
        activos.clear();
        offset = 0;
        for(int i = h-1; i >= 0; --i){
            //proceso entradas y salidas
            for(pii q : up[i][j])
                if(q.second == entra)
                    activos.insert(q.first);
                else
                    activos.erase(activos.find(q.first));

            //actualizo cota
            if(activos.size() > 0)
                last[i][j] = max(last[i][j], *(--activos.end())+ offset);
            ++offset;
        }
    }
    //recorrido filas left
    loop(i, 0, h){
        activos.clear();
        offset = 0;
        for(int  j = w-1; j >= 0; --j){
            //proceso entradas y salidas
            for(pii q : lef[i][j])
                if(q.second == entra)
                    activos.insert(q.first);
                else
                    activos.erase(activos.find(q.first));

            //actualizo cota
            if(activos.size() > 0)
               last[i][j] = max(last[i][j], *(--activos.end())+ offset);
            ++offset;
        }
    }

    //recorrido filas rigth
    loop(i, 0, h){
        activos.clear();
        offset = 0;
        for(int  j = 0; j < w; ++j){
            //proceso entradas y salidas
            for(pii q : righ[i][j])
                if(q.second == entra)
                    activos.insert(q.first);
                else
                    activos.erase(activos.find(q.first));

            //actualizo cota
            if(activos.size() > 0)
                last[i][j] = max(last[i][j], *(--activos.end())+ offset);
            ++offset;
        }
    }

    //actualizo las cotas 
    loop(i, 0, h){
    loop(j, 0, w){
        if(mat[i][j] == 1){
            if(last[i][j] == 0) {cotaMax = -1;}
            else cotaMin = max(cotaMin, last[i][j]);
        }else{
            if(last[i][j] > 0) cotaMax = min(cotaMax, last[i][j]-1);
        }
    }
    }

    if(cotaMin <= cotaMax)
        cout<<cotaMin<<" "<<cotaMax<<"\n";
    else
        cout<<"-1 -1\n";
    
    return 0;
}