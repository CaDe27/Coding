#include <iostream>
using namespace std;

void solve(){
    string s; cin>>s;
    if(s == "abc" || string(1, s[0]) + s[2] + s[1] == "abc"
        || string(1, s[1]) + s[0] + s[2] == "abc"
        || string(1, s[2]) + s[1] + s[0] == "abc")
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}