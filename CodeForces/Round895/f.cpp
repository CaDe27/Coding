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

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 100005;
int n;
int a[maxN];
ll c[maxN];
int ofMe[maxN];
bool visited[maxN];
stack<int> none;
vector<int> resp;

void procesa(int ini){
    int it = a[ini], mini = ini;
    visited[ini] = true;
    while(it != ini){
        if(c[it] < c[mini])
            mini = it;
        visited[it] = true;
        it = a[it];
    }   
    
    it = a[mini];
    while(it != mini){
        resp.push_back(it);
        it = a[it];
    }
    resp.push_back(mini);
}

void solve(){
    while(!none.empty()) none.pop();
    fill(ofMe, ofMe + n, 0);
    fill(visited, visited+n, 0);
    resp.clear();

    cin>>n;
    loop(i, 0, n) {cin>>a[i]; --a[i];}
    loop(i, 0, n) cin>>c[i];
    

    loop(i, 0, n){
        ++ofMe[a[i]];
    }

    loop(i, 0, n)
        if(ofMe[i] == 0)
            none.push(i);

    while(!none.empty()){
        int v = none.top();
        none.pop();
        resp.push_back(v);
        visited[v] = true;

        --ofMe[a[v]];

        if(ofMe[a[v]] == 0)
            none.push(a[v]);
    }

    //only cycles left
    loop(i, 0, n){
        if(!visited[i]){
            procesa(i);
        }
    }
    loop(i, 0, resp.size()){
        cout<<(resp[i]+1)<<" \n"[i==resp.size()-1];
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