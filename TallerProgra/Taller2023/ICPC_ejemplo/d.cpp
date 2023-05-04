#include<iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, m;
    cin>>n>>m>>k;    

    vector<int> adj[n];
    for(int i = 0; i <m ;++i){
        int a, b;
        cin>>a>>b;
        --a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int f[n][k+1];
    //calcularlas
    for(int i = 0; i < n; ++i)
        f[i][0] = 1;
    
    for(int j=1; j < k; ++j){
        for(int i = 0; i < n; ++i){
            f[i][j] = 0;
            for(int adyacente : adj[i]){
                f[i][j] = f[i][j] + f[adyacente][j-1];
                if( f[i][j] > MOD)
                    f[i][j] -= MOD; 
            }
        }
    }

    f[0][k] = 0;
    for(int adyacente : adj[0]){
        f[0][k] = f[0][k] + f[adyacente][k-1];
        if( f[0][k] > MOD)
            f[0][k] -= MOD; 
    }

    cout<<f[0][k]<<"\n";
    return 0;
}



