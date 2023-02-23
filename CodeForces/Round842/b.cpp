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
int n, k;
pii p[maxN];

void solve(){
    cin>>n>>k;
    int v;
    loop(i, 0, n){
        cin>>v;
        p[i] = pii(v, i);
    }
    sort(p, p+n);
    int i = 1;
    while(i < n && p[i].second > p[i-1].second) 
        ++i;
    int remove = n-i, ops = remove/k;
        if(remove%k == 0){
            cout<<ops<<"\n";
        }
        else{
            cout<<(ops + 1)<<"\n";
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