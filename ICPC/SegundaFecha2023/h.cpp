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

const int maxN = 1000005;
int n, root;

vector<int> adj[maxN];
int activesPerGroup[maxN];
int group[maxN], resp[maxN];
int activeGroups = 0;
void dfs(int v){
    ++activesPerGroup[group[v]];
    if(activesPerGroup[group[v]] == 1){
        ++activeGroups;
    }
    resp[v] = activeGroups;
    for(int son : adj[v]){
        dfs(son);
    }
    
    --activesPerGroup[group[v]];
    if(activesPerGroup[group[v]] == 0){
        --activeGroups;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n;
    int aux;
    for(int i = 1; i <= n; i++){
        cin>>aux;
        if(aux != 0){
            adj[aux].push_back(i);
        }
        else
            root = i;
    }

    for(int i = 1; i <= n; i++){
        cin>>group[i];
    }

    dfs(root);
    for(int i = 1; i < n; i++){
        cout<<resp[i]<<" ";
    }
    cout<<resp[n]<<"\n";

    return 0;
}