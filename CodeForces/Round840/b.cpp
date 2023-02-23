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
int n, k;

multiset<int> powers;
pair<ll, ll> arre[maxN];
void solve(){
    powers.clear();
    
    cin>>n>>k;
    loop(i, 0, n){
        cin>>arre[i].first;
    }
    loop(i, 0, n){
        cin>>arre[i].second;
        powers.insert(arre[i].second);
    }

    sort(arre, arre+n);
    int it = 0;
    ll acum = k;
    multiset<int>::iterator dir;
    while( it  < n && k > 0 ){
        while(it < n && arre[it].first <= acum){
            powers.erase(powers.find(arre[it].second));
            ++it;
        }
        if( it < n ){
            k -= *powers.begin();
            acum += k;
        }
    }
    if(it == n)
        cout<<"YES\n";
    else 
        cout<<"NO\n";
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