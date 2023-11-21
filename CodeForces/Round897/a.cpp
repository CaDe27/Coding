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
pii a[maxN];
int resp[maxN];
void solve(){
    cin>>n;
    loop(i, 0, n){
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a, a+n);
    
    for(int i = n-1; i>=0; --i){
        resp[a[i].second] = n-1-i+1; 
    }
    loop(i, 0, n){
        cout<<resp[i]<<" \n"[i==n-1];
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