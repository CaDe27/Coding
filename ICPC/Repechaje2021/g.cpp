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

const int maxN = 200005;
int n; 

const int maxP = 1e5;
vector<int> prime;
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

int solve(){
    int x, y; cin>>x>>y;
    if(x == 0)
        return 1;
    if(y <= x)
        return y;
    
    int potx, expx, expy;
    int gcd = 1;
    for(int p : prime){
        if(p > y) break;
        if(y%p == 0){
            expx = expy = 0;
            while(y%p == 0){
                y/=p;
                ++expy;
            }
            potx = p;
            while(x/potx >0){
                expx += x/potx;
                potx *= p;
            }
            gcd *= pow(p, min(expx, expy));
        }
    }
    if(y > 1 && x >= y)
        gcd *= y;
    return gcd;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    sieve();
    loop(i, 0, t){
        cout<<solve()<<"\n";
    }
    return 0;

}