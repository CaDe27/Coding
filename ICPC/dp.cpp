
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD  1000000009
#define modula(a,b) ((a%b + b)%b)

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxB = 128 + 3, maxK = 1000+5;
int  k, b;
ll invK;

ll pot2[129];
ll binPow(ll base, ll exp){
	ll r = 1;
	while (exp > 0){
		if(exp & 1)
			r = (r*base) % MOD;
		exp >>= 1;
		base = (base * base) % MOD;
	}
	return r%MOD;
} 

ll menor[maxB][maxK];
//devuelve cuantas unidades hay de diferencia entre
// el último m+rk que no pasa 2^bi - 1 y 2^bi - 1 mismo
bool vMenor[maxB][maxK];
ll DPmenor(int bi, int ki){
    //si ya me pase o ya me voy a pasar, regreso mi distancia dirigida a la potencia
    if(bi < 11 && (ki > pot2[bi]-1 || ki + k > pot2[bi]-1) )
        return pot2[bi]-1 - ki;
    
    if(!vMenor[bi][ki]){
        vMenor[bi][ki] = 1;
        //si todavia no me paso, me trato de dividir en dos como en la DP
        ll nuevoP = (bi>=11 || ki<=pot2[bi-1])? k - DPmenor(bi-1, ki) - 1 : ki - pot2[bi-1];
        menor[bi][ki] = DPmenor(bi-1, nuevoP);
    }
    return menor[bi][ki];
}

ll saltos[maxB][maxK];
bool vSaltos[maxB][maxK];
ll DPsaltos(int bi, int ki){
     //si ya me pase o ya me voy a pasar, son 0 saltos
    if(bi < 11 && (ki > pot2[bi]-1 || ki + k > pot2[bi]-1) )
        return 0; 

    if(!vSaltos[bi][ki]){
        vSaltos[bi][ki] = 1;

        ll resp = 0, nuevoP;
        if( bi>=11 || (ki <= pot2[bi-1]-1) ){ 
            nuevoP = k - DPmenor(bi-1, ki) - 1;
            //sumo un salto de cuando llego al nuevo pivote
            resp = (DPsaltos(bi-1,ki) + 1)%MOD;
        }
        else{
           nuevoP = ki - pot2[bi-1];
        } 
        resp = (resp+ DPsaltos(bi-1, nuevoP))%MOD;

        saltos[bi][ki] = resp;
    }  
    return saltos[bi][ki];
}



ll dp[maxB][maxK];
bool visited[maxB][maxK];

ll DP(int bi, ll ki){

    //entre 0 y 0, la respuesta es 0
    if(bi == 0)
        return 0;

    //si eres mayor que el limite, es cero
    if( bi < 11 && ki > pot2[bi]-1)
        return 0;

    if(!visited[bi][ki]){
        visited[bi][ki] = 1;
        ll resp = 0;
        ll nuevoPivote;
        //en la primera mitad
            //si cabes
            // como ki <= 1000, cabes si la potencia es al menos 11 (2^10 = 1024)
            // o sino, directo puedes checar si cabes
            if( bi>=11 || (ki <= pot2[bi-1]-1) ){
                resp = DP(bi-1, ki)%MOD;
                //tu posicion relativa a la nueva potencia
                // 2^(bi-1) es el nuevo cero
                nuevoPivote = k - DPmenor(bi-1, ki) - 1;
            }
            //si no cupiste, el nuevo pivote es tu posicion reltaiva a 2^(bi-1)
            else{
                nuevoPivote = ki - pot2[bi-1];
            }
        //en la segunda mitad
            //las mismas pregntas que en la primera mitad
            //para ver si hay un multiplo tuyo en esta mitad
            if( bi>=11 || nuevoPivote <= pot2[bi-1]-1 ){
                //dp desde el nuevo pivote
                resp = (resp + DP(bi-1, nuevoPivote) )%MOD;

                //aumento los bits fijos
                //la cantidad de saltos de tamanio k que puedes dar, mas el inicial
                resp = (resp + 1+DPsaltos(bi-1, nuevoPivote))%MOD;
            }     
        dp[bi][ki] = resp; 
    }
    return dp[bi][ki];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    cin>>k>>b;

    pot2[0] = 1;
    loop(i, 1, 129)
        pot2[i] = (pot2[i-1]*2)%MOD;
    
    cout<<DP(b, k)<<"\n";
    
}

