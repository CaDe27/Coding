#include <iostream>
#define loop(i, a, b) for(int i = a; i < b; ++i)
#define MOD 1000000007
using namespace std;

typedef int64_t ll;

ll solve(int sizeS, string s){
    ll resp = 0;
    bool XOSoFar = false;
    char lastChar;

    loop(i, 0, sizeS){
        if(s[i]=='X' || s[i] =='O'){
            if(XOSoFar && s[i] != lastChar) 
                ++resp;
            XOSoFar = true;
            lastChar = s[i];
        }        
    }

    return resp; 
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    int sizeS;
    string s;
    loop(i, 1, t+1){
        cin>>sizeS>>s;
        cout<<"Case #"<<i<<": "<<solve(sizeS, s)<<"\n";
    }

}