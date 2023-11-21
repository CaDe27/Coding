#include <iostream>
#include <set>
using namespace std;

int main(){
    int n,k,a; cin>>n>>k;
    int suma = 0;
    for(int i = 0; i < n ;++i){
        cin>>a;
        suma+=a;
    }
    while(suma % (k+1) != 0){
        --k;
    }
    cout<<k<<"\n";
    return 0; 
}