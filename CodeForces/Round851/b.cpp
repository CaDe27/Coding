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
int digitos[15];

void solve(){
    cin>>n;
    int d;
    int x = 0, y=0, i = 0;
    while(n > 0){
        digitos[i] = n%10;
        n/=10;
        ++i;
    }
    
    loop(it, 0, i){
        d = digitos[i-1-it];
        if(d&1){
            x = 10*x + (d-1)/2;
            y = 10*y + (d+1)/2;
            swap(x, y);
        }
        else{
            x = 10*x + d/2;
            y = 10*y + d/2;
        }
    }
    cout<<x<<" "<<y<<"\n";


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