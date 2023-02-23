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

const int maxN = 200005;
int n, a[maxN];
void solve(){
    cin>>n;
    loop(i, 0, n) cin>>a[i];
    if(n<=2){
        cout<<"-1\n";
        return;
    }
    int maxi = n, mini = 1;
    int l = 0, r = n-1;
    while(r>l+1 && (a[l] == maxi || a[l] == mini || a[r] == maxi || a[r] == mini) ){
        if(a[l] == mini){
            ++mini;
            ++l;
        }
        else if(a[l] == maxi){
            --maxi;
            ++l;
        }
        else if(a[r] == mini){
            ++mini;
            --r;
        }
        else if(a[r] == maxi){
            --maxi;
            --r;
        }
    }
    if(r-l == 1){
        cout<<"-1\n";
    }
    else{
        cout<<l+1<<" "<<r+1<<"\n";
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