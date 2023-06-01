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

const int maxN = 3e5+5;
ll n;
int a[maxN]; 
ll x[maxN], y[maxN], z[maxN], power2[20];
int logg2[maxN];
stack<pii> decreasing;

int minSparseTable[maxN][20];

void computeNextandLastBigger(){
    fill(y, y+n, -1);
    fill(x, x+n, -1);
    
    while(!decreasing.empty())
        decreasing.pop();

    loop(i, 0, n){
        while(!decreasing.empty() && a[i] > decreasing.top().second){
            y[decreasing.top().first] = i;
            decreasing.pop();
        }
        if(!decreasing.empty()){
            x[i] = decreasing.top().first;
        }
        decreasing.push(pii(i, a[i]));
    }   
}

int minQuery(int indx1, int indx2){
    int logSize = logg2[indx2-indx1+1];
    return min(minSparseTable[indx1][logSize], 
              minSparseTable[indx2-power2[logSize]+1][logSize]);
}

void computeNextLowerAfterBigger(){
    int start, end, middle;
    loop(i, 0, n){
        start = y[i];
        end = n-1;
        if(y[i] == -1 || minQuery(start, end) > a[i]){
            z[i] = n;
            continue;
        }

        while( start != end){
            middle = (start + end)/2;
            if(minQuery(start, middle) > a[i])
                start = middle+1;
            else
                end = middle;
        }
        z[i] = start;
    }
}

void fillSparseTable(){
    loop(i, 0, n)
        minSparseTable[i][0] = a[i];
    loop(k, 1, logg2[n]+1){
        loop(i, 0, n){
            if(i+power2[k-1] < n)
                minSparseTable[i][k] = min(minSparseTable[i][k-1], 
                                            minSparseTable[i+power2[k-1]][k-1]);
            else
                minSparseTable[i][k] = minSparseTable[i][k-1];
        }
    }
}

void solve(){
    cin>>n;
    loop(i, 0, n) cin>>a[i];
    
    ll resp = (n-1)*n*(n+1)/6;
    computeNextandLastBigger();
    
    fillSparseTable();
    computeNextLowerAfterBigger();

    loop(i, 0, n){
        if(y[i] != -1)
            resp -= (i-x[i])*(z[i]-y[i]);
    }
    cout<<resp<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    logg2[1] = 0;
    loop(i, 2, maxN){
        logg2[i] = logg2[i/2]+1;
    }

    power2[0] = 1;
    loop(i, 1, logg2[maxN-1]+1){
        power2[i] = 2*power2[i-1];
    }

    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}