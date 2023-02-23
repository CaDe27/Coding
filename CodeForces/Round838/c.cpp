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
#define MOD 998244353

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

int n;
string s;
void solve(){
    cin>>n;
    cin>>s;
    ll suma = 1;
    char ant = s[0];
    ll acum = 1;
    loop(i, 1, s.size()){
        if(s[i] == ant){
            acum<<=1;
            acum%= MOD;
            suma += acum;
            suma = suma%MOD;
        }
        else{
            acum = 1;
            suma += acum;
            suma = suma%MOD;
        }
        ant = s[i];
    }
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