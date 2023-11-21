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
int n; ll a[maxN];

string entre2(ll num){
    if(num&1)
        return to_string(num/2)+".5";
    else
        return to_string(num/2);
}
string solve(){
    cin>>n;
    loop(i, 0, n){  
        cin>>a[i];
    }
    sort(a, a+n);

    if(n == 5){
        return entre2( max((a[n-1]+a[n-2]) -(a[0] + a[2]), a[n-1]+a[2] - (a[0] +a[1])));
    }
    else{
        return entre2( a[n-1]+a[n-2] - (a[1]+a[0]) );
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    loop(i, 1, t+1)
        cout<<"Case #"<<i<<": "<<solve()<<"\n";
    
    return 0;
}