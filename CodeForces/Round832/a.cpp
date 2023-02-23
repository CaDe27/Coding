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

const int maxN = 500005;
int n, a[maxN];

void solve(){
    cin>>n;
    
    ll pos = 0, negs = 0, b;
    loop(i, 0, n){
        cin>>b;
        if( b < 0)
            negs += -b;
        else
            pos += b;
    }
    cout<<max(pos - negs, negs - pos)<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
        //cout<<solve<<"\n";
    }

    return 0;
}