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

const int maxN = 55, maxK = 31623;
int n, arre[maxN];

ll ini, fin, mitad;
bool esCuadrado(ll v){
    //busco primer cuadrado mayor o igual al numero
    ini = 0, fin = 1e9 + 1;
    while(ini != fin){
        mitad = (ini + fin)>>1;
        if(mitad*mitad < v)
            ini = mitad + 1;
        else 
            fin = mitad;
    } 
    return ini*ini == v;
}

int check(ll x){
    int cont = 0;
    loop(i, 0, n){
        if(esCuadrado(arre[i] + x))
            ++cont;
    }
    return cont;
}

int squarenes_pair(int u, int v){
    //both indices are squares
    if(arre[u] > arre[v]) swap(u, v);

    ll d = arre[v] - arre[u], b, x;
    int resp = 0;
    loop(k, 1, maxK){
        if(k*k > d) break;
        if(d%k == 0){
            b = d/k - k;
            if(b&1) continue;
            b>>=1;
            x = b * b - arre[u];
            if(x < 0) continue;
            resp = max(resp, check(x));
        }
    }
    return resp;
}

void solve(){
    cin>>n;
    loop(i, 0, n) cin>>arre[i];
    
    int squareness = 1, squareness_Case;
    for(int i = 0; i < n; ++i){
    for(int j = i+1; j < n; ++j){
        squareness = max(squareness, squarenes_pair(i, j));
    }
    }
    cout<<squareness<<"\n";
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