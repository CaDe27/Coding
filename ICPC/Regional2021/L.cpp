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
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 10005;

int c[481];
int n, x;
int events[2*100005];
void solve(){
    cin>>n>>x;
    int a, b;
    int last = -1;
    loop(i, 0, n){
        cin>>a>>b;
        events[a] += 1;
        events[a+b+1] += -1;
    }
    int actual = 0;
    for(int i = 0; i < 2*100000 +1; ++i){
        actual += events[i];
        if(actual > 0){
            for(int j = i%x; j <= i && j < 481; j += x){
                ++c[j];
            }
        }
    }
    int resp = 0, cResp = c[0];
    for(int i = 1; i < 481; ++i){
        if(c[i] < cResp){
            resp = i;
            cResp = c[i];
        }
    }
    cout<<resp<<" "<<cResp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
