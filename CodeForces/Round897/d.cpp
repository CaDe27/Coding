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
const int maxN = 200005;

bool visited[maxN];
int n, k, a[maxN], indx[maxN], cycleS[maxN];

bool possibleFrom(int v){
    int it = v, currIndx = 0;
    while(!visited[it]){
        visited[it] = true;
        indx[it] = currIndx;
        it = a[it];
        ++currIndx;
    }
    
    int ini = it;
    if(cycleS[it] == 0){
        cycleS[it] = currIndx - indx[it];
        it = a[it];
        while(it != ini){
            cycleS[it] = cycleS[ini];
            it = a[it];
        }
    }

    int cycleSize = cycleS[ini];
    return k%cycleSize == 0;
}

void solve(){
    cin>>n>>k;
    fill(visited, visited + n + 1, 0);
    fill(cycleS, cycleS + n + 1, 0);
    loop(i, 1, n+1) 
        cin>>a[i];

    if(k == 1){
        loop(i, 1, n+1)
            if(a[i] != i){
                cout<<"NO\n";
                return;
            }
        cout<<"YES\n";
        return;
    }
    loop(i, 1, n+1){
        if(!visited[i]){
            if(!possibleFrom(i)){
                cout<<"NO\n";
                return;
            }            
        }
    }
    cout<<"YES\n";
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