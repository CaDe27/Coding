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
const int maxN = 500005;
int n; 
int c[maxN], k, resp[maxN];
vector<int> imp;

void solve(){
    imp.clear();
    fill(resp, resp+n, 0);

    cin>>n;
    loop(i, 0, n) cin>>c[i];
    cin>>k;
    
    int mini = 1e9+1;
    for(int i = n-1; i >= 0; --i){
        if(c[i] < mini){
            imp.push_back(i);
            mini = c[i];
        }
    }
    
    reverse(imp.begin(), imp.end());

    resp[imp[0]] = k/c[imp[0]];
    k%=c[imp[0]];
    for(int i = 1; i < imp.size(); ++i){
        int quito = min(resp[imp[i-1]], k/(c[imp[i]]-c[imp[i-1]]));
        resp[imp[i-1]] -= quito;
        resp[imp[i]] += quito;
        k -= quito*(c[imp[i]]-c[imp[i-1]]);
    }

    for(int i = n-2; i>=0; --i)
        resp[i] += resp[i+1];

    loop(i, 0, n)
        cout<<resp[i]<<" \n"[i==n-1];    
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