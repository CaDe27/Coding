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

const int maxN = 105;
int n, k;

int dist[maxN][maxN];

void floydWarshall(){
    loop(k, 0, n){
    loop(i, 0, n){
    loop(j, 0, n){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }}}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int m;
    cin>>n>>m>>k;
    int c;
    loop(i, 0, n) cin>>c;
    //initialize distances matrix for Floyd Warshall
    loop(i, 0, n){
        loop(j, 0, n){
            dist[i][j] = 2*n;
        }
        dist[i][i] = 0;
    }

    //read graph
    int a, b;
    loop(i, 0, m){
        cin>>a>>b;
        --a;--b;
        dist[a][b] = dist[b][a] = 1;   
    }

    floydWarshall();

    int diam = 0;
    loop(i, 0, n)
    loop(j, 0, n){
        if(dist[i][j] == 2*n) continue;
        diam = max(diam, dist[i][j]);
    }

    cout<<diam+k<<"\n";
    return 0;
}