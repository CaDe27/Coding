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

#define INF 100000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 101;
int n;

//=======MAX FLOW
const int MAXE = 100*99/2 + 3*maxN + 5, MAXV = 2*maxN+5;
int s, t;
struct edge {
	int node, next, cap, flow;
};

edge g[MAXE*2];
int start[MAXV], nextEdge; // init start to 0s and nextEdge to 2

void addEdge(int a, int b, int c){
    g[nextEdge].node = b;
    g[nextEdge].next = start[a];
    g[nextEdge].cap = c;
    g[nextEdge].flow = 0;
	start[a] = nextEdge++;

    g[nextEdge].node = a;
    g[nextEdge].next = start[b];
    g[nextEdge].cap = 0;
    g[nextEdge].flow = 0;
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
//=======MAX FLOW=======================================

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    nextEdge = 2;

    int initialNodes, starting, ending;
    cin>>initialNodes>>starting>>ending;
    n = 2*initialNodes+2;
    s = 0;
    t = 2*initialNodes + 1;

    int a, b;
    loop(i, 0, starting){
        cin>>a;
        addEdge(s, 2*a-1, 1);
    }
    
    loop(i, 0, ending){
        cin>>a;
        addEdge(2*a, t, 1);
    }

    loop(k, 1, initialNodes+1)
        addEdge(2*k-1, 2*k, 1);
    
    int m;cin>>m;
    loop(i, 0, m){
        cin>>a>>b;
        addEdge(2*a, 2*b-1, 1);
    }

    cout<<maxFlow()<<"\n";
    return 0;
}