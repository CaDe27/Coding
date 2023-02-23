
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

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)

using namespace std;

typedef int64_t ll;

const int maxN = 500000;
const ll maxA = ll(1E9), maxK = ll(1E18);
ll a[maxN+5], extra[maxN+5];
int n, r;
ll k;

ll sumaIni;
bool sePuede(ll nivel){
    fill(extra, extra+n, 0);
    ll total, extras;
    int i, lindx;

    total = sumaIni;
    extras = 0;
    lindx = 0;
    i = 0;
    
    while(extras <= k && i < n){
        if(total < nivel){
            extras += nivel - total;
            extra[min(i+r, n-1)] += nivel - total;
            total = nivel;
        }
        //preparamos el total del siguiente
        ++i;
        if(i < n){
            if(i+r < n)
                total += a[i+r];
            if(i - lindx > r){
                total -=  a[lindx] + extra[lindx];
                ++lindx;
            }
        }
    }
    return extras <= k;
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>r>>k;

    sumaIni = 0;
    loop(i, 0, n){
        cin>>a[i];
        if(i <= r)
            sumaIni += a[i];
    }
    
    //min nivel es 0
    //max es sumaDelArreglo + extras (en caso r = n)
    //       max es (10^9)*500000 + 10^18
    ll ini, fin, mitad;
    ini = 0;
    fin = ((ll)n)*maxA + maxK;
    while(ini != fin){  
        mitad = (ini + fin)/2 + 1;
        if(sePuede(mitad))
            ini = mitad;
        else
            fin = mitad - 1;
    }
    cout<<ini<<'\n';
}