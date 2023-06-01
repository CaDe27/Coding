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

const int maxN = 1e5+5;
int n,q, root;
int success[maxN], resp[maxN], nodesSubtree[maxN];
vector<int> adj[maxN];
vector<pii> bonuses[maxN];

ll fenwick[maxN];
void update(int pos, ll x){
    while(pos < maxN){
        fenwick[pos] += x;
        pos += pos&(-pos);
    }
}

ll query(int pos){
    ll resp = 0;
    while(pos > 0){
        resp += fenwick[pos];
        pos -= pos&(-pos);
    }
    return resp;
}

void dfsNodeSubtree(int v, int ancestor){
    nodesSubtree[v] = 1;
    for(int son : adj[v]){
        if(son == ancestor)
            continue;
        dfsNodeSubtree(son, v);
        nodesSubtree[v] += nodesSubtree[son];
    }
}

//uses binary search
int computeResp(int person){
    int left, right, mid;
    if(query(q) < success[person])
        return -1;
    
    left = 1;
    right = q;

    while(left != right){
        mid = (left + right)/2;
        if(query(mid) >= success[person])
            right = mid;
        else
            left = mid+1;  
    }
    return left;
}

void dfsResp(int v, int ancestor){
    //include this node's bonuses
    for(pii bonus : bonuses[v]){
        update(bonus.first, bonus.second/nodesSubtree[v] + bonus.second%nodesSubtree[v]);
    }
    
    //compute resp for this node
    resp[v] = computeResp(v);

    //take the exceeding bonus only for this person
    for(pii bonus : bonuses[v]){
        update(bonus.first, -(bonus.second%nodesSubtree[v]));
    }

    //dfs to compute sons's answer
    for(int son : adj[v]){
        if(son == ancestor) continue;
        dfsResp(son, v);
    }

    for(pii bonus : bonuses[v]){
        update(bonus.first, -(bonus.second/nodesSubtree[v]));
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n>>q;
    loop(i, 1, n+1)
        cin>>success[i];

    bool isSubordinate[n+1];
    fill(isSubordinate+1, isSubordinate + n+1, 0);
    loop(i, 0, n-1){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        isSubordinate[b] = true;
    }
    
    //we compute the root of the tree
    
    loop(i, 1, n+1){
        if(!isSubordinate[i])
            root = i;
    }

    loop(i, 0, q){
        int x,b;
        cin>>x>>b;
        bonuses[x].push_back(pii(i+1, b));
    }

    dfsNodeSubtree(root, 0);
    dfsResp(root, 0);  

    loop(i, 1, n+1)
        cout<<resp[i]<<"\n";
    
    return 0;
}