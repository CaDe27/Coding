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
#include <fstream>

using namespace std;

typedef int64_t ll;
#define MOD 1000000007

#define MINF -1000000000000


#define loop(i,a,b) for(ll i = a; i < b; ++i)

const int maxP = 1e6 + 5;
vector<int> prime;
int menorPrimo[maxP];

void sieve () {
    loop(i, 0, maxP){
        menorPrimo[i] = i;
    }
    menorPrimo[0] = menorPrimo[1] = 1;
    
    for (int i = 2; i < maxP; ++i) {
        if (menorPrimo[i] == i) 
            prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] < maxP; ++j) {
            menorPrimo[i * prime[j]] = min(menorPrimo[i], prime[j]);
            if (i % prime[j] == 0) break;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    sieve();
    int krep[1000001];
    int pot2[1000001];

    krep[1] = 0;
    pot2[1] = 2;
    int p;
    ll aux1;
    loop(i, 2, 1e6 + 1){
        aux1 = 2;
        aux1 = (aux1*((ll)pot2[i-1]))%MOD;
        pot2[i] = (int) aux1;
        if(menorPrimo[i] == i)
            krep[i] = 2;
        else{
            p = menorPrimo[i];
            krep[i] = pot2[i/p];
            if(i % (p*p) != 0){
                aux1 = krep[i];
                aux1 = (aux1 + ((ll)pot2[p]) + MOD - 2)%MOD;
                krep[i] = (int) aux1;
            }
        }
    }

    int t; cin>>t;
    int k;
    loop(i, 0, t){
        cin>>k;
        cout<<krep[k]<<"\n";
    }
     
   return 0; 
}