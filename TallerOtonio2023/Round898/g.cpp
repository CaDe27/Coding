#include <iostream>
#include <algorithm>
#include <string>
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;

string s;
int cantidadDeAs(){
    int countA = 0;
    loop(i, 0, s.size())
        countA += s[i] == 'A';
    return countA;
}

bool hayDosBsConsecutivas(){
    loop(i, 1, s.size())
        if(s[i] == 'B' && s[i-1] == 'B')
            return true;
    return false;
}

int bloqueMinimoDeAs(){
    //elimino menor bloque de a's
    s += "B";
    int minBloque = 1e9, countBloque = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'A')
            ++countBloque;
        else if(i > 0 && s[i] == 'B' && s[i-1] == 'A'){
            minBloque = min(minBloque, countBloque);
            countBloque = 0;
        }
    }
    return minBloque;
}

void solve(){
    //leo
    cin>>s;
    
    // cosas que necesito para saber si son todas las As
    int countA = cantidadDeAs();
    bool twoB = hayDosBsConsecutivas();

    // imprimo la respuesta
    if(s[0] == 'B' || s[s.size()-1] == 'B' || twoB)
        cout<<countA<<"\n";
    else
        cout<<(countA-bloqueMinimoDeAs())<<"\n";    
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