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
typedef pair<ll, int> pli;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 200005;
int n, m, k;
ll h[maxN];
ll delta[maxN];

vector<int> unlock[maxN];
stack<int> ready;
stack<pli> stackResp;
vector<pli> pr;
int dependencies[maxN];

bool contains(pli a, pli b){
    if(a.first < b.first){
        return a.first-delta[a.second] <= b.first - k - delta[b.second];
        
    }
    else{
        return a.first-delta[a.second] <= b.first - delta[b.second];
    }
}

void clean(){
    loop(i, 0, n){
        unlock[i].clear();
        dependencies[i] = 0;
        delta[i] = 0;
    }
    while(!ready.empty())
        ready.pop();
    while(!stackResp.empty())
        stackResp.pop();
    pr.clear();
}

void solve(){
    cin>>n>>m>>k;
    clean();

    loop(i, 0, n)
        cin>>h[i];

    loop(i, 0, m){
        int a, b;
        cin>>a>>b;
        --a;--b;
        unlock[a].push_back(b);
        ++dependencies[b];
    }

    loop(i, 0, n){
        if(dependencies[i] == 0){
            ready.push(i);
        }
    }

    while(!ready.empty()){
        int v = ready.top();
        ready.pop();

        for(int u : unlock[v]){
            --dependencies[u];
            if(dependencies[u] == 0)
                ready.push(u);
            
            if(h[v] <= h[u]){
                delta[u] = max(delta[u], delta[v] + (h[u]-h[v]));
            }
            else{
                delta[u] = max(delta[u], delta[v] + k - (h[v]-h[u]) );
            }
        }
    }

    loop(i, 0, n){
        if(unlock[i].empty())
            pr.push_back(pli(h[i], i));
    }
    sort(pr.begin(), pr.end());
    stackResp.push(pr[pr.size()-1]);
    for(int i = pr.size()-2; i >= 0; --i){
        while(!stackResp.empty() && contains(pr[i], stackResp.top())){
            stackResp.pop();
        }
        if(!stackResp.empty() && contains(stackResp.top(), pr[i])){
            continue;
        }
        stackResp.push(pr[i]);
    }

    if(stackResp.size() == 1){
        cout<<delta[stackResp.top().second]<<"\n";
    }
    else{
        pr.resize(stackResp.size());
        while(!stackResp.empty()){
            pr.push_back(stackResp.top());
            stackResp.pop();
        }
        int size = pr.size();
        ll resp = delta[pr[0].second] + (pr[size-1].first - pr[0].first);
        for(int i = size-2; i >= 0; --i){
            resp = min(resp, delta[pr[i+1].second] + k - (pr[i+1].first-pr[i].first));
        }
        cout<<resp<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}