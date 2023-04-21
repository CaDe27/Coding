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

const int maxN = 2e5+5;
int n;
pii arre[maxN];
int resp[maxN];
void solve(){
    cin>>n;
    loop(i, 0, n-1){
        cin>>arre[i].first;
        arre[i].second = i;
    }
    
    sort(arre, arre+ n-1);
    fill(resp, resp + n, -1);

    int indx;
    loop(i, 0, n-1){
        indx = arre[i].second;
        if(resp[ indx ] == -1)
            resp[indx] = arre[i].first;
        if(resp[indx+1] == -1)
            resp[indx+1] = arre[i].first;
    }
    loop(i, 0, n)
        cout<<resp[i]<<(i<n-1? " " : "\n");
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