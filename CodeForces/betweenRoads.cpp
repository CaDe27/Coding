/*
    si hay una arista que no es puente, no se puede
    si todas son no puentes, direccionamos
        front edges hacia abajo
        back edges hacia arriba
*/
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

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)

const int maxN = 100005;
int n,m;
vector<pii> roads;

vi adj[maxN];
bool visited[maxN];
int level[maxN];

// =========== Puentes 
/*  
    dp[u] = numero de back edges que van de un "hijo" de u a un "ancestro" de u
    puente entre a y b syss 
    dp[u] = 0

    calculo de dp[u] = Suma(dp[hijos]) - backedgesQueLLeganAU + backEdgedSalenU 
*/

int dp[maxN];
int llegan[maxN];
bool hayPuente;

void dfs(int f, int nd){
    visited[nd] = true;
    level[nd] = level[f] + 1;
    int salen = 0;
    for(int son : adj[nd]){
        if(son != f)
        {
            //si eres back edge
            if(visited[son] && level[son] < level[nd]){
                ++salen;
                ++llegan[son];
                roads.push_back(pii(nd, son));
            }
            //si eres front edje
            else if(!visited[son]){
                dfs(nd, son);
                dp[nd] += dp[son]; 
                roads.push_back(pii(nd, son));
            }
        }
    }
    
    dp[nd] = dp[nd] - llegan[nd] + salen;
    if(nd != 1 && dp[nd] == 0)
        hayPuente = true;
    
}

//========Main
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin>>n>>m;
    hayPuente = false;
    loop(i, 0, m){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    level[1] = 0;
    dfs(0, 1);
    if(hayPuente)
        cout<<0<<"\n";
    else
    {
        for(pii rd : roads)
            cout<<rd.first<<" "<<rd.second<<"\n";
    }
}

