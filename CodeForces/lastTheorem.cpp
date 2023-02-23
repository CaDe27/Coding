
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
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 100005;
int n, m;
long double sq;

vi adj[maxN];
int papa[maxN];
bool visited[maxN];
int level[maxN];
bool enInd[maxN];

vi indpSet;
vi ciclo;
bool hayCiclo;

void llenaCiclo(int fa, int son){
    if(level[fa] > level[son])
        swap(fa, son);
    
    while(son != fa){
        ciclo.push_back(son);
        son = papa[son];
    }
    ciclo.push_back(fa);
}

void dfs(int f, int nd){
    visited[nd] = true;
    level[nd] = level[f] + 1;
    papa[nd] = f;

    int maxiBack = 0;

    bool unHijoIndp = false;
    for(int son : adj[nd]){
        if(hayCiclo)
            return;

        if(son == f) continue;

        //si eres back edge
        if(visited[son])
        {
            if(maxiBack == 0)
                maxiBack = son;
            else if( abs(level[nd] - level[son]) > abs(level[nd] - level[maxiBack]))
                maxiBack = son;
        }
        //si eres front edge
        else
            dfs(nd, son);
        
        if(enInd[son])
            unHijoIndp = true;
    }


    if(hayCiclo)
        return;
        
    if( maxiBack != 0 && abs(level[nd] - level[maxiBack])+1 >= sq) {
        hayCiclo = true;
        llenaCiclo(nd, maxiBack);
    }else{
        if(!unHijoIndp){
            indpSet.push_back(nd);
            enInd[nd] = true;
        }
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    sq = ceil(sqrt(n));

    loop(i, 0, m){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    hayCiclo = false;
    dfs(0,1);
    if(!hayCiclo)
    {
        cout<<1<<"\n";
        loop(i, 0, sq)
            cout<<indpSet[i]<<" ";
        cout<<"\n";
    }
    else{
        cout<<2<<"\n";
        cout<<ciclo.size()<<"\n";
        for(int v : ciclo)
            cout<<v<<" ";
        cout<<"\n";
    }
}


