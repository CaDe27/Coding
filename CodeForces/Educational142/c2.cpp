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

const int maxN = 200005;
int n, indx[maxN];

void solve(){
    cin>>n;
    int v;
    loop(i, 0, n){
        cin>>v;
        indx[v] = i;
    }
    int l, r, resp; 
    l = (n+1)/2; 
    r = (n+2)/2;
    
    while(l > 0 && (l==r || (indx[l] < indx[l+1] && indx[r-1] < indx[r]))){
        --l;
        ++r;
    }
    
    resp = ( n - r + 1 + l)/2;
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