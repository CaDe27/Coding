//need number of scc
//minimum prize in each scc and total of junctions that have that prize
// money = sum of minimums; number f ways = Product of total that have minimum per scc 
//https://codeforces.com/problemset/problem/427/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define loop(i, a, b) for(int i = a; i < b; ++i)
#define MOD 1000000007
#define endl '\n'
using namespace std;
typedef int64_t ll;

const int maxN = 100000;
ll minPrize, prize, totalWays;
int totalMinScc;
ll cost[maxN];

void dfs(int v,vector<int> adj[], bool visited[], stack<int> &next){
    visited[v] = true;
    for(int son: adj[v])
        if(!visited[son])
            dfs(son, adj, visited, next);
    next.push(v);
}

void dfs(int v,vector<int> transpose[], bool visited[]){
    visited[v] = true;
    if(cost[v] < minPrize){
        minPrize = cost[v];
        totalMinScc = 1;
    }
    else if(cost[v] == minPrize)
        ++totalMinScc;

    for(int son: transpose[v])
        if(!visited[son])
            dfs(son, transpose, visited);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> adj[n], transpose[n];
    loop(i, 0, n) cin>>cost[i];

    int m; cin>>m;
    loop(i, 0, m){
        int a, b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        transpose[b-1].push_back(a-1);
    }

    stack<int> next;
    bool visited[n];
    fill(visited, visited+n, false);
    for(int i = 0; i < n; ++i){
        if(!visited[i])
            dfs(i, adj, visited, next);
    }

    fill(visited, visited+n, false);
    prize = 0;
    totalWays = 1;
    while(!next.empty()){
        int aux = next.top(); next.pop();
        if(!visited[aux]){
            minPrize = 1000000000;
            totalMinScc = 0;
            dfs(aux, transpose, visited);
            prize += minPrize;
            totalWays = (totalMinScc*totalWays)%MOD;
        }
    }

    cout<<prize<<" "<<totalWays<<endl;


}