#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define MOD 1000000007


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


int main()
{

    int M = 1e6;

    ll ans[M+1];

    ans[0] = 1;

    for(int i=1;i<=M;i++){
        ans[i] = (2*ans[i-1])%MOD;
    }

    for(int i=1;i<=M;i++){
        int k = 2*i;
        while(k <= M){
            ans[k] = (ans[k]-ans[i])%MOD;
            k += i;
        }
    }

    int T; cin >> T;

    while(T--){
        int K; cin >> K;
        cout << (((binPow(2,K)-ans[K])%MOD)+MOD)%MOD << "\n";
    }

    return 0;
}
