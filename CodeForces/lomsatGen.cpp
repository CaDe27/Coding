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

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)

const int maxN = 100005;
int n;

void swap(int a, int b){
	int aux;
	aux = a;
	a = b;
	b = aux;
}

vi adj[maxN];
int papa[maxN];
bool visited[maxN];
int level[maxN];
int color[maxN];
ll sumColor[maxN]; 
ll actual[maxN];
ll maxi;

typedef map<int,ll> mapii;
void merge(mapii* &bucket, mapii* &aux){
    if( (*bucket).size() < (*aux).size() ){
        mapii* t = bucket;
        bucket = aux;
        aux = t;
    }

    for(auto a : *aux){
        if(a.first < 0) continue;
    
        (*bucket)[a.first] += a.second;
        
        if((*bucket)[a.first] == (*bucket)[-1])
            (*bucket)[-2] += a.first;

        else if((*bucket)[a.first] > (*bucket)[-1])
        {
            (*bucket)[-1] = (*bucket)[a.first];
            (*bucket)[-2] = a.first;
        }
    }

}

mapii* dfs(int f, int nd){
    mapii* bucket = new map<int,ll>();
    (*bucket)[color[nd]] = 1;
    (*bucket)[-1] = 1;
    (*bucket)[-2] = color[nd];

    for(int son : adj[nd]){
        if(son == f) continue;
        mapii* aux = dfs(nd, son);
        merge(bucket, aux);
    }
    sumColor[nd] = (*bucket)[-2];
    return bucket;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    loopi(i, 1, n)
        cin>>color[i];
    
    loop(i, 0, n-1){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, 1);
    loopi(i, 1, n)
        cout<<sumColor[i]<<" ";
    cout<<"\n";
}
