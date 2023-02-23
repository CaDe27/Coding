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

const int maxN = 1000;
vector<int> weights[maxN];

void solve(){
    int n; cin>>n;
    int totalEdges = n*(n-1)/2;
    int u, v, w;
    loop(i, 0, totalEdges){
        cin>>u>>v>>w;
        --u;--v;
        weights[u].push_back(w);
        weights[v].push_back(w);
    }

    ll resp = 0;
    for(int i = 0; i < n; ++i){
        sort(weights[i].begin(), weights[i].end());
        for(int j = 1; j < n; j += 2)
            resp += weights[i][j];
    }
    cout<<resp<<endl;
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
