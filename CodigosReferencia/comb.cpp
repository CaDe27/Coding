#define MOD 
typedef int64_t ll;

const int maxN = 2*1e5 + 5;
ll fact[maxN], invFact[maxN];
ll comb(int num, int k){
    if (num < 0 || num < k) return 0;
    return (((fact[num]*invFact[k])%MOD)*invFact[num-k])%MOD;
}


    fact[0] = invFact[0] = 1;
    for(int i = 1; i < maxN; ++i){
        fact[i] = (fact[i-1]*i)%MOD;
        invFact[i] = binPow(fact[i], MOD-2);
    }
