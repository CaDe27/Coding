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

const int maxN = 1e5+5;
int n, m;
set<int> x_set;
int x[maxN];
int le, ri;
void solve(){
    cin>>n>>m;
    le = ri = 0;
    x_set.clear();
    loop(i, 0, n){
        int xi;cin>>xi;
        if(xi == -1)
            ++le;
        else if(xi == -2)
            ++ri;
        else
            x_set.insert(xi);
    }
    int indx = 0;
    int resp = 0, respCaso;
    int s = x_set.size();
    //if xi is the first
    for(int xi : x_set){
        ++indx;
        // 1 + der + izq
        respCaso = 1 
                + s-indx + min( m-xi - (s-indx), ri) 
                + indx-1 + min( xi-1 - (indx-1), le);
        resp = max(resp, respCaso);
    }

    //if leftie is first
    //if there is no m
    if( x_set.lower_bound(m) == x_set.end() )
        respCaso = min(m, s+le);
    //there is m
    else
        respCaso = min(m, s-1 + le);
    resp = max(resp, respCaso);

    //if rightie is first
    if( *(x_set.begin()) == 1 )
        respCaso = min(m, s-1 + ri);
    else
        respCaso = min(m, s + ri);
    resp = max(resp, respCaso);
    cout<<resp<<"\n";
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