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
#define INF 1000000000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;


const int maxN = 2e5+5;
int n;
vector<int> sons[maxN];

int f(int v){
    if(sons[v].size() == 0)
        return 1;
    else if(sons[v].size() == 1)
        return f(sons[v][0]);
    else{
        priority_queue<int, vector<int>, greater<int> > minHeap;
        for(int son : sons[v]){
            minHeap.push(f(son));
            //cout<<"al de "<<v<<" inserto "<<minHeap.top()<<endl;
            if(minHeap.size() > 2)
                minHeap.pop();
        }
        int notMax = minHeap.top();
        minHeap.pop();
        int maxElement = minHeap.top();
        return max(maxElement, notMax+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    int T; cin>>T;
    while(T--){
        cin>>n;
        loop(i, 0, n+1)
            sons[i].clear();
        int a; cin>>a;
        loop(i, 2, n+1){
            cin>>a;
            sons[a].push_back(i);
        }
        cout<<f(1)<<"\n";
    }

    return 0;
}