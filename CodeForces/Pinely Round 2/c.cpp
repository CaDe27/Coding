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
ll n, k;
int a[maxN];
void solve(){
    cin>>n>>k;
    ll suma = n*(n+1)/2;
    loop(i, 0, n){
        cin>>a[i];
        suma -= a[i];
    }
    a[n] = suma;
    k %= (n+1);
    if(k == 0)
        k = n+1;

    int indx = n+1 - k;
    loop(i, 0, n){
        cout<<a[(indx+i)%(n+1)]<<(i < n-1? " ":"\n");
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