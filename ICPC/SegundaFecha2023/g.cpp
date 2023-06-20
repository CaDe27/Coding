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
int n, t;

ll max_si, max_so, max_s, s[maxN], in[maxN], out[maxN];
ll suma = 0; 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n>>t;
    ll a, b, respCase;
    for(int i = 0; i < t;++i){
        cin>>a>>b;
        if(a == b){
            suma += 2*s[a] + in[a] + out[a] + 1;
            ++s[a];
        }
        else{
            suma += s[a]+in[a]+s[b]+out[b];
            ++in[b]; ++out[a];
        } 
        max_s = max(max_s, 2*s[a]+in[a]+out[a]+1);
        max_s = max(max_s, 2*s[b]+in[b]+out[b]+1);
        max_si = max(max_si, s[b] + in[b]);
        max_so = max(max_so, s[a] + out[a]);
        respCase = max(max_s, max_si+max_so);
        cout<<suma<<" "<<respCase<<"\n";

    }
    return 0;
}