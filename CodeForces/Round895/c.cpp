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
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define maxP 3170

vector<ll> prime;
bool primo[maxP];

void sieve () {
    fill (primo, primo + maxP, true);
    primo[0] = primo[1] = false;
    for (int i = 2; i < maxP; ++i) {
        if (primo[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] < maxP; ++j) {
            primo[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}




const int maxN = 100005;
int n;

void solve(){
    int l, r;
    bool resp = false;
    cin>>l>>r;
    if(r<=3){
        cout<<-1<<"\n";
        return;
    }
    else if(r != l){
        if(r&1)
            --r;
        cout<<2<<" "<<r-2<<"\n";
    }
    else{

        for(ll i = 2; i*i <= r && !resp; ++i){
            if( (r % i) == 0){
                resp = true;
                cout<<i<<" "<<r-i<<"\n";
            }
        }
        if(!resp){
            cout<<-1<<"\n";
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    sieve();
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}