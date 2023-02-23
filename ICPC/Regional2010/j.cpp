#include <iostream>
#include <algorithm>
using namespace std;

bool simula(int a, int b, int c, int d, int e, int f){
    int gano = 0;
    if(a < d)
        ++gano;
    if(b<e)
        ++gano;
    if(c < f)
        ++gano;
    return gano>=2;
}

bool juego(int a, int b, int c, int d, int e, int f){
    bool ganoTodas = true;
    int p1[] = {a,b,c}, p2[] = {d,e,f};
    sort(p2, p2+3);
    do{
        sort(p1, p1+3);
        do{
            ganoTodas = simula(p1[0],p1[1],p1[2],p2[0],p2[1],p2[2]);
        }while(next_permutation(p1, p1+3) && ganoTodas);
    }while(next_permutation(p2, p2+3) && ganoTodas); 
    return ganoTodas;
}

int main(){
    int a, b, c, d, e ,f;
    cin>>a>>b>>c>>d>>e;
    while(!( a==0 && b == 0 && c==0 && d == 0 && e == 0)){
        bool ganaComoSea = false;
        int f = 0;
        for(int i = 1; i <= 52 && !ganaComoSea; ++i){
            f = i;
            if(f!=a && f!= b && f!=c && f!= d && f!=e)
                ganaComoSea=juego(a,b,c,d,e,f);
        }
        cout<<(ganaComoSea? f:-1)<<endl;
        cin>>a>>b>>c>>d>>e;
    } 
}