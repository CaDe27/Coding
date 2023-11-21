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
#define INF 1000000000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;
const int maxN = 500005;

int n; string s, resp; 
void solve(){
    cin>>n>>s;
    int a = 0, b = 0;
    int odd = s.size() & 1;
    int limit = n/2;

    loop(i, 0, limit){
        if(s[i] == s[n-i-1])
            ++b;
        else
            ++a;
    }
    
    resp = "";
    loop(i, 0, a){
        resp += "0";
    }
    if(odd){
        loop(i, a, a+2*b+2){
            resp += "1";
        }
        loop(i, a+2*b+2, n+1)
            resp += "0";
    }else{
        int toca = 1;
        loop(i, a, a+2*b+1){
            resp += toca? "1" : "0";
            toca ^= 1;
        }
        loop(i, a+2*b+1, n+1)
            resp += "0";
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