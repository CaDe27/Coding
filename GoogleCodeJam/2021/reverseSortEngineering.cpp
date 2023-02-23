#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std; 

const int maxN = 1005;

void solve(){
    int n,c;
    cin>>n>>c;
    if( c > (n-1)*(n+2)/2 || c < n-1) {
        cout<<"IMPOSSIBLE";
        return;
    }
    
    int arre[n];
    int index[n];
    for(int i = 0; i < n; ++i) index[i] = i;

    c -= n-1;
    int numero;
    for(int i = n-1; i >= 1; --i){
        numero = n-1 - i + 1;
        //checo si necesita los i
        if(c < i){
            //si no lo necesita, te necesito ya en tu lugar
            arre[index[numero-1]] = numero;
        }
        else{
            c -= i;
            //si los necesita
            arre[index[n-1]] = numero;
            reverse(index + (n-1 - i), index + n);
        }
    }
    arre[index[n-1]] = n;

    cout<<arre[0];
    for(int i = 1; i < n; ++i){
        cout<<" "<<arre[i];
    }
}

int main(){
    int T; cin>>T;
    for(int t = 1; t <= T; ++t){
        cout<<"Case #"<<t<<": ";
        solve();
        cout<<"\n";
    }
    return 0;
}