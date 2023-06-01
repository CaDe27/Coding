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

const int maxN = 3e5+5;
ll n;
int a[maxN]; 
ll x[maxN], y[maxN], z[maxN];
stack<pii> decreasing, ready, notReady;

void computeNextandLastBigger(){
    fill(y, y+n, -1);
    fill(x, x+n, -1);
    
    while(!decreasing.empty())
        decreasing.pop();

    loop(i, 0, n){
        while(!decreasing.empty() && a[i] > decreasing.top().second){
            y[decreasing.top().first] = i;
            decreasing.pop();
        }
        if(!decreasing.empty()){
            x[i] = decreasing.top().first;
        }
        decreasing.push(pii(i, a[i]));
    }   
}

void computeNextLowerAfterBigger(){
    fill(z, z+n, n);

    while(!ready.empty())
        ready.pop();

    while(!notReady.empty())
        notReady.pop();
    
    loop(i, 0, n){
        //ready is always decreasing
        //not ready is always increasing
        while(!ready.empty() && a[i] < ready.top().second){
            z[ready.top().first] = i;
            ready.pop();
        }

        while(!notReady.empty() && a[i] > notReady.top().second){
            ready.push(notReady.top());
            notReady.pop();
        }

        notReady.push(pii(i, a[i]));
    }
}

void solve(){
    cin>>n;
    loop(i, 0, n) cin>>a[i];
    
    ll resp = (n-1)*n*(n+1)/6;
    computeNextandLastBigger();
    computeNextLowerAfterBigger();

    loop(i, 0, n){
        if(y[i] != -1)
            resp -= (i-x[i])*(z[i]-y[i]);
    }
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