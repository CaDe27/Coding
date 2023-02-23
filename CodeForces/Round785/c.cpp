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

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 4*1e4+5;

vector<int> palindromos;
int pMenorIg[maxN];
void llenaPalindromos(){

    for(int j = 3; j>= 1; --j){
    for(int i = 9; i>=0; --i){
    for(int k = 9; k>=0; --k){
        palindromos.push_back(10001*j + 1010*i + 100*k);
    }}}

    for(int j = 9; j>= 1; --j)
    for(int i = 9; i>=0; --i){
        palindromos.push_back(1001*j + 110*i);
    }

    for(int j = 9; j>=1; --j)
    for(int i = 9; i>=0; --i){
        palindromos.push_back(101*j + 10*i);
    }

    for(int i = 9; i>=1; --i){
        palindromos.push_back(11*i);
    }
    
    for(int i = 9; i>=1; --i){
        palindromos.push_back(i);
    }
}

ll dp[maxN][500];
ll DP(int n, int i){
    if(n == 0)
        return 1;
    if(i == palindromos.size()-1)
        return 1;
    if(dp[n][i] == 0){
        if(palindromos[i] <= n)
            dp[n][i] = DP(n-palindromos[i],i);
        dp[n][i] = (dp[n][i] + DP(n,i+1))%MOD;
    }
    return dp[n][i]%MOD;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    llenaPalindromos();
    int t; cin>>t;
    int n;
    loop(i, 0, t){
        cin>>n;
        cout<<DP(n,0)<<"\n";
    }
    return 0; 
}
