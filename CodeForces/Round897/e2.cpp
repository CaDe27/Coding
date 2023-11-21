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

void solve(){
    int n, k; cin>>n>>k;
    ll resp = 0, query;
    if(n%k == 0){
        loop(i, 0, n/k){
            cout<<"? "<<1+i*k<<endl;
            cin>>query;
            resp ^= query;    
        }
        cout<<"! "<<resp<<endl;
    }
    else{
        loop(i, 0, n/k - 1){
            cout<<"? "<<1+i*k<<endl;
            cin>>query;
            resp ^= query;
        }
        int it = 1+(n/k-1)*k;
        int r = (n%k)/2;
        loop(i, 0, 3){
            cout<<"? "<<it + r*i<<endl;
            cin>>query;
            resp ^= query;
        }
        cout<<"! "<<resp<<endl;
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}