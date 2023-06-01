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

const int maxN = 2e5+5;
int n;
int a[maxN], b[maxN];

int bin(int i){
    int ini =0, fin = n-1, mita;
    if(a[n-1] <= i)
        return -1;
    while(ini != fin){
        mita = (ini+fin)/2;
        if(a[mita] > i)
            fin = mita;
        else
            ini = mita+1;
    }
    return ini;
}

void solve(){
    cin>>n;
    loop(i, 0, n){
        cin>>a[i];
    }
    loop(i, 0, n){
        cin>>b[i];
    }
    sort(a, a+n);
    sort(b, b+n);
    if(b[n-1] > a[n-1]){
        cout<<"0\n";
        return;
    }

    ll resp = 1;
    for(int i = n-1; i>=0; --i){
        ll res= bin(b[i]), opciones = ( (n-bin(b[i]))-(n-1-i));
        if(res == -1 || opciones <= 0){
            cout<<"0\n";
            return;
        }
        else
            resp = (resp * opciones)%MOD;
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