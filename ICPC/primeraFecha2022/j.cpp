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

#define NIL 0
using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 100005;
int n, m, A, B;


// ============= BIPARTITE MATCHING CODE 
// Hopcroft Karp BPM
// O(E sqrt V) near-linear in random graphs
// define variables A and B equal to the cardinality of both sets.
#define MAXN 100100 
vector<int> graph[MAXN];
int dist[MAXN], match[MAXN];

bool bfs(){ 
	queue<int> q ;
	for(int i = 1; i <= n; i++){ 
		if(!match[i]){
			dist[i] = 0; q.push(i);
		}
		else
			dist[i] = 1<<30;
	}

	dist [0] = 1<<30; 
	while(!q.empty()){
		int u = q.front(); q.pop(); if(u){
			for(auto v : graph[u])
			if(dist[match[v]] == 1<<30){
				dist[match[v]] = dist[u]+1; q.push(match[v]) ;
			}
		}
	}
	return dist[0] != 1<<30; 
}


bool dfs(int u){ 
	if (u){
		for(auto v : graph[u]){ 
			if(dist[match[v]] == dist[u]+1){
				if(dfs(match[v])){
					match[v] = u; 
					match[u] = v; 
					return 1;
				}
			}
		}
		dist[u] = 1<<30;	
		return 0;
	}
	return 1; 
}

//
int hopcroftKarp(){
	int ans = 0;
	fill(match , match + maxN, 0); 
	while(bfs())
	for(int i = 1; i <= n; i++) 
		if(!match[i] && dfs(i))
			ans++; 
	return ans ;
}

// ============= END OF BIPARTITE MATCHING CODE 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>m;

    int k, c;
    loop(i, 1, n+1){
        cin>>k;
        loop(j, 0, k){
            cin>>c;
            graph[i].push_back(n+c);
        }
    }
    int resp = hopcroftKarp();
    cout<<m - resp<<"\n";
    return 0;
}