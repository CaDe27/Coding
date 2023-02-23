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

typedef long double ld;
typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007
#define PI 3.14159265358979323846
#define eps ((ld)1e-9)

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)

const int maxN = 100005;

struct vect{
    ld x, y;
    vect(){x = 0; y = 0;}
    vect(ld r, ld s){ x = r; y = s;}
    vect(const vect &a){ x = a.x; y = a.y;}
    

    vect operator+(const vect &a){return vect(x + a.x, y + a.y);}
    vect operator-(const vect &a){return vect(x - a.x, y - a.y);}
    vect operator*(ld a){return vect(a*x, a*y);}
    

    ld norma(){return sqrt(x*x + y*y);}
    ld pCruz(const vect &u){return x*u.x + y*u.y;}
    vect normaliza(){ return vect(x = x/norma(), y = y/norma());}
    vect ortogonal(){ return vect(-y, x);}
    
    //vector perpendicular a this del mismo lado que el vector "a"
    vect perpDir(const vect &a){ 
        if(x*a.y - y*a.x > 0)
            return vect(-y, x);
        else
            return vect(y, -x);
    }
};

//distancia de "a" a la recta que forman b y c
ld distancia(const vect &a, const vect &b, const vect &c){
    ld A, B, C;
    
    //usaremos la formula para una recta Ax + By + C = 0
    // vector director de recta bc es (c.x - b.x, c.y - b.y)
    // y el vector perpendicular es (c.y - b.y, -(c.x - b.x)) = (A, B)
    A = c.y - b.y;
    B = -(c.x - b.x);
    C = -A*c.x - B*c.y;
    return abs(A*a.x + B*a.y + C)/sqrt(A*A + B*B);
}


//calcula la interseccion entre la recta {A -> B} y la recta{ C -> D}
pair<ld, ld> interseccion(const vect &A, const vect &B, const vect &C, const vect &D) 
{
    // Line AB represented as a1x + b1y = c1 
    ld a1 = B.y - A.y; 
    ld b1 = A.x - B.x; 
    ld c1 = a1*(A.x) + b1*(A.x); 
  
    // Line CD represented as a2x + b2y = c2 
    ld a2 = D.y - C.y; 
    ld b2 = C.x - D.x; 
    ld c2 = a2*(C.x)+ b2*(C.y); 
  
    ld determinant = a1*b2 - a2*b1; 
  
    if (determinant == 0) 
        return pair<ld,ld>(C.y, D.y);

    else
    { 
        ld x = (b2*c1 - b1*c2)/determinant; 
        ld y = (a1*c2 - a2*c1)/determinant; 
        return pair<ld,ld>(x, y); 
    } 
} 

//dice si P esta contenido en el segmento A->B
bool contSegm(vect &P, vect& A, vect& B){
    return (B-A).pCruz(P-A) == 0 && (P.x - A.x)*(P.x - B.x)<=0 && (P.y - A.y)*(P.y - B.y)<=0;
    
}

bool seIntersectan( vect &A,  vect &B,  vect &C,  vect &D){
    bool band = false;
    ll c1, c2, c3, c4;
    c1 = (B-A).pCruz(C-A);
    c2 = (B-A).pCruz(D-A);
    c3 = (D-C).pCruz(A-C);
    c4 = (D-C).pCruz(B-C);
    
    //different sides of line
    if(c1*c2 < 0 && c3*c4 < 0)
        band = true;
    
    //one point contained in the other segment
    if(contSegm(C, A, B) ||  contSegm(D, A, B) || contSegm(A, C, D) || contSegm(B, C, D))
        band = true;

    return band;
}

int main() {
    
    
	return 0;
}