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
const int maxN = 3002;
int n, m;
char mat[maxN][maxN];
int adj[maxN*maxN], fa[maxN*maxN], sizeM[maxN*maxN];
bool visited[maxN][maxN];

int father(int a){
    return fa[a] == a? a : fa[a] = father(fa[a]);
}

void unite(int i, int j){
    fa[father(i)] = father(j);
}

// void dfssss(int i, int j){
//     visited[i][j] = true;
//     if(i+1 < n && !visited[i+1][j] && mat[i][j] == mat[i+1][j]){
//         unite(i*m +j, (i+1)*n + j);
//         dfs(i+1, j);
//     }
//     if(i-1 >=  0 && !visited[i-1][j] && mat[i][j] == mat[i-1][j]){
//         unite(i*m +j, (i-1)*n + j);
//         dfs(i-1, j);
//     }
//     if(j-1 >=  0 && !visited[i][j-1] && mat[i][j] == mat[i][j-1]){
//         unite(i*m +j, i*m +j-1);
//         dfs(i, j-1);
//     }
//     if(j+1 < m && !visited[i][j+1] && mat[i][j] == mat[i][j+1]){
//         unite(i*m +j, i*m +j + 1);
//         dfs(i, j+1);
//     }
// }

set<int> fas;
string solve(){
    cin>>n>>m;
    loop(i, 0, n)
    loop(j, 0, m){
        visited[i][j] = false;
        sizeM[i*m +j] = 0;
        adj[i*m +j] = 0;
        fa[i*m +j] = i*m +j;
    }
    
    loop(i, 0, n){
    loop(j, 0, m){
        cin>>mat[i][j];      
    }
    }    

    loop(i, 0, n){
    loop(j, 0, m){
            if(mat[i][j] != 'W') continue;
            if(i+1 < n && !visited[i+1][j] && mat[i][j] == mat[i+1][j]){
                unite(i*m +j, (i+1)*m + j);
            }
            if(i-1 >=  0 && !visited[i-1][j] && mat[i][j] == mat[i-1][j]){
                unite(i*m +j, (i-1)*m + j);
            }
            if(j-1 >=  0 && !visited[i][j-1] && mat[i][j] == mat[i][j-1]){
                unite(i*m +j, i*m +j-1);
            }
            if(j+1 < m && !visited[i][j+1] && mat[i][j] == mat[i][j+1]){
                unite(i*m +j, i*m +j + 1);
            }
        }
    }

    // cout<<endl;
    // loop(i, 0, n){
    // loop(j, 0, m){
    //     if(mat[i][j] == 'W'){
    //         cout<<father(i*m +j)<<" ";
    //     }
    //     else
    //         cout<<mat[i][j]<<" ";
       
    // }
    //  cout<<endl;
    // }

    loop(i, 0, n)
    loop(j, 0, m){
        if(mat[i][j] == 'W')
            ++sizeM[father(i*m +j)];
    }

    
    loop(i, 0, n)
    loop(j, 0, m){
        fas.clear();
        if(mat[i][j] == '.'){
            if(i-1 >= 0 && mat[i-1][j] == 'W'){
                fas.insert(father((i-1)*m+j));
            }
            if(j-1 >= 0 && mat[i][j-1] == 'W'){
                fas.insert(father((i)*m+j-1));
            }
            if(i+1 < n && mat[i+1][j] == 'W'){
                fas.insert(father((i+1)*m + j));
            }
            if(j+1 < m && mat[i][j+1] == 'W'){
                fas.insert(father(i*m +j+1));
            }
            for(int x  : fas){
                ++adj[x];
            }
            // if(fas.size() > 0)
            //     {
            //         cout<<i<<" "<<j<<endl;
            //     }
        }
    }

    int resp = 0, respCase;
    loop(i, 0, n)
    loop(j, 0, m){
        if(mat[i][j] == '.'){
            fas.clear();
            if(i-1 >= 0 && mat[i-1][j] == 'W' && adj[father((i-1)*m+j)] == 1){
                fas.insert(father((i-1)*m+j));
            }
            if(j-1 >= 0 && mat[i][j-1] == 'W' && adj[father((i)*m+j-1)] == 1){
                fas.insert(father((i)*m+j-1));
            }
            if(i+1 < n && mat[i+1][j] == 'W' && adj[father((i+1)*m+j)] == 1){
                fas.insert(father((i+1)*m + j));
            }
            if(j+1 < m && mat[i][j+1] == 'W' && adj[father((i)*m+j+1)] == 1){
                fas.insert(father(i*m +j+1));
            }
            respCase = 0;
            
            for(int x  : fas){
                respCase += sizeM[x];
            }
            // if(fas.size() > 0)
            //     {
            //         cout<<i<<" "<<j<<endl;
            //     }
            resp = max(resp, respCase);
        }
    }
    return to_string(resp);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    for(int i = 1; i <= t; ++i){
        cout<<"Case #"<<i<<": "<<solve()<<"\n";
    }
    return 0;
}