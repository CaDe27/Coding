#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef int64_t ll;

#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

struct matrix{
    vector< vector<ll> > m;
    ll mod, sz;
    ll mod2;
 
    matrix (ll n,ll modc) : sz(n),m(n), mod(modc) {
        for(int i=0;i<n;i++)
            m[i].resize(n);
        mod2=mod*mod;
    }
    matrix operator*(matrix b)
    {
        matrix ans(sz,mod);
        for(int i=0;i<sz;i++)
        for(int j=0;j<sz;j++)
            for(int u=0;u<sz;u++)
            {
                ans.m[i][u]+=m[i][j]*b.m[j][u];
                if(ans.m[i][u]>=mod2)
                    ans.m[i][u]-=mod2;
            }
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                ans.m[i][j]%=mod;
        return ans;
    }
 
    matrix pow(ll e)
    {
        if(e==1)
            return *this;
        matrix x =pow(e/2);
        x=(x*x);
        if(e&1)
            x=(x*(*this));
        return x;
    }
};


matrix a = matrix(2, MOD);
const int maxN = 1e6+1;
ll memo[maxN];
ll fibo(ll i){
    if(i < maxN) 
        return memo[i];
    else
        return (a.pow(i).m)[0][1];
}

int main(){
    memo[0] = 0;
    memo[1] = 1;
    loop(i, 2, maxN)
        memo[i] = (memo[i-1] + memo[i-2])%MOD;

    a.m[0][0] = 1;
    a.m[0][1] = 1;
    a.m[1][0] = 1;
    a.m[1][1] = 0;
    
    int k;cin>>k;
    cout<<fibo(k)<<endl;
    
    return 0;
}