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
int n, arre[maxN];

void solve(){
    cin>>n;
    int maxi = 0;
    loop(i, 0, n) {
        cin>>arre[i];
        if(arre[maxi] < arre[i]){
            maxi = i;
        }
    }
    swap(arre[maxi], arre[0]);
    sort(arre+1, arre + n);
    if(n > 1 && arre[0] == arre[1]){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        loop(i, 0, n)
            cout<<arre[i]<<(i==n-1? "\n" : " ");
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