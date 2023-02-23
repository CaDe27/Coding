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

typedef pair<int,ll> pill;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;

void solve(){
    int n; cin>>n;
    int a[n], b[n];
    loop(i, 0, n)
        cin>>a[i];
    loop(i, 0, n)
        cin>>b[i];
    int maxDist=0;
    for(int i = 0; i < n; ++i){
        int minDist = abs(a[i] - b[0]);
        for(int j = 1; j < n; ++j){
            minDist = min(abs(a[i]-b[j]), minDist);
        }
        maxDist = max(maxDist, minDist);
    }
    cout<<maxDist<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
