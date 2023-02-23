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

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;

#define MINF -1000000000000

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)


const int maxN = 100005;

ll suma[maxN];
ll memo[maxN][maxN];

ll dp(int l, int r){
    if(l==r)
        return suma[r] - suma[l-1];
    
    else if(memo[l][r]==0)
        memo[l][r] = suma[r]-suma[l-1] - min(dp(l+1, r), dp(l, r-1));
    return memo[l][r];
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;cin>>n;
    ll aux;
    suma[0] = 0;

    cin>>suma[1];
    loop(i, 2, n+1){
        cin>>aux;
        suma[i] = suma[i-1] + aux;
    }
    cout<<dp(1, n)<<'\n';
}