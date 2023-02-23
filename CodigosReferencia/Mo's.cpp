#include<iostream>
#include <cmath>
using namespace std;
const int maxN = 100002, maxM = 100002;
int Q, n, resp[maxN];

struct query{
	int L, R, indx;
}q[maxM];

int block;
bool compara(const query &x, const query &y){
	if (x.L/block != y.L/block) 
	        return x.L/block < y.L/block;
    else
	    return x.R < y.R; 
}
 
void queryResult(){
    block = (int)sqrt(n);
    sort(q, q + Q, compara); 
    
    int currL = 1, currR = 1, aux;
    //inicializa datos
    //
 
	int L,R;
    // Traverse through all queries 
    for (int i=0; i<Q; ++i){ 
        // L and R values of current range 
        L = q[i].L;
        R = q[i].R;
        
        while (R < currR){
        	//quita de la derecha
            --currR;
        }
		while (currR < R){
            //agrega hacia la derecha
            ++currR;
        }
        while (currL < L){
        	//quita de la izq
            ++currL;
        }
        while (L < currL){
        	//agrega hacia la izq
            --currL;
        }
       
        //resp[q[i].indx] = //query
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	if(fopen("case.txt","r")) freopen("case.txt","r",stdin);
	cin>>Q;
	for(int i = 0; i < Q; ++i){
		cin>>q[i].L>>q[i].R;
		q[i].indx = i;
	}
	queryResult();
	for(int i = 0; i < Q; ++i)
		cout<<resp[i]<<'\n';
	return 0;
}