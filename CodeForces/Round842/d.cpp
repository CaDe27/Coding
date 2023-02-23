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

const int maxN = 2e5 + 5;
int n;
int p[maxN];
bool visited[maxN];
int cycle[maxN];
int cycles = 0;

void dfs(int i){
    if(visited[i]) return;
    visited[i] = true;
    cycle[i] = cycles;
    dfs(p[i]);
}

void solve(){  
    cin>>n;
    loop(i, 1, n+1)  cin>>p[i];
    fill(visited, visited+n+1, 0);
    cycles = 0;
    loop(i, 1, n+1){
        if(!visited[i]){
            ++cycles;
            dfs(i);
        }
    }
    int resp = n, respCase; 
    loop(i, 1, n){
        if(cycle[i] == cycle[i+1])
            respCase = n - (cycles+1);
        else
            respCase = n - (cycles-1);
        resp = min(resp, respCase);
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