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

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;

void solve(){
    int n; cin>>n;
    ++n;
    vector<int> a(n), b(n);
    loop(i, 0, n)
        cin>>a[i];
    loop(i, 0, n)
        cin>>b[i];
    
    ll needed = 0;
    bool notPossible = false;
    for(int i = n-1; i >= 0; --i){
        if(a[i] >= b[i])
             continue;
        else{
            b[i] -= a[i];
            if(i == 0)
                notPossible = true;
            else{
                b[i-1] += b[i]/2 + (b[i]&1);
                needed += b[i]/2 + (b[i]&1);
            }
        }
    }
    if(notPossible)
        cout<<"-1\n";
    else
        cout<<needed<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
