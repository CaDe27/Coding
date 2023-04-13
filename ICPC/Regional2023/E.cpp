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
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 1005;
int n, k, e;

map<int, bool> fijos;

bool visited[maxN][maxN];
int dp[maxN][maxN];
int DP(int i, int left){
    if(i > left || i == n+1) return 0;
    if(left == 0) return 0;
    if(left < 0) return -100000;
    
    if(fijos[i])
        return DP(i+1, left);

    if(!visited[i][left]){
        visited[i][left] = true;
        dp[i][left] = max(DP(i+1,left), i + DP(i+1, left - i));
    }
    return dp[i][left];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n>>k>>e;
    
    fijos[k] = true;
    int resp = 0;
    if(e == 0 || (n - (e + k)) == 0)
        resp = n-k - DP(1, n-k);
    else if(e != k){
        fijos[e] = true;
        resp = n-k-e - DP(1, n-k-e);
    }
    else if(n - (e+k) != k){
        fijos[n - (e+k)] = true;
        resp = e - DP(1, e);
    }
    //three sides are the same length
    else{
        if(k==1)
            resp = 2;
        else if(k-1 == 1){
            resp = 3;                                                                                          
        }
        else{
            fijos[k-1] = true;
            fijos[1] = true;
            resp = e - DP(1, e);
        }
    }
    cout<<resp<<"\n";
    return 0;
}