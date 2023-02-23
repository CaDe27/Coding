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

const int maxN = 200005;
int n, arre[maxN];
ll sumTot, sumAcum;

ll gcd(ll a, ll b){
    if(a == 0) return b;
    else return gcd(b%a, a);
}

void solve(){
    cin>>n;
    sumTot = 0;
    ll resp = 0;
    loop(i, 0, n){
        cin>>arre[i];
        sumTot += arre[i];
    }
    sumAcum = 0;
    loop(i, 0, n-1){
        sumAcum += arre[i];
        resp = max(resp, gcd(sumTot, sumTot - sumAcum));
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