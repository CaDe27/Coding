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
int n;


void solve(){
    cin>>n;
    if((n&1) == 0)
    {
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    int suma = 3*(n+1)/2;
    int i;
    for(i = (3*n-1)/2; i > n; --i){
        cout<<i<<" "<<(suma - i)<<"\n";
        ++suma;
    }
    for(i = 2*n; i > (3*n-1)/2; --i){
        cout<<i<<" "<<(suma - i)<<"\n";
        ++suma;
    }
    
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