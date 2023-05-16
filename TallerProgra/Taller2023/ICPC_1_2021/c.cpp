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

const int maxN = 100005, maxP = 1e6+1;
int n;
vector<ll> prime;
bool primo[maxP];
int acum[maxP];

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


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    sieve();
    acum[0] = 0;
    for(int i = 0; i < maxP; ++i){
        acum[i] = acum[i-1] + primo[i];
    }

    int t; cin>>t;
    int a, b;
    loop(i, 0, t){
        cin>>a>>b;
        cout<<acum[b] - acum[a-1]<<"\n";
    }
    return 0;
}