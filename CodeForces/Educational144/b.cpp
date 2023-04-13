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
string s1, s2;
void solve(){
    cin>>s1>>s2;
    if(s1[0] == s2[0]){
        cout<<"YES\n";
        cout<<s1[0]<<"*"<<"\n";
        return;
    }
    else if(s1[s1.size()-1] == s2[s2.size()-1]){
        cout<<"YES\n";
        cout<<"*"<<s1[s1.size()-1]<<"\n";
        return;
    }
    else{
        loop(i, 0, s1.size()-1){
        loop(j, 0, s2.size()-1){
            if(s1[i] == s2[j] && s1[i+1] == s2[j+1]){
                cout<<"YES\n";
                cout<<"*"<<s1[i]<<s1[i+1]<<"*\n";
                return;
            }   
        }
        }
    }
    cout<<"NO\n";
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