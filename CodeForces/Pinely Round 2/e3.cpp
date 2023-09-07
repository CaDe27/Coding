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
typedef pair<int, int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 200005;
int n, m, k;
ll h[maxN];
ll finish[maxN];
ll resp, upper, lower;

vector<int> unlock[maxN];
vector<pii> starters;
stack<int> ready;
int dependencies[maxN];

void clean(){
    loop(i, 0, n){
        unlock[i].clear();
        dependencies[i] = 0;
        finish[i] = 0;
    }
    while(!ready.empty())
        ready.pop();
    starters.clear();
}

void update(int v){
    finish[v] += k;
    upper = max(upper, finish[v]);

    for(int u:unlock[v]){
        if(finish[v] > finish[u])
            update(u);
    }
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
            finish[i] = h[i];
            starters.push_back(pii(h[i], i));
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
                finish[u] = max(finish[u], finish[v] + (h[u]-h[v]));
            }
            else{
                finish[u] = max(finish[u], finish[v] + k - (h[v]-h[u]) );
            }
        }
    }
    
    upper = finish[0];
    loop(i, 1, n)
        upper = max(upper, finish[i]);
    
    sort(starters.begin(), starters.end());
    lower = starters[0].first;
    resp = upper - lower;
    int it = 1, itLast = 0;
    while(it < starters.size()){
        while(it < starters.size() 
        && starters[it].first == starters[it-1].first)
            ++it;
        if(it == starters.size())
            break;

        lower = starters[it].first;
        loop(i, itLast, it)
            update(starters[i].second);
        
        resp = min(resp, upper-lower);
        itLast = it;
        ++it;
    }
    cout<<resp<<"\n";
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