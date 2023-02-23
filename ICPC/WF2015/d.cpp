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
#include <iomanip>

using namespace std;

typedef int64_t ll;
typedef long double ld;
typedef pair<int,int> pii;

#define INF 1000000000000
#define PI 3.14159265358979323846

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 1e4+5;
int n, s;
ld zs[maxN], rs[maxN];
ld resp[maxN], den, h, volCorte, vol[maxN];


ld volumen(ld z){
    ld volIni = (1e10)*z;
    loop(i, 0, n){
        //no quito nada
        if(z <= zs[i]-rs[i]) continue;
        //quito toda
        else if(zs[i] + rs[i] <= z){
            volIni -=  (4*PI * rs[i] * rs[i] * rs[i])/3;
        }
        //el centro esta despues
        //quito el segmento de esfera
        else if( z <= zs[i]){
            h = z - (zs[i]-rs[i]);
            volIni -= (PI/3 * h * h * (3*rs[i] - h));
        }
        //el centro esta antes 
        //quito la esfera completa y le aumento el segmento de esfera
        else{
            h = zs[i]+rs[i]-z;
            volIni = volIni - vol[i] + (PI/3 * h * h * (3*rs[i] - h));
        }
    }
    return volIni;
}

ld binsearch(int times){
    
    ld ini = 0, fin=100000, mitad;
    ld target = volCorte * times;
    loop(i, 0, 50){
        mitad = (ini + fin)/2;
        if(volumen(mitad) < target){
            ini = mitad;
        }
        else
            fin = mitad;
    }
    return ini;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    //leer cheese
    // encontrar volumen de piececita = v
    // el primer slice 1v, el sefundo 2v, ... hasta sv
    // para cada nuno bin search de 100

    cin>>n>>s;
    ld sumaCubos = 0;
    loop(i, 0, n){
        cin>>rs[i]>>zs[i]>>zs[i]>>zs[i];
        vol[i] = 4*PI/3*rs[i]*rs[i]*rs[i];
    }
    
    //calculo el volumen que debe tener cada corte
    ld volOriginal = 1e15;
    loop(i, 0, n){
        volOriginal -= vol[i];
    }
    volCorte = volOriginal/s;
    
    resp[0] = 0;
    loop(i, 1, s+1)
        resp[i] = binsearch(i);        

    loop(i, 1, s+1)
        cout<<fixed<<setprecision(7)<<(resp[i]-resp[i-1])/1000<<"\n";
    return 0;
}