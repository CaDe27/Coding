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

int n;
void solve(){
    cin>>n;
    int a1 = 1, a2=2, a3 = 3, f2;
    int maxi, dif, maxiF;
    cout<<"? "<<a1<<" "<<a2<<" "<<a3<<endl;
    cin>>dif;
    maxi = dif;
    
    loop(i, 4, n+1){
        cout<<"? "<<a1<<" "<<a2<<" "<<i<<endl;
        cin>>dif;
        if(dif > maxi){
            maxi = dif;
            a3 = i;
        }
    }
    maxiF = maxi;

    loop(i, 1, n+1){
        if(i == f1 && i == a1) continue;
        cout<<"? "<<a1<<" "<<f1<<" "<<i<<endl;
        cin>>dif;
        if(dif < mini){
            mini = dif;
        }
        else if(dif > maxi){
            maxi = dif;
            f2 = i;
        }
    }

    if(mini == maxi){
        cout<<"! "<<a1<<" "<<f1<<endl;
        return;
    }

    else{
        cout<<"! "<<f1<<" "<<f2<<endl;
    }
}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
