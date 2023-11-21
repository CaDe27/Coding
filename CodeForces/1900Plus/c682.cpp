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
const int maxN = 105;;
int mat[maxN][maxN];
bool contra;
vector<pair<pii, char> > adj[maxN][maxN];
int v[maxN][maxN], inc[maxN][maxN];
int cV, n, m;

int finalVal(int i, int j){return mat[i][j] + inc[i][j];}

stack<pair<pii, int> > d;
void dfs(int x, int y, int val){
    while(!d.empty()) d.pop();

    d.push(pair(pii(x, y), val));
    int i, j, value;
    while(!d.empty()){
        i = d.top().first.first; j = d.top().first.second;
        value = d.top().second;
        d.pop();
        
        if(v[i][j] < cV){
            ++v[i][j];
            inc[i][j] = value; 
            for(auto ve : adj[i][j]){
                if(v[ve.first.first][ve.first.second] < cV)
                {
                    if(ve.second == 's')
                        d.push(pair(ve.first, value));
                    else
                        d.push(pair(ve.first, value^1));
                }
            }
        }

        if(i >0 && finalVal(i, j) == finalVal(i-1, j))
            contra = true;
        else if(i+1 < n && finalVal(i+1, j) == finalVal(i, j))
            contra = true;
        else if(j>0 && finalVal(i, j) == finalVal(i, j-1))
            contra = true;
        else if(j+1 < m && finalVal(i, j) == finalVal(i, j+1))
            contra = true;
    }
}

void solve(){
    cin>>n>>m;
    loop(i, 0, n)
    loop(j, 0, m)
        cin>>mat[i][j];
    
    loop(i, 0, n)
    loop(j, 0, m){
        adj[i][j].clear();
        inc[i][j] = 0;
        v[i][j] = 0;
    }

    loop(i, 0, n)
    loop(j, 0, m)
    {
        if( i > 0){
            if(mat[i-1][j] == mat[i][j])
                adj[i][j].push_back(pair(pii(i-1, j), 'd'));
            else if( abs(mat[i-1][j] - mat[i][j]) == 1){
                adj[i][j].push_back(pair(pii(i-1, j), 's'));
            }
        } 
        if( j > 0){
            if(mat[i][j-1] == mat[i][j])
                adj[i][j].push_back(pair(pii(i, j-1), 'd'));
            else if( abs(mat[i][j-1] - mat[i][j]) == 1){
                adj[i][j].push_back(pair(pii(i, j-1), 's'));
            }
        }
        if(i+1 < n){
            if(mat[i+1][j] == mat[i][j])
                adj[i][j].push_back(pair(pii(i+1, j), 'd'));
            else if( abs(mat[i+1][j] - mat[i][j]) == 1){
                adj[i][j].push_back(pair(pii(i+1, j), 's'));
            }
        }
        if(j+1 < m){
            if(mat[i][j+1] == mat[i][j])
                adj[i][j].push_back(pair(pii(i, j+1), 'd'));
            else if( abs(mat[i][j+1] - mat[i][j]) == 1){
                adj[i][j].push_back(pair(pii(i, j+1), 's'));
            }
        }
    }


    loop(i, 0, n)
    loop(j, 0, m){
        if(!v[i][j]){
            cV=1;
            contra = 0;
            dfs(i, j, 0);
            if(contra){
                cV=2;
                dfs(i, j, 1);
            } 
        }
    }

    loop(i, 0, n)
    loop(j, 0, m){
        cout<<mat[i][j]+inc[i][j]<<" \n"[j==m-1];
    }
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