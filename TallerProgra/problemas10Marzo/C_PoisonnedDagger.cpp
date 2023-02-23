//
// lo dificil aquí es no saber con k atacar al dragón
// y si lo estás averiguando de forma dinámico el problema es muy caótica
// si k fuera fija, es muy sencillo responder si con esa k se puede vencer al 
//dragón. 
// 
// esto motiva a hacer una búsqueda binaria sobre k
// buscamos la primer k que cumple


#include <iostream>
using namespace std;
typedef int64_t ll;

const int maxN = 105;
int n;
ll vidaDragon, a[maxN];

//venzo al dragon si el total de daño que le ingligí fue al menos su vida
bool venzoAlDragon(ll k){
    ll totalDanio = 0;
    //en cada momento le inflijo k si se puede, o mi distancia al proximo
    //segundo si esta es menor
    for(int i = 0; i <n-1; ++i){
        totalDanio += min(a[i+1]-a[i], k);
    }
    //el ultimo ataque siempre inflige daño k porque nadie lo limita
    totalDanio += k;
    return vidaDragon <= totalDanio;
}

void solve(){
    cin>>n>>vidaDragon;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    ll ini, mitad, fin;

    //el minimo daño es 1 y el máximo entre todos los casos posibles es 10^18
    ini = 1;
    fin = 1e18;

    while(ini!=fin){
        //la mitad es de esta forma porque busco la primer k que se puede
        mitad= (ini+fin)/2;
        if(venzoAlDragon(mitad))
            fin=mitad;
        else
            ini=mitad+1;
        
    }
    cout<<ini<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCases; 
    cin>>testCases;
    for(int i = 0; i < testCases; ++i){
        solve();
    }
}
