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

const int maxN = 1e6+5;
int n, x;

vector<int> adj[maxN];
int sizeS[maxN], dis[maxN], father[maxN];
int dfs(int v, int fa){
    father[v] = fa; 
    dis[v] = 1+dis[fa];
    int sum = 1;
    for(int son : adj[v]){
        if(son == fa) continue;
        sum += dfs(son, v);
    }
    sizeS[v] = sum;
    return sizeS[v];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n>>x;
    --x;
    loop(i, 0, n-1){
        int a, b;
        cin>>a>>b;
        --a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, 0);
    cout<<2*(n-sizeS[father[x]]) - dis[father[x]] + 2<<"\n";
    return 0;
}