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
const int maxN = 100005;

int n;
int a[maxN];
void solve(){
    cin>>n;
    loop(i, 0, n)
        cin>>a[i];
    
    int it = 0;
    while(it < n && a[it] == it)
        ++it;
    int mex = it;
    
    cout<<mex<<endl;

    int y;
    cin>>y;
    while(y != -1){
        cout<<y<<endl;
        cin>>y;
    }
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}