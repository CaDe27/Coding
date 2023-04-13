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
int n, s;
string query(ll a, ll b){
    if(a == b)
        return 2*s == n? "YES" : "NO";
        
    ll num1 = ((n-2*s)*b), num2 = a-b;
    if( num1%num2 != 0)
        return "NO";

    ll d = ((n-2*s)*b) / (a-b);
    if( s-n <= d && d <= s)
        return "YES";
    else 
        return "NO";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin); 
    cin>>n;
    string str; cin>>str;
    s = 0; 
    for(char c : str){
        if(c == '+')
            ++s;
    }

    int q; cin>>q;
    int a, b;
    loop(i, 0, q){
        cin>>a>>b;
        cout<<query(a,b)<<"\n";

    }
    return 0;
}