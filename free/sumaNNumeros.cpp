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
int n, arre[maxN];
void solve(){
    //leemos la cantidad de numeros a leer
    cin>>n;

    //defino la suma como un entero de 64 bits en caso de que la suma 
    //no quepa en un int normal (32 bits ~ 2*10^9,  64 bits~ 4*10^18)
    // ll no existe, pero por el typedef int64_t ll, esto es lo mismo que
    //  int64_t suma = 0;
    ll suma = 0;
    int x;
    //por el #define loop de la linea 24, esto es lo mismo 
    //que for(int i = 0; i < n; ++i)
    loop(i, 0, n){
        //leemos el siguiente elemento
        // para leer varias cosas haces: cin>>var1>>var2>>var3>>var4;
        cin>>x;
        suma += x;
    }
    
    //imprimimos la suma de los n numeros y un salto de linea
    //para imprimir varias cosas haces cout<<var1<<var2<<var3;
    //aunque esto los imprime uno seguido del otro, cin espacios
    /// si quieres espacios puedes hacer cout<<var1<<" "<<var2<<" "<<var3;
    cout<<suma<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    // si son varios casos de entrada, usas int t; cin>>t; y resuelves cada caso
    // en solve()
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
