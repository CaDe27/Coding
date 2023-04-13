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
int a[maxN], b[maxN];
void solve(){
    cin>>n;
    loop(i, 0, n)  cin>>a[i];
    loop(i, 0, n) cin>>b[i];
    int indx = n-1;
    int maxIndx = indx;
    for(int i = n-1; i >= 0; --i){
        //checo si se puede que hasta i puedan estar desconectadas
        while( indx>-1 && a[indx] != b[i])
            --indx;
        if(indx == -1){
            cout<<i+1<<"\n";
            return;
        }   
    }
    cout<<0<<"\n";
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