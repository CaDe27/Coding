#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int mat[n+1][n+1];
	int i, j;
	for(i = 1; i <= n; ++i)
	for(j = 1; j <= n; ++j)
		cin>>mat[i][j];
	int ant[n+1][n+1], act[n+1][n+1], puntaje, d, size, sumaAportada;
	int (*pant)[n+1][n+1] = &ant;
	int (*pact)[n+1][n+1] = &act;
	ant[1][1] = mat[n][n];
	for(int d = 2*n - 2; d >= 1; --d){
		size = d <= n? d: 2*n - d;
		for(i = 1; i <= size; ++i)
		for(j = i; j <= size; ++j){
			puntaje = INT_MIN;
			if(d<n){
				if(i!=j)
					puntaje = (*pant)[i+1][j];
				puntaje = max(puntaje, (*pant)[i][j]);
				puntaje = max(puntaje, (*pant)[i+1][j+1]);
				puntaje = max(puntaje, (*pant)[i][j+1]);
			}
			else{
				if(i!=j)
					puntaje = (*pant)[i][j-1];
				if(i > 1)
					puntaje = max(puntaje, (*pant)[i-1][j-1]);
				if(size != j)
					puntaje = max(puntaje, (*pant)[i][j]);
				if( i > 1 && size != j)
					puntaje = max(puntaje, (*pant)[i-1][j]);
			}
			sumaAportada = d<n? mat[size-i+1][i] + mat[size-j+1][j] : mat[n-i+1][n-size+i] + mat[n-j+1][n-size+j];
			if(i==j)
				sumaAportada/=2;
			puntaje += sumaAportada;
			(*pact)[i][j] = puntaje;
		}
		int (*t)[n+1][n+1] = pact;
		pact = pant; 
		pant = t;
	}
	cout<<(*pant)[1][1]<<"\n";
	return 0;
}