/*



*/


#include <iostream>

using namespace std;

typedef int64_t ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, m;
    cin>>n>>m;
    
    if(n <= m){
        cout<<n<<"\n";
        return 0;
    }
    
    // buscamos el primer dia tal que n -m- s(k) <=0
    // donde s(k) es la suma de gaus (1+2+3+...+k)
    
    //nuestro espacio es de la forma - - - - - + + + 
    //buscamos el primer mas

    //hacemos busqueda binaria sobre k;
    ll ini, fin, mitad;
    ini = (ll)0;
    fin = n-m;  

    while(ini != fin){
        mitad = (ini + fin)/2;
        if( mitad >= 1414213562 || (n - m <= mitad*(mitad+1)/2) )
            fin = mitad;
    
        else
            ini = mitad+1;
    }

    cout<<m+(ini)<<"\n";
    return 0;
}