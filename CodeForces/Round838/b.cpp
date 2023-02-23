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
int n;
ll a[maxN], pot[64];
void solve(){
    cin>>n;
    ll maxi = -1;

    cout<<n<<"\n";
    int it;
    loop(i, 0, n){
        cin>>a[i];
        it= 0;
        while(a[i] > pot[it]){
            ++it;
        }
        cout<<(i+1)<<" "<<pot[it]-a[i]<<"\n";
    }
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;

    pot[0] = 1;
    loop(i, 1, 64)
    {
        pot[i] = pot[i-1]*2;
    }

    while(t--){
        solve();
    }
    return 0;
}