
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

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)


const int maxN = 1000000;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, arre[maxN+1];
    int k;
    cin>>n>>k;
    
    fill(arre, arre+maxN+1, 0);
    int aux, maxC = 0;
    loop(i, 0, n){
        cin>>aux;
        ++arre[aux];
        maxC = max(maxC, aux);
    }


    int cuantos, maxi, izq, cIzq, de;
    ll extra;
    cIzq = cuantos = maxi = arre[0];
    extra = izq = de = 0;

    for(ll i = 1; i <=maxC; ++i){
        extra += cuantos;
        cuantos += arre[i];

        while(extra - (i-izq)*cIzq > k){
            extra -= (i-izq)*cIzq;
            cuantos -= cIzq;
            ++izq;
            cIzq = arre[izq];
        }

        if(extra > k){
            aux = ceil( (double(extra-k)) /(i - izq) );
            cuantos -= aux;
            cIzq -= aux;
            extra -= aux*(i-izq);
        }
        
        if(cuantos > maxi){
            maxi = cuantos;
            de = i;
        }
    }

    cout<<maxi<<" "<<de<<'\n';
    return 0;

}

