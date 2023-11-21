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

string solve(){
    int s, d, k;
    cin>>s>>d>>k;
    return 2*s + 2*d >= k+1 && s+2*d >= k? "YES" : "NO";

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