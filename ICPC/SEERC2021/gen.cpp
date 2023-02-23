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
    ll tot = 0;
    string s, t;
    int n;
    cin>>n;
    cin>>s>>t;
    ll equalLeft[n+1];
    
    loop(i, 0, n){
        if(s[i] == t[i])
            equalLeft[i] = 1 + (i>0? equalLeft[i-1] : 0);
        else
            equalLeft[i] = 0;
    }
    if(s[n-1] < t[n-1]) tot = 1;
    if(n > 1 && s[0] < t[0]) tot += n;
    for(int i = n-2; i >= 1; --i){
        if(s[i] < t[i]){
            tot += (equalLeft[i-1] + 1)*(n-i);
        }

    }
    cout<<tot<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cout<<(ll)100000*2000001<<endl;
    
    return 0; 
}
