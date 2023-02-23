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
#define INF (1e9*2000)  
 
const int maxN = 2005;
int n;
ll tiempo[maxN], costo[maxN];
 

bool visited[maxN][6005];
ll dp[maxN][6005];
//dp(i, t) lo que me minimo que cuesta robar a partir del artículo i
//         con t tiempo disponible
ll DP(int i, int t){
    //casos base
        //si llegue al final
        if(i == n)
            return t>=0? 0 : INF;
        
        // si puedo robar todos los que restan

        if(t >= n-(i-1))
            return 0;
    // si no te he visitado, te calculo
    if(!visited[i][t+2000] /*de alguna forma pregunto si ya te calculo/*/){
        visited[i][t+2000] = 1;
        //minimo entre pago o no pago este
         dp[i][t+2000] = min(costo[i] + DP(i+1, t+tiempo[i]), 0+DP(i+1, t-1) );
    }
    return dp[i][t+2000];
 
}
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>tiempo[i]>>costo[i];
    cout<<DP(0, 0)<<"\n";
}