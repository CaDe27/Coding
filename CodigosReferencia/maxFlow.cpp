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
 
using namespace std;
 
typedef int64_t ll;
 
typedef pair<int,ll> pill;
typedef vector<pill> vill;

 
#define INF (120*100000)
#define MOD 1000000007
 
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)

 
 // ==================== MAX FLOW ================
 // Complexity O(V*(E^2))
const int maxV = 105;
int source, sink;
ll capacity[maxV][maxV]; 
vector<int> adj[maxV];      

ll bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pill> q;
    q.push( pill(s, INF) );
 
    while (!q.empty()) {
        int cur = q.front().first;
        ll flow = q.front().second;
        q.pop();
 
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push( pill(next, new_flow) );
            }
        }
    }
 
    return 0;
}
 
ll maxflow(int s, int t) {
    ll flow = 0;

    vector<int> parent(maxV);
    ll new_flow;
 
    while ( (new_flow = bfs(s, t, parent)) ) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
 
    return flow >= INF? -1 : flow;
}
 
void init(){
	cout<<"llena adj list (no dirigida) e inicializa el flujo residual en cada arista"<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	
	source = ;
	sink = ;
    init();
    int resp = maxflow(source,sink);
    cout<<resp<<"\n";
    
}