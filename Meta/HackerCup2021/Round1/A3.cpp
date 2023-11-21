#include <iostream>
#define loop(i, a, b) for(int i = a; i < b; ++i)
#define MOD 1000000007
using namespace std;

typedef int64_t ll;

int sizeS;
string s;
void updateChangesSOFar(int indx, int &firstIndexNotF, char &lastChar,ll &changesSoFar, bool &changeHappened){
    if(firstIndexNotF > -1)
        changeHappened = s[indx] != lastChar;
    if(changeHappened) 
        changesSoFar = (changesSoFar + 1) % MOD;
    firstIndexNotF = indx;
    lastChar = s[indx];
}

ll solve(){
    ll resp = 0, changesSoFar = 0, sumLast = 0, pendingSum = 0, lastContribution = 0, pos = 0;
    ll newSumLast, sumChangesSoFar, t, aux;
    int firstIndexNotF = -1;
    bool changeHappened = false;
    char lastChar;

    loop(i, 0, sizeS){
        if(s[i]=='X' || s[i] =='O'){
            updateChangesSOFar(i, firstIndexNotF, lastChar, changesSoFar, changeHappened);  
            if(changeHappened) 
                sumLast = (sumLast + pendingSum)%MOD;
            pendingSum = 0;
            lastContribution = ((pos*changesSoFar)%MOD + MOD - sumLast)%MOD;
            sumLast = (sumLast + changesSoFar)%MOD;
            sumChangesSoFar = (sumChangesSoFar + changesSoFar)%MOD;
            resp = (resp + lastContribution)%MOD; 
            ++pos;
        }
        else if(s[i] == 'F'){
            pendingSum += 1;
            sumLast = (sumLast + changesSoFar)%MOD;
            sumChangesSoFar = (sumChangesSoFar + changesSoFar)%MOD;
            resp = (resp + lastContribution)%MOD;
            ++pos; 
        }
        else{
            if(firstIndexNotF == -1) continue;
            if(lastChar != s[firstIndexNotF]){
                t = (pos + MOD - firstIndexNotF)%MOD;
                newSumLast = (sumLast + pendingSum)%MOD;
            }
            else{
                t = 0;
                newSumLast = sumLast;
            }

            aux = (pos*pos)%MOD;
            aux = (aux*changesSoFar)%MOD;

            resp = (2*resp)%MOD;
            resp = resp + aux + (pos*t)%MOD + sumChangesSoFar + MOD - (pos*newSumLast)%MOD;
            resp %= MOD;

            sumLast = (newSumLast + (pos*changesSoFar)%MOD + t + sumLast)%MOD;
            changesSoFar = (2*changesSoFar + (lastChar!=s[firstIndexNotF]))%MOD;
            pos = (2*pos-1)%MOD;
            lastContribution = ((pos*changesSoFar)%MOD + MOD - sumLast)%MOD;
            
        } 
        pos%= MOD;
    }

    return resp; 
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    loop(i, 1, t+1){
        cin>>sizeS>>s;
        cout<<"Case #"<<i<<": "<<solve()<<"\n";
    }

}