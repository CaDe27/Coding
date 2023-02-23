
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
#include <sstream>

using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

typedef int64_t ptype;
struct PT {
    ptype x,y;
 
    PT(){};
    PT(ptype x, ptype y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const {  return PT(x+p.x, y+p.y);  }
    PT operator - (const PT &p) const {  return PT(x-p.x, y-p.y);  }
    bool operator < (const PT &p) const { return x < p.x || (x == p.x && y < p.y);}
    bool operator == (const PT &p) const {return x == p.x && y == p.y;}
    
    int cuad(){
        if(x > 0 && y >= 0) return 0;
        if(x <= 0 && y > 0) return 1;
        if(x < 0 && y <=0) return 2;
        return 3;
    }  
    ptype pp(const PT &p) {return x*p.x + y*p.y;}
    bool paralelo(const PT &p){
        PT ort = PT(y, -x);
        return ort.pp(p) == 0;
    }
    bool aMiDer(const PT &p ){
        PT ort = PT(y, -x);
        if(ort.cuad() != (cuad() - 1 + 4)%4) 
            ort = PT(-y, x);
        return ort.pp(p) > 0;
    }
    bool aMiIzq(const PT &p){return !paralelo(p) && !aMiDer(p);}

    void print(){cout<<x<<" "<<y<<endl;}
};
ptype cross(const PT &a, const PT &b){return a.x*b.y - a.y*b.x;}
 
typedef long double ld;
int n; 
vector<PT> pol;
ll resp = 0;
ll area;
//esta multiplicada por dos
ll gauss(){
    ll sumax = 0, sumay = 0;
    loop(i, 0, n){
        sumax += pol[i].x * pol[(i+1)%n].y;
        sumay += pol[i].y * pol[(i+1)%n].x;
    }
    return abs(sumax - sumay);
}

ll gaussTri(const PT &a, const PT &b, const PT &c){
    ll sumax = 0, sumay = 0;
    sumax = a.x*b.y + b.x*c.y + c.x*a.y;
    sumay = a.y*b.x + b.y*c.x + c.y*a.x;
    return abs(sumax - sumay);
}
void solve(){
    //calcula area  total
    resp = 0;
    ll area = gauss();
   
    //inicializa cosas
    int pivote = 0;
    //encuentro los dos entre los que esta la mitad del area
    ll area1= gaussTri(pol[0], pol[1], pol[2]);
    int indx = 2;
    ll aux = gaussTri(pol[indx], pol[(indx+1)%n], pol[pivote]);
    while( 2*area1 < area ){
        area1 += aux; 
        ++indx;
        aux = gaussTri(pol[indx], pol[(indx+1)%n], pol[pivote]);
    }

    --indx;
    aux = gaussTri(pol[indx], pol[(indx+1)%n], pol[pivote]);
    area1 -= aux;

    resp = max(resp, min(area-area1, area1+aux));
    //por cada punto
    loop(i, 1, n){
        ++pivote;
        area1 -= gaussTri(pol[pivote-1], pol[pivote], pol[indx%n]);
        aux = gaussTri(pol[indx%n], pol[(indx+1)%n], pol[pivote]);
        while( 2*area1 < area){
            area1 += aux; 
            ++indx;
            aux = gaussTri(pol[indx%n], pol[(indx+1)%n], pol[pivote]);
        }

        --indx;
        aux = gaussTri(pol[indx%n], pol[(indx+1)%n], pol[pivote]);
        area1 -= aux;
        resp = max(resp, min(area-area1, area1+aux));
     }
    // encuentro siguiente contrario
    // eligo uno de los dos
    // actualizo par resp si el maximo es mayor que el actual

    //imprimo resp
    cout<<resp<<" "<<area-resp<<endl;
}

int main(){
    while(cin>>n){
        pol.clear();
        pol.resize(n);
        loop(i, 0, n){
            cin>>pol[i].x>>pol[i].y;
        }
        solve();
    }


}
