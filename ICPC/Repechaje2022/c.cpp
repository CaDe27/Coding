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
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;
int n, m;
int arre[maxN];
ll acum[maxN];

int maxMenorIgual(int cota){
    int ini = 0, fin = n-1, mitad;
    if(arre[0] > cota)  
        return -1;

    while(ini != fin){
        mitad = (ini + fin + 1)>>1;
        if(arre[mitad] <= cota)
            ini = mitad;
        else 
            fin = mitad - 1; 
    }
    return ini;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>m;
    loop(i, 0, n)
        cin>>arre[i];

    sort(arre, arre+n);

    loop(i, 0, n){
        acum[i] = arre[i];
        if(i > 0) acum[i] += acum[i-1];
    }

    ll cota, indx;
    ll suma;
    loop(i, 0, m){
        cin>>cota;
        indx= maxMenorIgual(cota);
        if(i == -1){
            suma = n*cota;
        }
        else{
            suma = acum[indx] + (n-indx-1)*cota;
        }
        cout<<suma<<"\n";
    }
    return 0;
}