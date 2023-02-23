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
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(ll i = a; i < b; ++i)

const int maxP = 1e6+10;
int n, m;

vector<ll> prime;
bool primo[maxP];
map<pii, int> mapeo;

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


void solve(){
    sieve();
    int acum[maxP];
    fill(acum, acum+maxP, 0);
    loop(i, 0, maxP){
        if(primo[i]) acum[i] = 1;
        if(i > 0)acum[i]+=acum[i-1];
    }

    cin>>n;
    int a, b;
    loop(i, 0, n){
        cin>>a>>b;
        cout<<acum[b] - acum[a-1]<<"\n";
    }    
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}