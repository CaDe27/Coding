#include <iostream>
using namespace std;
typedef int64_t ll;



ll n, r;
ll a[500000];
ll decrementos[500005];

bool sePuede(ll nivel, ll k){
    ll incremento = 0;
    for(int i = 0; i < n; ++i){
        //para cada seccion verifica si si tiene el nivel
        incremento -= decrementos[i];
        if( a[i] + incremento >= nivel)
            continue;
        
        ll necesito = nivel - (a[i] + incremento);
        if( necesito > k)
            return false;
        else{
            k -= necesito;
            incremento += necesito;
            int indice = min(i + 2*r + 1, n);
            decrementos[indice] -= necesito;
        }
    }
    return true;
}

int main(){
    ll k;
    cin>>n>>r>>k;
    for(int i = 0; i < n; ++i)
        cin>>a[i];

    ll ini = 0, fin = 2e18, mitad;
    while(ini != fin){
        mitad = (ini + fin + 1)/2;
        if(sePuede(mitad, k))
            ini = mitad;
        else 
            fin = mitad-1;
    }
    cout<<ini<<"\n";
    return 0;
}