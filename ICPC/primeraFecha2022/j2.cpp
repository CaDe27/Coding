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

#define INF 1000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

int n;

// ============= BIPARTITE MATCHING CODE 
const int MAXE = 200005, MAXV = 20005;
int s, t;
struct edge {
	int node, next, cap, flow;
    edge(){
        node = next = cap = flow = 0;
    }
    edge(int node_, int next_, int cap_, int flow_){
        node = node_;
        next = next_;
        cap = cap_; 
        flow = flow_;
    }
};

edge g[MAXE*2];
int start[MAXV], nextEdge; // init start to 0s and nextEdge to 2

void addEdge(int a, int b, int c){
	g[nextEdge] = edge(b, start[a], c, 0);
	start[a] = nextEdge++;
	g[nextEdge] = edge(a, start[b], 0, 0);
	start[b] = nextEdge++;
}

// s->source, t->sink, n->total no. nodes
int maxFlow(){
	int tot = 0;
	static int q[MAXV], z[MAXV], d[MAXV], p[MAXV], qs, qe, curr;

	while (true){
		fill(d, d + n, MAXV);
		d[s] = qs = qe = 0;
		q[qe++] = s;

		while (qs < qe){
			curr = q[qs++];
			z[curr] = start[curr];
			if (d[curr] == d[t]) continue;
			for (int i = start[curr]; i; i = g[i].next)
				if (g[i].cap - g[i].flow > 0 &&
				    d[g[i].node] > d[curr] + 1){
					d[g[i].node] = d[curr] + 1;
					q[qe++] = g[i].node;
				}
		}

		if (d[t] == MAXV) return tot;

		curr = s;
		while (true){
			while (z[curr] && (g[z[curr]].cap - g[z[curr]].flow <= 0 ||
			       d[g[z[curr]].node] != d[curr] + 1))
				z[curr] = g[z[curr]].next;

			if (!z[curr]){
				if (curr == s) break;
				curr = g[p[d[curr]-1]^1].node;
				d[g[p[d[curr]]].node] = -INF;
				continue;
			}

			p[d[curr]] = z[curr];
			curr = g[z[curr]].node;

			if (curr == t){
				int m = INF;
				for (int i = 0; i < d[t]; i++)
					m = min(m, g[p[i]].cap - g[p[i]].flow);
				for (int i = 0; i < d[t]; i++){
					g[p[i]].flow += m;
					g[p[i]^1].flow -= m;
				}
				tot += m;
				curr = s;
			}
		}
	}
}

// ============= END OF BIPARTITE MATCHING CODE 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    nextEdge = 2;
    int m;

    cin>>n>>m;
    s = 0;
    t = n + m + 1;
    loop(i, 1, n+1)
        addEdge(s, i, 1);
    loop(i, 1, m+1)
        addEdge(n+i, t, 1);

    int k, c;
    loop(i, 1, n+1){
        cin>>k;
        loop(j, 0, k){
            cin>>c;
            addEdge(i, n+c, 1);
        }
    }
    n = n + m + 2;
    int maxBipartiteMatching = maxFlow();
    cout<<m - maxBipartiteMatching<<"\n";
    return 0;
}