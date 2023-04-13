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
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    cin>>s;
    bool lucky = true;
    ll tot = 0;
    loop(i, 0, n){
        tot += s[i]-'0';
        if(s[i] != '4' && s[i] != '7'){
            lucky = false;
        }
    }
    ll sum = 0;
    n>>=1;
    loop(i, 0, n){
        sum += s[i]-'0';
    }
    if(lucky && 2*sum == tot){
        cout<<"YES\n";
    }
    else
        cout<<"NO\n";
    return 0;
}