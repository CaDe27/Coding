#include <iostream>
//si hay un primo que divida a ambos, su producto sera divisible por p^2
//si no hay tal primo, son primos relativos y no se podra

using namespace std;

typedef int64_t ll;

ll gcd(ll a, ll b){
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}

int main(){
    int n;
    cin>>n;

    ll a,b;

    for(int i = 0; i < n; i++){
        cin>>a>>b;
        cout<< (gcd(a,b) == 1? "SI" : "NO") <<"\n";
    }
    return 0;
}