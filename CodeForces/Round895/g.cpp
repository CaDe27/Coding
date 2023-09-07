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
typedef pair<ll,ll> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 200005;
ll n;

ll a[maxN], ac[maxN], sac[maxN];
vector<int> di;

ll val(pii v){
    if(v.first == 0)
        return ac[v.second] - sac[v.second];
    else    
        return ac[v.second]/ac[v.first-1] - (sac[v.second]-sac[v.first-1]);
}

void solve(){
    cin>>n;
    loop(i, 0, n)
        cin>>a[i];
    int it1 = 0, it2 = n-1;
    while(it1 < n && a[it1] == 1)
        ++it1;
    
    while(it2 >= 0 && a[it2] == 1)
        --it2;
    
    if(it1 == n || it1 == it2){
        cout<<"1 1\n";
        return;
    }

    di.clear();
    loop(i, it1, it2+1){
        if(a[i] != 1)
            di.push_back(i);
    }

    if(di.size() > 50){
        cout<<(it1+1)<<" "<<(it2+1)<<"\n";
        return;
    }

    ll mul = 1;
    for(int i = it1; i <= it2; ++i){
        ll nec = 100000000000LL/mul;
        if( a[i] >= nec){
            cout<<(it1+1)<<" "<<(it2+1)<<"\n";
            return;
        }
        mul *= a[i];
    }

    sac[0] = a[0];
    loop(i, 1, n)
        sac[i] = sac[i-1] + a[i];

    ac[0] = a[0];
    loop(i, 1, n)
        ac[i] = ac[i-1]*a[i];
    
    pii maxi = pii(it1,it2);
    for(int i = 0; i < di.size(); ++i){
    for(int j = i+1; j < di.size(); ++j){
        if(val(maxi) < val(pii(di[i], di[j])))
            maxi = pii(di[i], di[j]);
    }
    }

    if(val(maxi) > 0){
        cout<<(maxi.first+1)<<" "<<(maxi.second+1)<<endl;
    }
    else{
        cout<<"1 1\n";
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