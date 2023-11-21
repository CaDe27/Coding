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
#define MOD 998244353
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define sum(a, b) (((a) + (b))%MOD)
using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;


const int maxN = 100005;

vector<pii>  adj[maxN];
vector<int> reverseGraph[maxN];
int n;
int parentCountReverse[maxN];
stack<int> topoQueue;
vector<int> topologicalSort;

ll a[maxN], b[maxN], y[maxN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    int n; cin>>n;
    loop(i, 0, n){
        int m; cin>>m;
        int l, w;
        loop(j, 0, m){
            cin>>l>>w;
            --l;
            adj[i].push_back(pii(l, w));
            reverseGraph[l].push_back(i);
            ++parentCountReverse[i];
        }
    }

    loop(i, 0, n)
        if(parentCountReverse[i] == 0)
        	topoQueue.push(i);
    
    while(!topoQueue.empty()){
        int node = topoQueue.top();
        topoQueue.pop();

        topologicalSort.push_back(node);
        for(int son : reverseGraph[node]){
            --parentCountReverse[son];
            if(parentCountReverse[son] == 0)
                topoQueue.push(son);
        }
    }

    for(int i = 0; i < n; ++i){
        int v = topologicalSort[i];  
        for(int j = 0; j < adj[v].size(); ++j){
            int son = adj[v][j].first;
            if(adj[v][j].second == 0){
                a[v] = sum(a[v], 1);
                b[v] = sum(b[v], y[v]);
            }
            else
                y[v] = sum(y[v], 1);

            a[v] = sum(a[v], a[son]);
            b[v] = sum(b[v], sum(b[son], a[son]*y[v]));
            y[v] = sum(y[v], y[son]);
        }
    }

    cout<<b[0]<<"\n";
    return 0;
}