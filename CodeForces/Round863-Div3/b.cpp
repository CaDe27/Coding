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

int getSquare(int x, int y){
    //if x == i
    if( min(x, n+1-x) <= y && y <= max(x, n+1-x)){
        return min(x, n+1 - x);
    }
    else
        return min(y, n+1-y);
}

void solve(){
    cin>>n;
    int x1, x2, y1, y2;
    cin>>x1>>y1>>x2>>y2;
    
    cout<< abs(getSquare(x1, y1) - getSquare(x2, y2)) <<"\n";
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