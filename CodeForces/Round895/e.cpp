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

ll a[maxN], acum[maxN];
string s;

ll xorRange(int l, int r){
    if(l == 0)
        return acum[r];
    else
        return acum[r]^acum[l-1];
}

vector<ll> resps;
void solve(){
    resps.clear();
    cin>>n;
    loop(i, 0, n)
        cin>>a[i];
    cin>>s;

    ll ceros = 0, ones = 0;
    loop(i, 0, n){
        if(s[i] == '0')
            ceros ^= a[i];
        else
            ones ^= a[i];
    }
    acum[0] = a[0];
    loop(i, 1, n){
        acum[i] = acum[i-1]^a[i];
    }


    int q, t, l, r, g;
    cin>>q;
    loop(i, 0, q){
        cin>>t;
        if(t == 1){
            cin>>l>>r;
            --l;--r;
            ceros ^= xorRange(l, r);
            ones ^= xorRange(l, r);
        }
        else{
            cin>>g;
            resps.push_back(g == 0? ceros : ones);
        }
    }

    loop(i, 0, resps.size()){
        cout<<resps[i]<<" \n"[i==resps.size()-1];
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