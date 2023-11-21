#include <iostream>
using namespace std;
int a[10], n;

void solve(){
    // leo datos
    cin>>n;
    for(int i = 0; i < n; ++i) 
        cin>>a[i];

    // busco el indice del minimo
    int indxMin = 0;
    for(int i = 1; i < n; ++i)
        if(a[indxMin] > a[i])
            indxMin = i;
    // lo aumneto
    ++a[indxMin];

    // calculo la respuesta
    int resp = 1;
    for(int i = 0; i < n; ++i)
        resp *= a[i];
    cout<<resp<<"\n";
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