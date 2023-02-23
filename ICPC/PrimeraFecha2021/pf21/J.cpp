#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef int64_t ll;
typedef pair<int, int> pii; 

const int MAXN = 1e5+10;
vector<int> adj[MAXN];
const int MOD = 998244353;

ll fast(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a%MOD;
    ll c = fast(a,b/2);
    c = (c*c)%MOD;
    if(b&1){
        c *= a;
        c %= MOD;
    }
    return c;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int mi;
    for(int i=2;i < n+1;++i){
        cin >> mi;
        adj[mi].push_back(i);
        adj[i].push_back(mi);
    }

    bool visited[n+1];
    fill(visited, visited+n+1, 0);
    queue<pii> bfs;

    //si soy hoja inicio la bfs
    for(int i=2; i < n+1;i++)
        if(adj[i].size() == 1)
            bfs.push(pii(i, 1)); 

    ll suma = 0;
    int u, espera, v;
    while(!bfs.empty()){
        u = bfs.front().first;
        espera = bfs.front().second;
        bfs.pop();

        if(visited[u]) continue;
        visited[u] = true; 
        suma += espera;
        for(vector<int>::iterator itV = adj[u].begin(); itV != adj[u].end(); ++itV){
            v = *itV;
            if(!visited[v])
                bfs.push(pii(v, espera+1));
        }
    }
    cout <<(suma*fast(n, MOD-2))%MOD << "\n";

    return 0;
}
