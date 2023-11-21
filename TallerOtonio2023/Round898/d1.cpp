#include <iostream>
#include <algorithm>

using namespace std;

void solve(){
    int n, k; cin>>n>>k;
    string s; cin>>s;

    int it = 0, ops = 0;
    while(it < n){
        if(s[it] == 'B'){
            ++ops;
            it += k;
        }
        else
            ++it;
    }
    cout<<ops<<"\n";
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