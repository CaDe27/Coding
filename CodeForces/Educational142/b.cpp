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
ll a[5];

void solve(){
    loop(i, 0, 4) cin>>a[i];
    if(a[0] == 0){
        cout<<1<<"\n";
        return;
    }
    if(a[2] < a[1]) swap(a[2], a[1]);
    ll resp = a[0] + (a[1]<<1);
    a[2] -= a[1];
    resp += min(a[2] + a[3], a[0] + 1); 
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