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

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef pair<int,int> pii;

#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 8005;
int n; 
int arre[maxN];
ll respMax[maxN], respMin[maxN];


void fillMaxi(){
    vector<int> sorted(arre, arre+n);
    sort(sorted.begin(), sorted.end(), greater<int>());
    ll suma = 0;
    for(int i = 0; i < n; ++i){
        suma += sorted[i];
        respMax[i] = suma;
    }
}

//we use the famous stack process (like destruyendo edificios)
ll indxBigger[maxN];
void fillNextBigger(){
    stack<pii> bigger;
    bigger.push(pii(arre[0], 0));
    loop(i, 1, n){
        while(!bigger.empty() && arre[i] >= bigger.top().first){
            indxBigger[bigger.top().second] = i;
            bigger.pop();
        }
        bigger.push(pii(arre[i], i));
    }
    while(!bigger.empty()){
        indxBigger[bigger.top().second] = n;
        bigger.pop();
    }
}


ll dp[maxN][maxN];
stack<pair<int,ll> > stackDP;
ll DP(int partitions){
    while(!stackDP.empty())
        stackDP.pop();

    ll INF = maxN*(1000000000LL);
    for(int i = n-partitions+1; i <= n-1; ++i)
        dp[i][partitions] = INF;

    stackDP.push(make_pair(arre[n-partitions+1], dp[n-partitions+1][partitions-1]));
    ll aux;
    for(int i = n-partitions; i>=0; --i){
        aux = INF;
        while(!stackDP.empty() && arre[i] > stackDP.top().first){
            aux = min(aux, stackDP.top().second);
            stackDP.pop();
        }

        //actualizo dp[i][partitions]
        if(stackDP.empty()){
            //i was the biggest
            //aux cant be the INF in this case, sinces there's always someone on the stack
            //when I arrive
            dp[i][partitions] = arre[i] + aux;
        }
        else{
            dp[i][partitions] = min( ((ll)arre[i]) + min(aux, dp[indxBigger[i]][partitions-1]), dp[indxBigger[i]][partitions]);
        }
        stackDP.push(make_pair(arre[i], min(aux, dp[i][partitions-1])));
    }
    return dp[0][partitions];
}   


void solve(){
    cin>>n;
    loop(i, 0, n)
        cin>>arre[i];

    //for the max for k partitions we just take the k biggest elements
    fillMaxi();

    //for min we use dp(index, partionsLeft) = min(arre[indx] + dp(indx+1, partions-1), dp(indexNextBigger, partions))
    fillNextBigger();
    //we also fill case where theres only one partition
    dp[n-1][1] = arre[n-1];
    for(int i = n-2; i >= 0; --i){
        dp[i][1] = max((ll)arre[i], dp[i+1][1]); 
    }
    respMin[0] = dp[0][1];

    loop(i, 1, n){
        respMin[i] = DP(i+1);
    }

    loop(i, 0, n){
        cout<<respMin[i]<<" "<<respMax[i]<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}

