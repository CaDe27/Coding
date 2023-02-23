/*
    hacemos dp sobre el arreglo ordenado
    la estado es pos i, y cuantos de los k he tomado
    contiene el grado minimo de injusticia desde ahi
    y la decisión es tomar o no tomar 
    esto da una complejidad de nlogn + n*k
    usamos n*k de memoria que son 8*10^7 = 80*10^6  si usamos int 64 y son 128*10^6 bytes disponibles y si cabe
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

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)


const int maxN = 3005;
int n, k;

ll arre[maxN];
ll memo[maxN][maxN];
bool visited[maxN][maxN];

ll dp(int i, int ks){
    if(i == n)
        return 0;

    else if(!visited[i][ks]){
        if( n-i == k - ks )
            memo[i][ks] = (n-k)*arre[i] + dp(i+1, ks+1);
        else if(ks == k)
            memo[i][ks] = k*arre[i] + dp(i+1, ks);
        else{
            visited[i][ks] = 1;
            //si lo tomo, sumo la diferencia con los i-1-ks y resto la diferencia
            // con los n-k - i-1-ks que faltan del otro lado
            //si no lo tomo, sumo la diferencia cn los ks que he tomado y resto la de los k - ks que no he tomado
            memo[i][ks] = min(arre[i]*(i-ks) -  arre[i]*(n-k - (i-ks) ) + dp(i+1, ks+1), 
                              arre[i]*(ks) -  arre[i]*(k-ks) + dp(i+1,ks));
        }

    }
    return memo[i][ks];
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    loop(i, 0, n)
        cin>>arre[i];

    sort(arre, arre+n);
    cout<<dp(0, 0)<<'\n';
}