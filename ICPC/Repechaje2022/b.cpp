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

const int maxN = 105;
int n, m;
int resp = 10;

int mat[maxN][maxN];
bool vis[maxN][maxN];
int sx, sy, ex, ey, active;
pii movs[4] = {pii(-1, 0), pii(1, 0), pii(0, -1), pii(0, 1)};

bool possible(int x, int y){
    return (active & (1<<(mat[x][y]-1))) != 0;
}

bool dfs(int x, int y){
    if(x == ex && y == ey) return true;
    if(vis[x][y]) return false;
    vis[x][y] = true;
    
    for(pii mov : movs){
        if(x + mov.first < 0 || x + mov.first >= n) continue;
        if(y + mov.second < 0 || y + mov.second >= m) continue;
        if(vis[x+mov.first][y+mov.second]) continue;
        if(possible(x+mov.first, y+mov.second)){
            if(dfs(x+mov.first, y+mov.second))
                return true;
        }
    }
    return false;
}

bool sePuede(){
    loop(i, 0, n) fill(vis[i], vis[i]+m, 0);
    return dfs(sx, sy);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n>>m;
    cin>>sx>>sy>>ex>>ey;
    --sx;--sy;--ex;--ey;
    loop(i, 0, n)
    loop(j, 0, m){
        cin>>mat[i][j];
    }

    int cont;
    loop(i, 1, 1023){
        active = i;
        if( (active & 1<<(mat[sx][sy]-1)) == 0) continue;
        cont = 0;
        if(sePuede()){
            while(active > 0){
                if(active&1)
                    ++cont;
                active>>=1;
            }
            resp = min(resp, cont);
        }
    }
    cout<<resp<<"\n";
    return 0;
}