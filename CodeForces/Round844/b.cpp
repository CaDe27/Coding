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
int n;

int arre[maxN];
void solve(){
    cin>>n;
    loop(i, 0, n) cin>>arre[i];
    sort(arre, arre + n);
    int ops = 1;
    if(arre[0] > 0) ++ops;
    loop(i, 1, n){
        if(arre[i-1] <= i-1 && arre[i] >= i+1)
            ++ops;
    }
    cout<<ops<<"\n";
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