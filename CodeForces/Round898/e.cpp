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
int a[maxN], n, x;

ll waterNeeded(int h){
    ll resp = 0;
    loop(i, 0, n)
        resp += max(0, h-a[i]);
    return resp;

}

void solve(){
    cin>>n>>x;
    loop(i, 0, n)
        cin>>a[i];
    
    int ini = 1, fin = 2e9+1, mid;
    while(ini != fin){
        mid = ( ((ll)ini) + fin + 1)/2;
        if(waterNeeded(mid) > x)
            fin = mid-1;
        else
            ini = mid;
    }
    cout<<ini<<"\n";
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