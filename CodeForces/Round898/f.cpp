#include <iostream>
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;

const int maxN = 200005;
int h[maxN], a[maxN];
void solve(){
    int n, k; cin>>n>>k;
    loop(i, 0, n) cin>>a[n-1-i];
    loop(i, 0, n) cin>>h[n-1-i];

    int iniPedazo = 0, finPedazo = 0, respSize = 0;
    while(iniPedazo < n){
        //encuentra el pedazo mas grande en el que 
        //el subarreglo cumple la condicion de 
        // divisibilidad
        while(finPedazo < n-1 && h[finPedazo+1]%h[finPedazo] == 0){
            ++finPedazo;
        }

        //en este subarreglo donde se cumple la divisibilidad
        //haz un barrido para encontrar el maximo subarreglo
        // que cumple la suma
        int l = iniPedazo, r = iniPedazo;
        ll sum = a[iniPedazo];
        while(l <= finPedazo){
            //extiendo a la derecha
            while(r < finPedazo && sum + a[r+1] <= k)
                sum += a[++r];
            //si es valido, actualizo
            if(sum <= k)
                respSize = max(respSize, r - l + 1);
            
            //para siguiente iteracion
            sum -= a[l];
            if(r == l)
                sum += a[++r];
            ++l;
        }
        iniPedazo = finPedazo + 1;
        finPedazo = iniPedazo;
    }
    cout<<respSize<<'\n';
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