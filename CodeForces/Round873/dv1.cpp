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

const int maxN = 5e3+3;
int n;
int a[maxN], x[maxN], y[maxN], z[maxN];
void computeNextBigger(){
    loop(i, 0, n){
        y[i] = -1;
        loop(j, i+1, n){
            if(a[j] > a[i]){
                y[i] = j;
                break;
            }
        }
    }
}

void computeLastBigger(){
    loop(i, 0, n){
        x[i] = -1;
        for(int j = i-1; j > -1; --j){
            if(a[j] > a[i]){
                x[i] = j;
                break;
            }
        }
    }
}

void computeNextLowerAfterBigger(){
    loop(i, 0, n){
        z[i] = n;
        loop(j, y[i]+1, n){
            if(a[j] < a[i]){
                z[i] = j;
                break;
            }
        }
    }
}

void solve(){
    cin>>n;
    loop(i, 0, n) cin>>a[i];
    
    ll resp = 0; 
    loop(i, 0, n)
    loop(j, i, n){
        resp += j-i;
    }
    cout<<resp<<"\t";

    computeNextBigger();
    computeLastBigger();
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
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}