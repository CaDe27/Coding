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
int arre[maxN];
void solve(){
    cin>>n;
    int tot = 0;
    loop(i, 0, n){
        cin>>arre[i];
        if(arre[i]==2)
            ++tot;

    }
    
    if(tot == 0){
        cout<<1<<"\n";
        return;
    }
    if(tot&1){
        cout<<"-1\n";
        return;
    }
    
    tot>>=1;
    loop(i, 0, n){
        if(arre[i] == 2)
            --tot;
        if(tot==0){
            cout<<i+1<<"\n";
        return;}
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