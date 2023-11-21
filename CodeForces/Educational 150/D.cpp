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
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;
const int maxN = 2005;
int n;
pii pairs[maxN]; 
int dp[maxN];
void solve(){
    cin>>n;
    loop(i, 0, n)
        cin>>pairs[i].first>>pairs[i].second;
    sort(pairs, pairs+n);

    dp[n-1] = 1;
    dp[n] = 0;
    for(int i = n-2; i >= 0; --i){
        //no tomo
        dp[i] = 1 + dp[i+1];

        //si lo tomo
        if(pairs[i+1].first > pairs[i].second)
            continue;

        int indxMin = i+1;  
        for(int j = i+2; j < n && pairs[j].first <= pairs[i].second; ++j){
            if(pairs[indxMin].second > pairs[j].second)
                indxMin = j;
        }

        int sig = indxMin+1;
        while(sig < n && pairs[sig].first <= max(pairs[i].second, pairs[indxMin].second)){
            ++sig;
        }
        dp[i] = min(dp[i], dp[sig] + sig-1 - (i-1) -2);
    }

    cout<<dp[0]<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}