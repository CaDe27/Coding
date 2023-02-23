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

const int maxN = 1e6 +5;

bool in[maxN];
int gcdMultiples[maxN];
int gcd(int a, int b){
    if(a == 0) return b;
    else return gcd(b%a, a);
}
void solve(){
    int n, maxElement = 0;
    cin>>n;
    for(int x, i = 0; i < n; ++i){
        cin>>x;
        in[x] = true;
        maxElement = max(maxElement, x);
    }
    int resp = 0;
    loop(i, 1, maxElement+1){
        for(int j = i; j <= maxElement; j+=i){
            if(in[j])
                gcdMultiples[i] = gcd(gcdMultiples[i], j);
        }
        resp += gcdMultiples[i] == i;
    }
    cout<<resp - n<<"\n";  
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
