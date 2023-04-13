#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

#define loop(i, a, b) for(ll i = a; i < b; ++i)
#define maxN 1100
#define inf INT64_MAX
typedef int64_t ll;
typedef pair<ll,ll> pii;

ll n, k;
struct edge{
    
    ll v, f, c, val;
    edge(){}
    edge(ll v, ll f, ll c, ll val): v(v), f(f), c(c), val(val) {};
};

ll v;
vector<edge> edges;
vector<ll> graph[maxN];
ll dist[maxN], ptr[maxN], pai[maxN];

void add(ll u, ll v, ll c, ll val){
    edges.push_back(edge(v, 0, c, val));
    //le dices a u que la edge que acabas de agregar a edges sale de ella
    graph[u].push_back(edges.size()-1);
    edges.push_back(edge(u, 0, 0, -val));
    graph[v].push_back(edges.size()-1);
}

pii operator+(pii a, pii  b){
    a.first += b.first;
    a.second += b.second;
    return a;
}

bool dijkstra(ll s, ll t){
    for(ll i = 0; i < v; ++i){
        dist[i] = inf;
        pai[i] = -1;
    }
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(pii(0, s));
    
    while(!q.empty()){
        ll d = q.top().first, u = q.top().second;
        q.pop();
        if(d > dist[u]) continue;

        for(ll e : graph[u]){
            if(dist[u] + edges[e].val < dist[edges[e].v]
                && edges[e].c - edges[e].f > 0){
                    dist[edges[e].v] = dist[u] + edges[e].val;
                    pai[edges[e].v] = u;
                    q.push(pii(dist[edges[e].v], edges[e].v));
            }
        }
    }
    return dist[t] != inf;
}

pii dfs(ll s, ll t, ll f){
    if(s == t){
        return pii(0, f);
    }
    
    for(ll &i = ptr[s]; i < graph[s].size(); ++i){
        ll e = graph[s][i];
        if(pai[edges[e].v] == s 
            && dist[edges[e].v] == dist[s] + edges[e].val
            && edges[e].c - edges[e].f > 0){
            
            pii x = pii(edges[e].val, 0) + dfs(edges[e].v, t, min(f, edges[e].c - edges[e].f));
            if(x.second){
                edges[e].f += x.second;
                edges[e^1].f -= x.second;
                return x;
            }
        }
    }

    return pii(0, 0);
}

pii getMaxFlowMinCost(ll s, ll t){
    pii ans(0, 0);
    while(dijkstra(s, t)){
        fill(ptr, ptr + maxN, 0);
        pii x;
        while( (x = dfs(s, t, inf)).second ){
            ans = ans + x;
        }
    }
    return ans;
}

int main(){
    cin>>n>>k;
    v = 2 + n + n+1;

    add(0, 1, k, 0);
    ll cij;
    loop(i, 1, n+1 +1){
        loop(j, i+1, n+1 + 1){
            cin>>cij;
            add(i, n+j, 1, cij);
        }
        //del nodo al sink
        add(i, 2*n+2, k, 0);
        //para conectar los caminos, del nodo i derecho al nodo i izquierdo
        if(i >= 2){
            add(n+i, i, 1, -1000000000000);
        }
    }
    cout<<getMaxFlowMinCost(0, 2*n+2).first + n*(1000000000000)<<"\n";
}