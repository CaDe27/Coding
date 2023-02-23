
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

const int maxN = 100005;
int as[55], bs[55];
string s;
void solve(){
    cin>>s;
    int cant = 1;
    for(int i = 1; i <s.size(); ++i){
        if(s[i] == s[i-1])
            ++cant;
        else{
            if(as[cant]==0){
                cout<<"NO\n";
                return;
            }
            else{
                cant = 1;
            }
        }
    }
    if(as[cant]==0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    as[2]=as[3] = 1;
    for(int i = 4; i < 55; ++i){
        if(as[i-2] == 1 || as[i-3] == 1){
            as[i] = 1;
        }
    }
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
