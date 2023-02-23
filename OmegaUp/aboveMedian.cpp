#include <iostream>
#include <cstdint>
#include <algorithm>
using namespace std;
typedef int64_t ll;
const int maxN = 100000;
int n;

int cubeta[maxN+1];
int query(int pos){
    int total = 0;
    while(pos > 0){
        total+=cubeta[pos];
        pos -= pos&-pos;
    }
    return total;
}

void update(int pos, int valor){
    while(pos <= n){
        cubeta[pos]+= valor;
        pos += pos&-pos;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt","r")) freopen("case.txt","r",stdin);
    long x;
    cin>>n>>x;

    ll total = 0;
    long aux, mini, arre[n+1];
    arre[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin>>aux;
        arre[i] = arre[i-1] + (aux >= x? 1: -1);
        if(arre[i] >= 0) ++total; //para el contar el caso de si cuenta el de todos hasta i
        mini = min(mini, arre[i]); //para modificar el arreglo de manera que todos sean positivos
    }
    mini = -1*mini +1;
    for(int i = 1; i <= n; ++i)
        arre[i] += mini;

    update(arre[1], 1); 
    for(int i = 2; i <= n; ++i){
        total += query(arre[i]);
        update(arre[i], 1);
    }
    cout<<total<<'\n';
    
}






