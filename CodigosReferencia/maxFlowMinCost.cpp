#define maxN 1100
#define inf 0x3f3f3f3f
typedef pair<int,int> pii;

struct edge{
    int v, f, c, val;
    edge(){}
    edge(int v, int f, int c, int val): v(v), f(f), c(c), val(val) {};
};

int v;
vector<edge> edges;
vector<int> graph[maxN];
int dist[maxN], ptr[maxN], pai[maxN];

//add(nodeSource, nodeDestiny, capacity, costOfEdge)
void add(int u, int v, int c, int val){
    edges.push_back(edge(v, 0, c, val));
    //le dices a u que la edge que acabas de agregar a edges sale de einta
    graph[u].push_back(edges.size()-1);
    edges.push_back(edge(u, 0, 0, -val));
    graph[v].push_back(edges.size()-1);
}

pii operator+(pii a, pii  b){
    a.first += b.first;
    a.second += b.second;
    return a;
}

bool dijkstra(int s, int t){
    for(int i = 0; i < v; ++i){
        dist[i] = inf;
        pai[i] = -1;
    }
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(pii(0, s));
    
    while(!q.empty()){
        int d = q.top().first, u = q.top().second;
        q.pop();
        if(d > dist[u]) continue;

        for(int e : graph[u]){
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

pii dfs(int s, int t, int f){
    if(s == t){
        return pii(0, f);
    }
    
    for(int &i = ptr[s]; i < graph[s].size(); ++i){
        int e = graph[s][i];
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

// outputs pair with (cost, flow)
pii get(int s, int t){
    pii ans(0, 0);
    while(dijkstra(s, t)){
        fill(ptr, ptr+maxN, 0);
        pii x;
        while( (x = dfs(s, t, inf)).second )
            ans = ans + x;
    }
    return ans;
}

// update inf with INT64_MAX if you need long integers
// do v = number of nodes
// add edges to the graph
// obtain (cost, flow) with get(source, sink)