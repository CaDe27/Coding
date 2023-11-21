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
const int maxN = 500005;

void solve(){
    char x;
    int ix, jx;
    int points = 0;
    loop(i, 0, 10){
    loop(j, 0, 10){
        cin>>x;
        if(x == 'X')
        {   
            ix = i < 5? i : 9 - i;
            jx = j < 5? j : 9 - j;
            points += min(ix, jx) + 1;
        }
    }
    }
    cout<<points<<"\n";
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