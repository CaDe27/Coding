#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
void generaPin(int pin[], int n){
	int vp5[n+1], vp2[n+1], vp52[n+1];
	long long pot2[n+1];
	fill(vp2, vp2+n+1, 0);
	fill(vp5, vp5+n+1, 0);
	pin[1] = 1;
	vp52[1] = 1;
	
	int pot, mp, mm; 
	pot = 1; 
	mp =(int)(log(n)/log(2));
	for(int i = 1; i <= mp;++i){
		pot= pot*2;
		mm = n/pot;
		for(int j = 1; j<=mm; ++j)
			++vp2[pot*j];
	}
	pot = 1;
	mp =(int)(log(n)/log(5));
	for(int i = 1; i <= mp;++i){
		pot*=5;
		mm = n/pot;
		for(int j = 1; j<=mm; ++j)
			++vp5[pot*j];
	}
 
	pot2[0] = 1;
	pot2[1] = 2;
	for(int i = 2; i <= n; i++)
		pot2[i] = (pot2[i-1]*2)%100000;

	long long aux;
	int k;
	for(int i = 2; i <= n; ++i){
		aux = 1;
		k = i;
		k /= pot2[vp2[i]];
		k /= pow(5,vp5[i]);
		aux *= vp52[i-1];
		vp52[i] = (aux*k)%100000;
		vp2[i] += vp2[i-1];
		vp5[i] += vp5[i-1];
		aux = pot2[vp2[i]-vp5[i]];
		pin[i] = (aux*vp52[i])%100000;
	}
}
 
int getSumBIT(int BIT[], int index){ 
    int sum = 0;
    for(;index>0;index -= (index & (-index)))
        sum += BIT[index];  
    return sum; 
} 
 
void updateBIT(int BIT[], int index, int val){ 
    for(;index<=100000;index += (index & (-index)))
       BIT[index] += val;
} 
 
struct query{
	int L, R, indx, x, y;
};

int block;
bool compara(const query &x, const query &y){
	if (x.L/block != y.L/block) 
	        return x.L/block < y.L/block; 
	    return x.R < y.R; 
}
 
void queryResult(query q[], int r[], int Q, int pin[], int n){
    block = (int)sqrt(n);
    sort(q, q + Q, compara); 
    
    int BIT[n+1], currL = 1, currR = 1, aux;
    fill(BIT, BIT+n+1, 0);
    updateBIT(BIT,pin[1], 1);
 
	int L,R;
    // Traverse through all queries 
    for (int i=0; i<Q; ++i){ 
        // L and R values of current range 
        L = q[i].L;
        R = q[i].R;
        
        while (R < currR){
        	updateBIT(BIT,pin[currR], -1);
            --currR;
        }
		while (currR < R){
            updateBIT(BIT,pin[currR+1], 1);
            ++currR;
        }
        while (currL < L){
        	updateBIT(BIT,pin[currL], -1);
            ++currL;
        }
        while (L < currL){
        	updateBIT(BIT,pin[currL-1], 1);
            --currL;
        }
       
        r[q[i].indx] = getSumBIT(BIT,q[i].y) - getSumBIT(BIT,(q[i].x)-1);
    }
}
 
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(fopen("case.txt","r")) freopen("case.txt","r",stdin);
	int n = 100000;
	int pin[n+1];
	generaPin(pin, n);
	int Q;
	cin>>Q;
	int r[Q];
	query q[Q];
	for(int i = 0; i < Q; ++i){
		cin>>q[i].L>>q[i].R>>q[i].x>>q[i].y;
		q[i].indx = i;
	}
	queryResult(q, r, Q, pin, n);
	for(int i = 0; i < Q; ++i)
		cout<<r[i]<<'\n';
	return 0;
}

