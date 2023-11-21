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

ll solve(){
    ll a, b, c;
    cin>>a>>b>>c;
    // when it's impossible
    if(c < min(a,b))
        return 0;

    //only buy doubles
    if(b <= a)
        return max(0LL, 2*(c/b)-1); 
    //only buy singles
    else if(2*a <= b)
        return c/a;
    else{
        //max between three cases 
        //    all doubles,
        //    1 single and the rest doubles
        //    2 singles and the rest doubles
        // in case with at least one single, you only
        // need to maximize k=s+2d, and it is always 
        // cheapear or at less the same to buy one double
        // than two singles. And a double
        // has double value for the expression.
        // That means that you can always reduce your case to having
        // 1 or 2 singles at most. 
        ll resp = max(2*(c/b)-1, 1 + 2*((c-a)/b));
        if(c >= 2*a)
            resp = max(resp, 2+2*((c-2*a)/b));
        return resp;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    for(int i = 1; i <= t; ++i){
        cout<<"Case #"<<i<<": "<<solve()<<"\n";
    }
    return 0;
}