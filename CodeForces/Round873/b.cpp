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

const int maxN = 2e5+5;
int n;
int arre[maxN];
bool v[maxN];

int gcd(int a, int b){
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}

int recorre(int x){
    int pos = x;
    int resp = 0;
    while(!v[pos]){
        v[pos] = true;
        resp = gcd(resp, abs(arre[pos] - pos));

        pos = arre[pos];
    }
    return resp;
}

void solve(){
    cin>>n;
    fill(v+1, v+n+1, false);
    
    loop(i, 1, n+1){
        cin>>arre[i];
    }

    int resp = 0;
    for(int i = 1; i <= n; ++i){
        if(v[i])
            continue;
        resp = gcd(resp, recorre(i));
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