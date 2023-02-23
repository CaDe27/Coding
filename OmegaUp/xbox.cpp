#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n;
    cin>>n;
    
    long suma = 0, maxi = -100;
    int aux;
    
    for(int i = 0; i < n; ++i){
        cin>>aux;
        suma += aux;
        maxi = max(maxi, suma);
        if(suma < 0)
            suma = 0;
    } 
    cout<<maxi<<'\n';
}