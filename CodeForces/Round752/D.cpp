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

#define m(a,b) (a%b + b)%b
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 1e5 +10;
int n; 

void solve(){
    ll x, y;
    cin>>x>>y;
    ll resp, cociente;
    if( y < x)
        resp = x+y;
    else if( y % x == 0)
        resp = x;
    else{
        cociente = y / x;
        resp = cociente*x;
        resp = resp + (y - resp)/2;
    }
    cout<<resp<<"\n";
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    
    int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
