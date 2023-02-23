/*
    una linea queda definida por un vértice y un vector diretor
    si para cuatro puntos, la diferencia entre ellos y un vértice 
    dan un múltiplo del mismo vector, estan en una recta los 5
    
    para no batallar para checar con múltiplos del vector director, 
    dividimos el vector entre el gcd de las coordenadas y dejamos la primera coordenada 
    mayor o igual a cero
*/

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
typedef pair<int,int> pii;
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 200005;
int n; 

int gcd(int a, int b){
    if (a == 0) return b;
    else return gcd(b%a, a); 
}

struct fivev{
    int a[5];
    fivev(){loop(i, 0, 5) a[i] = 0;}
    fivev(int a1, int b1, int c1, int d1, int e1){
        a[0] = a1; a[1] = b1; a[2] = c1; a[3] = d1; a[4] = e1;
    }
    fivev(int b[5]){
        loop(i, 0, 5) a[i] = b[i];
    }

    fivev normaliza(){
        int gcdFive = gcd(a[0], a[1]);
        loop(i, 2, 5) 
            gcdFive = gcd(gcdFive, a[i]);
        if(gcdFive == 0) 
            return *this;
        loop(i, 0, 5)
            a[i] /= gcdFive;
        if(a[0] < 0)
            loop(i, 0, 5)
                a[i] *= -1;

        return *this;
    }

    bool operator ==(const fivev &other) const{
        bool resp = true;
        loop(i, 0, 4)
            if(a[i] != other.a[i])
                resp = false;
        return resp;
    }

    bool operator <(const fivev &other) const{
        int it = 0;
        while(it < 4 && a[it] == other.a[it])
            ++it;
        return a[it] < other.a[it];
    }

    fivev operator -(const fivev &other){
        int b[5];
        loop(i, 0, 5)
            b[i] = a[i] - other.a[i];
        return fivev(b);
    }
};

map<fivev, map<fivev, int> > mx, mo;
vector<fivev> xs, os;

bool winner;
void procesa(map<fivev, map<fivev, int> > &m, vector<fivev> &s, fivev v){
    set<fivev> thisTurn;
    fivev d;
    for(fivev u : s){
        d = (u-v).normaliza();
            m[u][d]++;
            if(m[u][d] == 4)
                winner = true;
    }
    s.push_back(v);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    int a, b, c, d, e, f;
    char player;
    loop(i, 0, t){
        cin>>a>>b>>c>>d>>e>>player;
        if(player == 'X')
            procesa(mx, xs, fivev(a,b,c,d,e));
        else
            procesa(mo, os, fivev(a,b,c,d,e));
        if(winner){
            cout<<player<<" "<<(i+1)<<"\n";
            break;
        }
    }
    if(!winner){
        cout<<"DRAW\n";
    }
    return 0;

}