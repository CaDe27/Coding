
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
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 200005;
int a[maxN], n;

bool check(int ini){
    loop(i, 0, n){
        if(abs(a[i] - (ini+i))>1)
            return false;
    }
    return true;
}


void solve(){
    cin>>n;;
    loop(i, 0, n){
        cin>>a[i];
    }

    if(check(a[0])){
        cout<<"YES\n";
        return;
    }
    else if(check(a[0]-1)){
        cout<<"YES\n";
        return;
    }
    if(check(a[0]+1)){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
