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
const int maxN = 1005;
int mat[maxN][maxN];
bool visited[maxN][maxN];
int n, m;

int dfs(int i, int j){
    int resp = mat[i][j];
    visited[i][j] = true;
    if(i+1 < n && mat[i+1][j] > 0 && !visited[i+1][j])
        resp += dfs(i+1, j);
    if(i-1 >= 0 && mat[i-1][j] > 0 && !visited[i-1][j])
        resp += dfs(i-1, j);
    if(j+1 < m && mat[i][j+1] > 0 && !visited[i][j+1])
        resp += dfs(i, j+1);
    if(j-1 >= 0 && mat[i][j-1] > 0 && !visited[i][j-1])
        resp += dfs(i, j-1);
    return resp;
}

void solve(){
    cin>>n>>m;
    loop(i, 0, n)
    loop(j, 0, m){
        cin>>mat[i][j];
        visited[i][j] = 0;
    }
    
    int resp = 0;
    loop(i, 0, n)
    loop(j, 0, m){
        if(!visited[i][j] && mat[i][j] > 0){
            resp = max(resp, dfs(i, j));
            //cout<<i<<" "<<j<<" "<<resp<<endl;
        }
            
    }
    cout<<resp<<"\n";
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