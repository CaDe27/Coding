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
#include <fstream>

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

#define loop(i,a,b) for(int i = a; i < b; ++i)

int n, b;
typedef pair<ll,ll> pll;
bool f(const pll &a, const pll &b){
    return a.first * b.second < a.second * b.first;
}

void solve(){
    cin>>b>>n;
    vector<pll> bolsas;
    pll bolsa;
    loop(i, 0, b){
        cin>>bolsa.first>>bolsa.second;
        if(bolsa.first == 0)
            bolsa.second = 10;
        bolsas.push_back(bolsa);
    }
    bolsa = pll(0, 1);
    loop(i, b, 5)
        bolsas.push_back(bolsa);
    sort(bolsas.begin(), bolsas.end(), f);
    if(bolsas[4].first == 0){
        cout<<"-1\n";
        return;
    }

    ll a, b, c;
    double s, ar = 0;
    
    loop(i, 0, n){
        cin>>a>>b>>c;
        s = (a + b + c)/2;
        ar += sqrt(s*(s-a)*(s-b)*(s-c));         
    }
    ll kgsNecesarios = ceil(ar/30), kgs;

    ll kg, precio, faltan; 
    ll resp = -1, respCaso;
    loop(i, 0, 26)
    loop(j, 0, 26)
    loop(k, 0, 26)
    loop(l, 0, 26){
        kgs = i*bolsas[0].first + j*bolsas[1].first + k*bolsas[2].first + l*bolsas[3].first;
        precio = i*bolsas[0].second + j*bolsas[1].second + k*bolsas[2].second + l*bolsas[3].second;
        faltan = kgsNecesarios <= kgs? 0 : (kgsNecesarios - kgs)/bolsas[4].first + ((kgsNecesarios-kgs)%bolsas[4].first > 0? 1:0);
        respCaso = precio + faltan*bolsas[4].second;
        if(resp == -1 || respCaso < resp)
            resp = respCaso;
    }
    cout<<resp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}