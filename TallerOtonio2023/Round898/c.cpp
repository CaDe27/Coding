#include <iostream>
#include <algorithm>
#define INF 1000000000000000000
#define MOD 1000000007

using namespace std;

void solve(){
    char x;
    int ix, jx;
    int totalPoints = 0;
    
    // i es la fila
    // j es la columna
    for(int i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j){
        cin>>x;
        if(x == 'X')
        {  
            ix = i < 5? i : 9 - i;
            jx = j < 5? j : 9 - j;
            totalPoints += min(ix, jx) + 1;
        }
    }
    }
    cout<<totalPoints<<"\n";
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