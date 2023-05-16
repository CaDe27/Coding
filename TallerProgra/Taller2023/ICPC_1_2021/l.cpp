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

string resp(ll n){
    if(n == 1)
        return "2";
    if(n%2 == 0)
        return "(" + resp(n/2) +")^2";
    else
        return "(2*"+resp(n-1)+")";
}

void solve(){
    int64_t n;
    cin>>n;
    cout<<resp(n)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; 
    cin>>t;
    for(int i = 0; i < t; ++i){
        solve();
    }
    return 0;
}