#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef pair<int,int> pii;
const int maxN = 1000005;
int n;

struct juego{
    int id, ini, fin, boletos;
}juegos[maxN];

pii inicios[maxN], finales[maxN];

//para el precalculo
int sigJuego[maxN];
void precalculo(){
    //precalculo para ver el primer juego que empieza despues de ti
    int itI, itF;
    itI = itF = 0;
    //si estan ordenados por como acaban, entonces podemos hacer un barrido
    // para saber cual es el indice en inicios del siguiente juego
    while(itF < n){
        while(itI < n && inicios[itI].first < finales[itF].first){
            ++itI;
        }
        int id = finales[itF].second;
        sigJuego[id] = itI;
        ++itF;
    }
}

//para la DP

int dp[maxN];
//DP(i) devuelve el maximo de boletos que puedes obtener desde la posicion i
// iterando sobre inicios
void llenaDP(){
    dp[n] = 0;
    for(int i = n-1; i >= 0; --i){
        int id = inicios[i].second;
        int siguiente = sigJuego[ id ];
        dp[i] = max(juegos[id].boletos + dp[siguiente], dp[i+1] );
    }
}

int main(){
    /*time_t start, end; 
    time(&start);  */

    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
  
    
    
    //leo los juegos
    for(int i = 0; i < n; ++i){
        cin>>juegos[i].ini>>juegos[i].fin>>juegos[i].boletos;
        juegos[i].id = i;

        inicios[i] = pii(juegos[i].ini, juegos[i].id);
        finales[i] = pii(juegos[i].fin, juegos[i].id);
    }

    sort(inicios, inicios+n);
    sort(finales, finales+n);
    
    precalculo();
    
    llenaDP();

    cout<<dp[0]<<"\n";

    /*
    // Recording end time. 
    time(&end); 
  
    // Calculating total time taken by the program. 
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5); 
    cout << " sec \n"; 
    */
    return 0;

}
