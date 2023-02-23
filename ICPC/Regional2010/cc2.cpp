#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef int64_t ll;

struct vect{
    ll x, y;
}puntos[105];

vect dif(const vect &a, const vect &b){
    vect n;
    n.x = a.x - b.x;
    n.y = a.y - b.y;
    return n;
}


ll dist2(const vect &a, const vect &b){
    return (a.x-b.x)*(a.x-b.x) + (a.y - b.y)*(a.y - b.y);
}

//como trabajamos con vectores en R2 solo nos importa la componente en z del producto cruz
ll pcruz(const vect &a, const vect &b){
    return a.x*b.y - a.y*b.x;
}

bool colineales(const vect &a, const vect &b, const vect &c){
    return pcruz(dif(a,b), dif(a,c)) == 0;
}

bool conciclicos( vect a, vect b,  vect c, vect d){
    //reordenamos de forma que ac sea diagonal
    //probamos si a y b son diagonall
        if(pcruz(dif(b,a), dif(c,a)) * pcruz (dif(b,a), dif(d,a)) < 0){
            vect aux = b;
            b = c;
            c = aux;
        }
        
        //si a  y d son una diagonal
        else if(pcruz(dif(d,a), dif(c,a)) * pcruz (dif(d,a), dif(b,a)) < 0){
            vect aux = d;
            d = c;
            c = aux;
        }
        //probamos el teorema de ptolomeo (version doblemente al cuadrado)
        ll exp = (dist2(a,c)*dist2(b,d) - dist2(a,b)*dist2(d,c) - dist2(b,c)*dist2(a,d));
        return   exp*exp == 4*dist2(a,b)*dist2(a,d)*dist2(b,c)*dist2(c,d);
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while(n != 0){
        for(int i = 0; i < n; ++i)
            cin>>puntos[i].x>>puntos[i].y;
        int resp = min(2, n), contador;
        for(int i = 0; i < n; ++i)
        for(int j = i+1; j < n; ++j)
        for(int k = j+1; k < n; ++k){
            if(!colineales(puntos[i], puntos[j], puntos[k])){
                contador = 3;
                for(int d = k+1; d < n; ++d){
                    if(conciclicos(puntos[i], puntos[j], puntos[k], puntos[d]))
                        ++contador;
                }
                if(contador > resp)
                    resp = contador;
            }
        }
        cout<<resp<<'\n';
        cin>>n;
    }


}