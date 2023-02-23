/*
    the idea is that when you fing a first substring that 
    is divisible by m then you can either cut or no
    if you do, then it's the same subproblem starting from the following index
    n't, you will have to cut in some other part that is divisible my m
        so its again the saeme problem 
        so it's twice as the same problem starting from i;
*/

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
#define MOD 1000000007LL

#define loop(i,a,b) for(int i = a; i < b; ++i)
const int maxN = 100005;

int n;
ll m;
string cad;

ll f(int indx){
    int i = indx+1;
    ll num = cad[indx]-'0';
    while(i < n && num % m != 0){
        num = num*10 + cad[i]-'0';
        num %= m;
        ++i;
    }
    if(i == n)
        return num%m == 0;
    else
        return ((2*f(i))%MOD);
}

void solve(){    
    cin>>n>>m;
    cin>>cad;
    cout<<f(0)<<"\n";
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

