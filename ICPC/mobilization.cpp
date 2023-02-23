
//sacamos convex hull de los puntos
// sobre cada lado sacamos el maximo valor de xy
//  en el intervalo




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

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


struct PT {
    double x,y;
    PT(){};
    PT(double x, double y) : x(x), y(y){}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const {  return PT(x+p.x, y+p.y);  }
    PT operator - (const PT &p) const {  return PT(x-p.x, y-p.y);  }
    bool operator < (const PT &p) const { return x < p.x || (x == p.x && y < p.y);}
};

double cross(PT p, PT q)    {return p.x*q.y - p.y*q.x;}

vector < PT > ConvexHull(vector < PT > &P){ 
    sort(P.begin(), P.end());
    vector<PT>U,L;
    for(int i = 0; i < P.size(); i++){
        while(L.size() > 1 && cross(L[L.size()-1]-L[L.size()-2], P[i]-L[L.size()-2]) > 0)
            L.pop_back();
        L.push_back(P[i]);
    }
    if(L.size() > 1) L.pop_back();
    for(int i = P.size()-1; i >= 0; i--){
        while(U.size() > 1 && cross(U[U.size()-1]-U[U.size()-2], P[i]-U[U.size()-2]) > 0) 
            U.pop_back();
        U.push_back(P[i]);
    }
    if(U.size() > 1) U.pop_back();
    L.insert(L.end(), U.begin(), U.end());
    return L;
}

double maxVal(const PT &p, const PT &q){
    
    if(p.x == q.x)
        return max(p.y*p.x, q.y*p.x);
    else{
        double m = (p.y - q.y) / (p.x - q.x);
        double b = p.y - m*p.x;
        
        double exp1, exp2;
        exp1 = p.x*p.x*m + b*p.x;
        exp2 = q.x*q.x*m + b*q.x;
        if(m >= 0)
            return max(exp1, exp2);
        else{
            double x2 = max(p.x, q.x), x1 = (min(p.x, q.x));
            if(x1 <= -b/(2*m) && -b/(2*m) <= x2)
                return -b*b/(4*m);
            else{
                return max(exp1, exp2);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n; double C;
    cin>>n>>C;
    vector<PT> points(n);
    loop(i, 0, n){
        double c,h,p;
        cin>>c>>h>>p;
        points[i] = PT(h/c,p/c);
    }

    vector<PT> polygon = ConvexHull(points);

    int sizeP = polygon.size();
    double resp = 0;
    PT act, sig;
    loop(i, 0, sizeP){
        act = polygon[i];
        sig = polygon[ (i+1)%sizeP ];
        resp = max(resp, maxVal(act, sig));
    }

    cout<<setprecision(2)<<fixed<<C*C*resp<<"\n";

    return 0;

}
