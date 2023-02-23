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

const int maxN = 1005;
int n;

ll v[maxN][maxN];
ll dp[maxN][maxN];
bool visited[maxN][maxN];

ll DP(int f, int c){
    if(f == n-1)
        return v[f][c];

    if(!visited[f][c]){
        visited[f][c] = 1;
        dp[f][c] = v[f][c] + max(DP(f+1,c), DP(f+1, c+1));
    }
    return dp[f][c];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i <= n-1; ++i)
    for(int j = 0; j <= i; ++j){
        visited[i][j] = false;
        cin>>v[i][j];
    }
    cout<<DP(0, 0)<<endl;
}