#include <iostream>
#include <algorithm>
using namespace std;

#define loop(i, a, b) for(int i = a; i < b; ++i)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k, p;
    cin>>k>>p;

    int bolsas[p];
    int maxN = 50000+101;
    bool sePuede[maxN];
    fill(sePuede, sePuede + maxN, 0);

    //leo las bolsas y marco su cantidad como que puede alcanzarse
    loop(i, 0, p){
        cin>>bolsas[i];
        sePuede[ bolsas[i] ] = true;
    }
    
    //marcamos todas las cantidades validas que pueden pedirnos
    loop(i, 1, maxN){
        //esta cantidad es valida si quitando una bolsa unitaria 
        //tenemos una cantidad ya valida 
        loop(j, 0, p){
            if(bolsas[j] < i && sePuede[ i - bolsas[j] ])
                sePuede[i] = true;
        }
    }
    
    //guardamos el minimo desperdicio para cada una
    int sigSePuede = maxN;
    int desperdicio[maxN];
    for(int i = maxN-1; i >= 1; --i){
        if(sePuede[i])
            sigSePuede = i;
        desperdicio[i] = sigSePuede - i;
    }

    int query;
    loop(i, 0, k){
        cin>>query;
        cout<<desperdicio[query]<<"\n";
    }
}