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
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;


int fromString(string s){
    int resp = 0;
    s = s.substr(1);
    for(int i = 0; i < s.size(); ++i){
        resp = resp*10 + (s[i]-'0');
    }
    return resp;
}

void solve(){
    int n; cin>>n;
    int total = 0, counter = 0;
    string s; 
    cin>>s;
    total += fromString(s);
    loop(i, 0,n){
        cin>>s;
        total += fromString(s);
        if(total %100 != 0)
            ++counter;
    }

    cout<<counter<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
