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
#include <sstream>

using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100 +5, maxA = 2*1e5 + 5;
int n, A;
pii p[maxN];
int dp[maxN][maxN][maxN];
bool visited[maxN][maxN][maxN];
map<int, int> alturasIndx;
map<int, int> indxAlturas;
set<int> alturas;

//cuantos rectangulos necesito para cubrir los puntos entre 
//indxIni e indxFin que tienen altura mayor a la dada
int DP(int indxIni, int indxFin, int indxAltura){
    if(indxIni > indxFin)
        return 0;

    else if(indxIni == indxFin)
        return p[indxIni].second <= indxAlturas[indxAltura]? 0:1;

    if(!visited[indxIni][indxFin][indxAltura]){
        visited[indxIni][indxFin][indxAltura] = true;

        //si ya estoy cubierto, no hay necesidad de procesarme
        if(p[indxIni].second <= indxAlturas[indxAltura])
            return dp[indxIni][indxFin][indxAltura] = DP(indxIni+1,indxFin,indxAltura);
        
        //entonces desde ahora asumo que no estoy cubierto
        //inicializo como si solo cubriera a este edificio
        dp[indxIni][indxFin][indxAltura] = 1 + DP(indxIni+1, indxFin, indxAltura);

        //intento terminar en cada uno de los demas
        //it va a ser el indice del punto donde termine el rectanculo
        int it = indxIni + 1, ancho, nAltura, indxNAltura;       
        while(it <= indxFin){
            ancho = p[it].first - p[indxIni].first;
            nAltura = A / ancho;
            nAltura = *( --alturas.upper_bound(nAltura) );
            indxNAltura = alturasIndx[nAltura];
            if(nAltura < p[indxIni].second)
                break;
            dp[indxIni][indxFin][indxAltura] = min(dp[indxIni][indxFin][indxAltura], 1+DP(indxIni,it,indxNAltura) + DP(it+1,indxFin,indxAltura));
            ++it;
        }
    }
    return dp[indxIni][indxFin][indxAltura];
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>A;
    pii aux[n];
    loop(i, 0, n){ 
        cin>>aux[i].first>>aux[i].second;
    }
    sort(aux, aux+n);

    //dejo solo los puntos que no tienen ninguno arriba 
    int nuevaN = 0;
    alturas.insert(0);
    alturas.insert(maxA+1);
    loop(i, 0, n){
        if(i == n-1 || aux[i].first != aux[i+1].first){
            p[nuevaN++] = pii(aux[i]);
            alturas.insert(aux[i].second);
        }
    }

    int i = 0; 
    for(int altura : alturas){
        alturasIndx[altura] = i;
        indxAlturas[i] = altura;
        ++i;
    }

    n = nuevaN;
    cout<<DP(0, n-1, 0)<<endl;

    return 0;
}
