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

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;


void solve(){
    ll k, x;
    cin>>k>>x;
    ll ini, mid, fin, mitad;

    //si si cabe
    ll resp; 
    if(x > k*k)
        resp = 2*k-1;
    //si debo buscar en la primera mitad
    else if( k*(k+1)/2 >= x){
        ini = 1; fin = k;
        while(ini != fin){
            mitad = (ini + fin)/2;
            if( mitad*(mitad+1)/2 >= x)
                fin = mitad;
            else
                ini = mitad + 1;
        }
        resp = ini;
    }
    //si en la segunda
    else{
        x -= k*(k+1)/2;
        ini = 1, fin = k-1;
        while(ini != fin){
            mitad = (ini + fin)/2;
            if(mitad*k - mitad*(mitad+1)/2 >= x)
                fin = mitad;
            else
                ini = mitad+1;
        }
        resp = k + ini;
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
