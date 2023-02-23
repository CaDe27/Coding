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
int n, a[maxN];

void solve(){
    cin>>n;
    loop(i, 0, n){
        cin>>a[i];
    }
    --a[0];
    int mini = 1;
    loop(i, 2, n)
        if(a[i] < a[mini])
            mini = i;

    int bob = a[mini] + 1;

    int mini2 = 0;
    loop(i, 1, n){
        if(i != mini && a[i] < a[mini2])
            mini2 = i;
    }
    int alice = a[mini2] + 1;
    if(alice == bob){
        cout<<"Alice\n";
    }
    else if(bob < alice){
        cout<<"Alice\n";
    }
    else
        cout<<"Bob\n";

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