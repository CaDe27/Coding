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
#define all(x) begin(x), end(x)
using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 100005;
int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    ll a, b;
    cin>>n;
    ll resp = 0;
    vector<ll> proms;
    loop(i, 0, 2*n){
        cin>>a>>b;
        if(a > b) swap(a,b);
        resp += (b-a);
        proms.push_back(a+b);
    }
    sort(all(proms));
    loop(i, 0, n){
        resp += proms[2*n-1-i] - proms[i];
    }
    resp >>=1;
    cout<<resp<<"\n";
    return 0;
}