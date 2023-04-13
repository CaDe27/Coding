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

const int maxN = 1001;
int n;
vector<int> adj[maxN], inverso[maxN];
int prohibited;

int veces[maxN];
bool visited[maxN];

void dfsInv(int x){
    visited[x] = true;
    ++veces[x];

    for(int v : inverso[x]){
        if(v != prohibited && !visited[v])
            dfsInv(v);
    }
}

bool canLose(int v){
    fill(veces, veces + n, 0);

    fill(visited, visited + n, 0);
    dfsInv(v);

    fill(visited, visited + n, 0);
    dfsInv(adj[v][0]);

    fill(visited, visited + n, 0);
    dfsInv(adj[v][1]);

    loop(i, 0, n){
        if(veces[i] >= 3)
            return true;
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    int a, b;
    loop(i, 0, n){
        cin>>a>>b;
        --a;--b;
        inverso[a].push_back(i);
        inverso[b].push_back(i);
        adj[i].push_back(a);
        adj[i].push_back(b);
    }

    string resp = string(n, 'N');
    loop(i, 0, n){
        prohibited = i;
        if(canLose(i))
            resp[i] = 'Y';
    }

    cout<<resp<<"\n";
    return 0;
}