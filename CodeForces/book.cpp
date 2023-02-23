//https://codeforces.com/problemset/problem/1572/A
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
#include <sstream>

using namespace std;

typedef int64_t ll;
typedef long double ld;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 200005;
int n;
int before[maxN];
vector<int> adj[maxN];
priority_queue<pii, vector<pii>, greater <pii> > minheap;

void clean(){
    loop(i, 1, n+1)
        adj[i].clear();
    while(!minheap.empty()) minheap.pop();
}


int solve(){
    cin>>n;
    clean();
    int bookBefore;
    loop(i, 1, n+1){
        cin>>before[i];
        loop(j, 0, before[i]){
            cin>>bookBefore;
            adj[bookBefore].push_back(i);
        }
        if(before[i] == 0) 
            minheap.push(pii(1, i));
    }    

    int understood = 0, timesToRead = 1;
    int book;
    while(!minheap.empty()){
        ++understood;
        book = minheap.top().second;
        timesToRead = minheap.top().first;
        minheap.pop();

        for(int son : adj[book]){
            --before[son];
            if(before[son] == 0)
                minheap.push(pii(son > book? timesToRead : timesToRead + 1, son));
        }
    }
    
    return understood == n? timesToRead : -1;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    int t; cin>>t;
    loop(i, 0, t){
        cout<<solve()<<"\n";
    }
    
    
}
