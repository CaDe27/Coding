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

const int maxN = 105, maxP = 101;
int n;
ll a[maxN];

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


int residuos[100];
void solve(){
    cin>>n;
    loop(i, 0, n){
        cin>>a[i];
    }

    loop(i, 0, n)
    loop(j, i+1, n){
        if(a[i] == a[j]){
            cout<<"NO\n";
            return;
        }
    }

    for(int p : prime){
        fill(residuos, residuos + p, 0);
        loop(i, 0, n)
        loop(j, i+1, n){
            if( (a[j]-a[i])%p == 0 ){
                residuos[ a[i]%p ] = 1;
                residuos[ a[j]%p ] = 1;
            }
        }
        
        bool flag = false;
        loop(i, 0, p){
            if(residuos[i] == 0)
                flag = true;
        }
        if(!flag){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

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
