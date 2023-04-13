#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;
typedef long long ll;
 
struct PT{
	double x,y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT(const PT&p) : x(p.x), y(p.y) {}
	PT operator + (const PT &p) const {return PT(x+p.x,y+p.y);}
	PT operator - (const PT &p) const {return PT(x-p.x,y-p.y);}
	PT operator * (double c) const {return PT(x*c,y*c);}
	PT operator / (double c) const {return PT(x/c,y/c);}
	bool operator < (const PT &p) const {return x<p.x||(x==p.x && y<p.y);}
};

double dot(PT p, PT q){
	return p.x*q.x + p.y+q.y;
}

double dist2(PT p, PT q){
	return dot(p-q,p-q);
}

double cross(PT p, PT q){
	return p.x*q.y-p.y*q.x;
}

vector<PT> ConvexHull(vector<PT> &P){
	sort(P.begin(),P.end());
	vector<PT> U,L;
	for(int i=0;i<P.size();i++){
		while(L.size() > 1 && cross(L[L.size()-1]-L[L.size()-2],P[i]-L[L.size()-2]) > 0)
			L.pop_back();
		L.push_back(P[i]);
	}
	if(L.size() > 1) L.pop_back();
	for(int i=P.size()-1;i >=0 ; i--){
		while(U.size() > 1 && cross(U[U.size()-1]-U[U.size()-2],P[i]-U[U.size()-2]) > 0)
			U.pop_back();
		U.push_back(P[i]);
	}
	if(U.size() > 1) U.pop_back();
	L.insert(L.end(),U.begin(),U.end());
	return L;
}

int req(PT p, PT q){
    int A = max(abs((p-q).x),abs((p-q).y));
    if((p-q).x == (p-q).y) A++;
    return A;
}

long double expo(long double base, int exp){
    if(exp == 0) return 1;
    if(exp == 1) return base;
    long double c = expo(base,exp/2);
    c = c*c;
    if(exp & 1){
        c *= base;
    }
    return c;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,P,k; cin >> n >> P >> k;
    
    long double Q[n+1];
    
    Q[0] = 0;
    
    long double S = 0;
    long double ans = 0;
    
    for(int i=1;i<=n;i++){
        Q[i] = i; Q[i] /= n;
        Q[i] = expo(Q[i],k);
        Q[i] -= S;
        if(i < P){
            ans += Q[i]*P;
        }
        else{
            ans += (Q[i]/2)*(i+1);
        }
            
        S += Q[i];
    }
    
    cout << fixed << setprecision(6) << ans << "\n";
    
    
    
    return 0;
}