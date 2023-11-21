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

void solve(){
    int n, k;
    cin>>n>>k;

    int complete = n/k;
    ll resp = 0, num;
    int indx = 1;
    for(int i = 0; i < complete-1; ++i, indx+=k){
        cout<<"? "<<indx<<endl;
        cin>>num;
        resp ^= num;
    }
    
    for(; indx + k <= n+1; ++indx){
        cout<<"? "<<indx<<endl;
        cin>>num;
        resp ^= num;
    }

    cout<<"! "<<resp<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}