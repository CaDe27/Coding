#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
typedef int64_t ll;

#define MOD 1000000007LL
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
unordered_map<int, ll> superMemo;
const int maxN = 5e5+1;
ll memo[maxN];
ll fibo(ll i){
    if(i < maxN) 
        return memo[i];
    else{
        if(superMemo[i] == 0){
            superMemo[i] = (a.pow(i-1).m)[0][0];
        }
        return superMemo[i];
    }
}


void fillMemo(){
    memo[0] = 0;
    memo[1] = 1;
    loop(i, 2, maxN)
        memo[i] = (memo[i-1] + memo[i-2])%MOD;
}
int main(){
    fillMemo();

    a.m[0][0] = 1;
    a.m[0][1] = 1;
    a.m[1][0] = 1;
    a.m[1][1] = 0;
    
    int n, m;
    cin>>n>>m;
    vector<int> missing;
    missing.push_back(-1);
    loop(i, 0, m) {
        int miss;
        cin>>miss;
        if(miss == 0 || miss == n){
            cout<<"0\n";
            return 0;
        }
        else if(miss > 0 && miss < n){
            missing.push_back(miss);
        }
    }
    missing.push_back(n+1);
    sort(missing.begin()+1, missing.end()-1);
    loop(i, 1, missing.size()){
        if(missing[i] == missing[i-1]){
            cout<<"0\n";
            return 0;
        }
    }
    
    ll resp = 1;
    loop(i, 1, missing.size()){
        resp = resp * fibo(missing[i] - missing[i-1] - 1);
        resp %= MOD;
    }
    cout<<resp<<"\n";
    return 0;
}