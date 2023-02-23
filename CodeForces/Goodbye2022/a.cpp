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

const int maxN = 1000;
int n; 
ll a[maxN], b[maxN];

void solve(){
    int m;
    cin>>n>>m;
    ll suma =0; 
    loop(i,0,n){
        cin>>a[i];
    }
    loop(i, 0 ,m) {
        cin>>b[i];
        int indxMin = 0;
        loop(j, 1, n){
            if(a[j] < a[indxMin])
                indxMin = j;
        }
        a[indxMin] = b[i];
    }
    loop(i, 0, n)
        suma += a[i];


    cout<<suma<<"\n";
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