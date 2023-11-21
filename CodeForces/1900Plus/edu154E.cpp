//https://codeforces.com/contest/1861/problem/E
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
#define INF 1000000000000000000
#define MOD 998244353
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;
const int maxN = 500005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n, k; cin>>n>>k;

    ll dp[n][k+1], sdp[n][k+1];
    ll kpowers[n];
    kpowers[0] = 1;
    loop(i, 1, n)
        kpowers[i] = (kpowers[i-1]*k)%MOD;

    fill(dp[0], dp[0]+k+1, 0);
    dp[0][1] = k;

    fill(sdp[0], sdp[0]+k+1, 0);
    sdp[0][1] = k;

    ll resp = 0;
    loop(i, 1, n){    
        loop(itK, 1, k+1){
            dp[i][itK] = itK==1? k*dp[i-1][k] : (k-itK+1)*dp[i-1][itK-1]%MOD;
            if(itK < k)
                dp[i][itK] = (dp[i][itK] + sdp[i-1][itK]%MOD)%MOD;
        }
        resp = (resp + dp[i][k]*kpowers[n-i-1])%MOD;

        //sdp
        sdp[i][k-1] = dp[i][k-1];
        for(int itK = k-2; itK >= 1; --itK){
            sdp[i][itK] = (sdp[i][itK+1] + dp[i][itK])%MOD;
        }
    }
    cout<<resp<<"\n";
    return 0;
}