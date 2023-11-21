#include <iostream>
#include <algorithm>
using namespace std;
int a[10], n;

void solve(){
    // leo datos
    cin>>n;
    for(int i = 0; i < n; ++i) 
        cin>>a[i];

    // ordeno el arreglo
    sort(a, a+n);

    // aumento el indice del minimo
    ++a[0];

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