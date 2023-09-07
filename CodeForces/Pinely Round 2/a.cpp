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
int n, a, q;
string c;
void solve(){
    cin>>n>>a>>q;
    cin>>c;
    
    bool YES = false;
    int active = a;
    int totAct = a;
    if(active == n){
        YES = true;
    }
    loop(i, 0, q){
        if(c[i] == '+'){
            ++active;
            ++totAct;
        }
        else{
            --active;
        } 
        if(active == n){
            YES = true;
        }
    }
    
    if(YES){
        cout<<"YES\n";
    }
    else if(totAct >= n){
        cout<<"MAYBE\n";
    }
    else{
        cout<<"NO\n";
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