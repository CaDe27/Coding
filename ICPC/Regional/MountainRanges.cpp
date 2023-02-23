#include <iostream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt","r")) freopen("case.txt","r",stdin);
    int n, x, h1, h2, cont = 1, m=1;
    cin>>n>>x;
    cin>>h1;
    for(int i = 1; i < n; ++i){
        cin>>h2;
        cont = h2 > x+h1? 1 : 1+cont;
        if(cont > m) m = cont;
        h1 = h2;
    }
    cout<<m<<'\n';
}