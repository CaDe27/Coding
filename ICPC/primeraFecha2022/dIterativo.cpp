#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef int64_t ll;

#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxK = 100000 + 5, maxN = 100 + 5;
const int logMaxK = 2*20 + 5;
int n, m, k;
bool adj[maxN][maxN];
vector<int> usar;

int cont = 0;
ll dp[maxN][maxN][logMaxK];
void fillDP(){
    int indx = 0;
    loop(i, 1, n+1)
    loop(j, 1, n+1){
        dp[i][j][indx] = (adj[i][j]==1? 1:0);
    }

    int paso;
    for(int u = 1; u < usar.size(); ++u){
        paso = usar[u];
        ++indx;
        loop(i, 1, n+1)
        loop(j, 1, n+1){
            if(paso&1){
                loop(z, 1, n+1)
                    if(adj[i][z])
                        dp[i][j][indx] = (dp[i][j][indx] + dp[z][j][indx-1])%MOD;
            }
            else{
                loop(z,1,n+1)
                    dp[i][j][indx] = (dp[i][j][indx] + (dp[i][z][indx-1]*dp[z][j][indx-1])%MOD)%MOD;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    int a, b;
    loop(i, 0, m){
        cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    

    int copiaK = k, it = 0;
    while(copiaK > 0){
        if(copiaK & 1){
            usar.push_back(copiaK);
            --copiaK;
        }
        if(copiaK != 0)   
            usar.push_back(copiaK);
        copiaK >>=1;
    }
    reverse(usar.begin(), usar.end());

    fillDP();

    ll resp = 0;
    loop(i, 1, n+1)
        resp = (resp + dp[1][i][usar.size()-1])%MOD;
    
    cout<<resp<<"\n";
    return 0;
}