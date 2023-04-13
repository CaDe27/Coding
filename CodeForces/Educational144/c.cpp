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

void solve(){
    ll l, r;
    cin>>l>>r;
    ll uno = 1;
    ll k = 0;
    while( (l*(uno<<k)) <= r){
        ++k;
    }
    --k;
    
    ll ini = l, mid, fin = min(r, 2*l - 1);
    while(ini != fin){
        mid = (ini + fin +1)/2;
        if(mid*(uno<<k) <= r)
            ini = mid;
        else
            fin = mid-1; 
    }
    ll resp = ini - l + 1;

    if(3*l*(uno<<(k-1)) <= r){
        fin = ini;
        ini = l;
        while(ini != fin){
            mid = (ini + fin +1)/2;
            if(mid*3*(uno<<(k-1)) <= r)
                ini = mid;
            else
                fin = mid-1; 
        } 
        resp = (resp + (k*(ini-l+1)%MOD) )%MOD;
    }
    cout<<(k+1)<<" "<<resp<<"\n";
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