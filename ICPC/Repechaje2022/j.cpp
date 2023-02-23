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
typedef pair<ll,ll> pll;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 300005;
int n, degree[maxN], ancestor[maxN];
ll b[maxN], resp;
vector<int> adj[maxN];
vector<pll> value_sons[maxN];

ll process_nodes(){
    stack<int> to_process;
    //the root is zero and is not included here
    loop(i, 1, n){
        if(degree[i] == 1)
            to_process.push(i);
    }

    int node, fa, out_degree, size;
    ll sum, maxi, with, without;
    while(!to_process.empty()){
        node = to_process.top();
        to_process.pop();
        //update ancestor's degree
        fa = ancestor[node];
        if(node != 0){
            --degree[fa];
            if(fa==0){
                if(degree[fa]==0)
                    to_process.push(fa);
            }
            else{
                if(degree[fa] == 1)
                    to_process.push(fa);
            }
        }

        //if it is a leaf
        if(value_sons[node].empty()){
            value_sons[fa].push_back(pll(b[1]-b[0], b[0]));
            continue;
        }

        //not a leaf
        sort(value_sons[node].begin(), value_sons[node].end());
        size = value_sons[node].size();

        //compute without 
        out_degree = size;
        sum = 0;
            //intialize sum
        loop(i, 0, size){
            sum += value_sons[node][i].second;
        }
        maxi = b[out_degree] + sum;

        iloop(i, size-1, -1){
            --out_degree;
            sum += value_sons[node][i].first;
            maxi = max(maxi, b[out_degree] + sum);
        }
        without = maxi;

        //compute with
        out_degree = 1;
        //cout<<"suma "<<sum<<endl;
            maxi = b[out_degree] + sum;
        loop(i, 0, size){
            ++out_degree;
            sum -= value_sons[node][i].first;
            maxi = max(maxi, b[out_degree] + sum);
        }
        with = maxi;
        if(node == 0){
            resp = without;
        }
        else{
            //cout<<"node "<<node<<" "<<without<<" "<<with<<endl;
            value_sons[fa].push_back(pll(with - without, without));
        }
    }
    return resp;    
}

void dfs_assign_parents(int v, int fa){
    ancestor[v] = fa;
    for(int son : adj[v]){
        if(son == fa) continue;
        dfs_assign_parents(son, v);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    cin>>n;
    loop(i, 0, n)
        cin>>b[i];

    for(int i =0, a, b; i < n-1; ++i){
        cin>>a>>b;
        --a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++degree[a]; ++degree[b];
    }

    dfs_assign_parents(0, 0);

    cout<<process_nodes()<<"\n";
    return 0;
}