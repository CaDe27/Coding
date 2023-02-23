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
#include <sstream>

using namespace std;

typedef int64_t ll;
#define loop(i,a,b) for(int i = a; i < b; ++i)

// a mod m = b mod m  => a - b mod m = 0
// then we use the difference array
// and for each index we find (to the left) the max number of
// elements that have such that the gcd of all is > 1

//for this we use ST
// and simulate a "binary search" over the past elements

ll gcd(ll a, ll b){
    if(a == 0 || b == 0) return a + b;
    else return gcd(b % a, a);
}

const int maxN = 2*1e5 + 5, maxLog = 20;
int n, logg[maxN], pot[maxLog];
ll arre[maxN], diff[maxN];
ll sparseGcd[maxN][maxLog];

void init(){
    loop(i, 0, n-1)
        sparseGcd[i][0] = diff[i];

    loop(exp, 1, maxLog){
        loop(i, 0, n-1){
            if(i - pot[exp-1] < 0)
                sparseGcd[i][exp] = sparseGcd[i][exp-1];
            else
                sparseGcd[i][exp] = gcd(sparseGcd[i][exp-1], sparseGcd[i-pot[exp-1]][exp-1]);
        }
    }
}

ll queryGCD(int lq, int rq){
    int logRange = logg[rq - lq + 1];
    return gcd(sparseGcd[rq][logRange], sparseGcd[lq + pot[logRange] - 1][logRange]);
}

bool sumOne;
ll query(int indx){
    if(diff[indx] == 1) return 1;
    int ini = 0, fin = indx, mid;
    while(ini != fin){
        mid = (ini + fin)/2;
        if(queryGCD(mid, indx) > 1)
            fin = mid;
        else
            ini = mid + 1;
    }
    return indx - ini + 1;
}

void solve(){
    cin>>n;
    sumOne = false;
    loop(i, 0, n) {
        cin>>arre[i];
        if(i > 0){
            diff[i-1] = abs(arre[i] - arre[i-1]); 
            if(diff[i-1] > 1) sumOne = true;
        } 
    }
    if(n == 1) {
        cout<<1<<endl;
        return;
    }
    init();
    ll resp = 1;
    loop(i, 1, n-1){
        resp = max(resp, query(i));
    }
    cout<<resp+sumOne<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);  
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    logg[1] = 0;
    loop(i, 2, maxN)
        logg[i] = logg[i/2] + 1;
    
    pot[0] = 1;
    loop(i, 1, 20)
        pot[i] = pot[i-1]*2;

    loop(i, 0, t)
        solve();
    return 0;
}
