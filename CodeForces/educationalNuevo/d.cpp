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

const int maxN = 2*100005;
int n, x, nuevaN;
ll a[maxN];


void solve(){
    cin>>n>>x;
    loop(i, 0, n){
        cin>>a[i];
    }
    ll diff = 0;
    ll mini=a[0], maxi = a[0];
    loop(i, 1, n){
        mini = min(a[i], mini);
        maxi = max(a[i], maxi);
        diff += abs(a[i]-a[i-1]);
    }
    ll agrega;
    if(1 < mini){
        agrega = min(a[0] -1,a[n-1]-1);
        agrega = min(agrega, 2*mini - 2);
        diff += agrega;
    }   
    if(x > maxi){
        agrega = min(x-a[0],x-a[n-1]);
        agrega = min(agrega, 2*x - 2*maxi);
        diff += agrega;
    }
    cout<<diff<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
