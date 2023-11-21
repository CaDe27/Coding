#include <iostream>
#define loop(i, a, b) for(int i = a; i < b; ++i)
#define MOD 1000000007
using namespace std;

typedef int64_t ll;

void updateChangesSOFar(bool &XOSoFar, char &lastChar, char &nextChar, ll &changesSoFar, bool &changeHappened){
    if(XOSoFar)
        changeHappened = nextChar != lastChar;
    if(changeHappened) 
        changesSoFar = (changesSoFar + 1) % MOD;
    XOSoFar = true;
    lastChar = nextChar;
}

ll solve(int sizeS, string s){
    ll resp = 0, changesSoFar = 0, sumLast = 0, pendingSum = 0, lastContribution = 0;
    bool XOSoFar = false, changeHappened = false;
    char lastChar;

    loop(i, 0, sizeS){
        if(s[i]=='X' || s[i] =='O'){
            updateChangesSOFar(XOSoFar, lastChar, s[i], changesSoFar, changeHappened);  
            if(changeHappened) 
                sumLast = (sumLast + pendingSum)%MOD;
            pendingSum = 0;
            lastContribution = ((i*changesSoFar)%MOD + MOD - sumLast)%MOD;
            sumLast = (sumLast + changesSoFar)%MOD;
        }
        else{
            pendingSum += 1;
            sumLast = (sumLast + changesSoFar)%MOD;
        }     
        resp = (resp + lastContribution)%MOD;   
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