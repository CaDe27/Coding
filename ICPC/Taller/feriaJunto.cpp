#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
  
    int ini[n], fin[n], sigJuego[n];
    short boletos[n];

    pii inicios[n], finales[n];
    //leo los juegos
    for(int i = 0; i < n; ++i){
        cin>>ini[i]>>fin[i]>>boletos[i];

        inicios[i] = pii(ini[i], i);
        finales[i] = pii(fin[i], i);
    }

    sort(inicios, inicios+n);
    sort(finales, finales+n);

   //precalculo para ver el primer juego que empieza despues de ti
    int itI, itF;
    itI = itF = 0;
    //si estan ordenados por como acaban, entonces podemos hacer un barrido
    // para saber cual es el indice en inicios del siguiente juego
    while(itF < n){
        while(itI < n && inicios[itI].first < finales[itF].first)
            ++itI;
        sigJuego[ finales[itF].second ] = itI;
        ++itF;
    }

    //DP

    fin[n] = 0;
    for(int i = n-1; i >= 0; --i)
        fin[i] = max( ((int)boletos[inicios[i].second]) + fin[sigJuego[ inicios[i].second ]], fin[i+1] );
    cout<<fin[0]<<"\n";

    return 0;

}
