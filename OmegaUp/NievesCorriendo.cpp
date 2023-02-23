#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

/*
//https://omegaup.com/arena/problem/Nieves-Corriendo#problems
// para simular las dos carreras, considero dos caminos que inician ambos en la
//		casilla (1,1) y en cada paso se tienen cuatro opciones, abajo-abajo, 
//		derecha-derecha, abajo-derecha, derecha-abajo
// la dp consiste en un bottom-up que encuentra el maximo puntaje entre las dos 
//		casillas actuales y el final
// cada estado se define en base a la diagonal en la que se encuentran los caminos
//		y el numero de la casilla relativo a la diagonal.
//		i.e. la casilla dos de la diagonal dos realmente es la casilla (1, 2)
//		y la casilla uno de la diagonal dos es (2,1)
*/
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int mat[n+1][n+1];
	int i, j;
	for(i = 1; i <= n; ++i)
	for(j = 1; j <= n; ++j)
		cin>>mat[i][j];
	/*
	// en pAnt vamos a guardar los datos de la diagonal que antes hicimos
	// e iremos guardando los datos la actual en *pAct
	//
	// d es el numero de la diagonal
	// size el tamanio de la diagonal
	// sumaAportada la suma que aportan las casillas actuales
	// puntaje primero guarda el puntaje maximo de entre los caminos posibles a 
	//		seguir y luego le sumamos sumaAportada para ser el puntaje maximo desde 
	//		las casillas actuales hasta el final
	// i y j pasan a representar la casilla en la diagonal del primer y segundo
	//		camino respectivamente
	// spg i<=j
	*/
	int ant[n+1][n+1], act[n+1][n+1];
	int (*pAnt)[n+1][n+1] = &ant;
	int (*pAct)[n+1][n+1] = &act;
	int puntaje, d, size, sumaAportada;
	ant[1][1] = mat[n][n];
	
	for(int d = 2*n - 2; d >= 1; --d){
		size = d <= n? d: 2*n - d;
		for(i = 1; i <= size; ++i)
		for(j = i; j <= size; ++j){
			puntaje = INT_MIN;
			/*
			// las cosas son diferentes dependiendo de que lado de la diagonal 
			// principal estes
			// si estas en la diagonal d y en la casilla x
			// si d < n 
			//		abajo: diagonal d+1 casilla x
			//		derecha: diagonal d+1 casilla x+1
			//		pos relativas al eje x y al eje y: (size-(x-1), x)
			// si d >= n
			//		abajo: diagonal d+1 casilla x-1
			//		derecha: diagonal d+1 casilla x
			//		pos relativas al eje x y al eje y: (size-(x-1), x):
			//			(n - (x-1) , (n-size)+x)
			*/
			if(d<n){
				//der-abajo; abajo abajo; der der; abajo der 
				if(i!=j) //si son iguales aqui se romperia i<=j
					puntaje = (*pAnt)[i+1][j];
				puntaje = max(puntaje, (*pAnt)[i][j]);
				puntaje = max(puntaje, (*pAnt)[i+1][j+1]);
				puntaje = max(puntaje, (*pAnt)[i][j+1]);
				sumaAportada = mat[size-i+1][i] + mat[size-j+1][j];
			}
			else{
				/*
				//der-abajo; abajo abajo; der der; abajo der 
				// si i > 1 si tiene abajo
				// si j != size tiene derecha
				*/
				if(i!=j)
					puntaje = (*pAnt)[i][j-1];
				if(i > 1)
					puntaje = max(puntaje, (*pAnt)[i-1][j-1]);
				if(size != j)
					puntaje = max(puntaje, (*pAnt)[i][j]);
				if( i > 1 && size != j)
					puntaje = max(puntaje, (*pAnt)[i-1][j]);
				sumaAportada = mat[n-i+1][n-size+i] + mat[n-j+1][n-size+j];
			}
			//si i == j solo sumas una vez la casilla
			if(i==j)
				sumaAportada/=2;
			puntaje += sumaAportada;
			(*pAct)[i][j] = puntaje;
		}
		// *pAct pasa a ser la anterior, y *pAnt la usamos para la nueva
		int (*t)[n+1][n+1] = pAct;
		pAct = pAnt; 
		pAnt = t;
	}
	cout<<(*pAnt)[1][1]<<"\n";
	return 0;
}