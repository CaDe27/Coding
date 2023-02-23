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
ll n, x;

void solve(){
    cin>>n>>x;
    ll cotaSup = 5e18 + 1, cotaInf = 0;
    ll bitIt = 0, acum = 0;
    bool xPrendido, nPrendido;
    while( (1LL<<bitIt) <= max(x, n)){
        xPrendido = x & (1LL<<bitIt);
        nPrendido = n & (1LL<<bitIt);
        if(nPrendido) 
            acum += (1LL<<bitIt);
        if(!nPrendido && xPrendido){
            cout<<"-1\n";
            return;
        }
        else if(xPrendido && nPrendido){
            cotaSup = min(cotaSup, (1LL<<(bitIt+1)) - acum);
        }
        else if(nPrendido && !xPrendido){
            cotaInf = max(cotaInf, (1LL<<(bitIt+1)) - acum);
        }
        ++bitIt;
    }
    //buscamos el menor numero mayor o igual a la cota inf y menor a la cota sup
    if(cotaSup <= cotaInf ){
        cout<<"-1\n";
        return;
    }
    else{
        cout<<n+cotaInf<<"\n";
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