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
ll n, x, y;

ll gcd(ll a, ll b){
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}

//assumes not zero
ll mcm(ll a, ll b){
    return a*b/gcd(a,b);
}

void solve(){
    cin>>n>>x>>y;
    ll m = mcm(x, y);
    ll c = n/x - n/m;
    ll sumM = c*n - (c-1)*c/2;

    c = n/y - n/m;
    ll summ = c*(c+1)/2;

    cout<<sumM - summ<<"\n";
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