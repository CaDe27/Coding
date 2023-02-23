#include <iostream>
#include <algorithm>

using namespace std;
typedef int64_t ll;

#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxK = 5000 + 5;
int k, m, n; 

ll fact[maxK], invFact[maxK];
ll binPow(ll base, ll exp){
    ll r = 1;
    while (exp > 0){
        if( exp & 1)
            r = (r*base) % MOD;
        exp >>= 1;
        base = (base * base) % MOD;
    }
    return r;
} 
ll comb(int num, int k){
    if (num < 0 || num < k) return 0;
    return (((fact[num]*invFact[k])%MOD)*invFact[num-k])%MOD;
}

//formas[i] tiene la cantidad de palabras distintas de tamanio n que 
//          puedo formar con i letras distintas
ll formas[maxK];
void llenaFormas(){
    formas[1] = 1;
    for(int i = 2; i <= k; ++i){
        //inicio con todas las formas de almenos i letras
        formas[i] = binPow(i, n);
        //resto las de menos de i letras
        for(int j = 1; j <= i-1; ++j){
            formas[i] = (formas[i] - (comb(i, j) * formas[j])%MOD + MOD)%MOD;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;  

    //precalculo factoriales
    fact[0] = invFact[0] = 1;
    for(int i = 1; i <= m; ++i){
        fact[i] = (fact[i-1]*i)%MOD;
        invFact[i] = binPow(fact[i], MOD-2);
    }
        
    llenaFormas();
    ll resp = (comb(m, k) * formas[k]) %MOD;
    cout<<resp<<"\n";

    return 0; 
}
