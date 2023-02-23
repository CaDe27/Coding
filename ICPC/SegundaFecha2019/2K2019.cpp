#include <iostream>
#include <stack>
#define pt pila.top()
using namespace std;
/*
	Segunda fecha ICPC Mexico 2019
	http://coj.uci.cu/24h/problem.xhtml?pid=4258
	Para un caso mas general vea https://omegaup.com/arena/problem/Loca-People#problems
	 del que tambien tengo una entrada
*/

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//variables del problema
	int max = 0, n, m;
	cin>>n>>m;
	//variables de trabajo
	int i, j, aux;
	int h[n+1][m+2];
	fill(h[0], h[0]+m+2, 0);
	//el cero que va a sacar todas las alturas
	for(i = 1; i <= n; ++i)
		h[i][m+1] = 0;
	
	//la lectura de las alturas depende del problema
	//pero, en general se obtiene la altura (desde esa entrada hacia arriba) de h[i][j]
	for(i = 1; i <= n; ++i)
	for(j = 1; j <= m; ++j){
		cin>>aux;
		h[i][j] = aux==0? 1+h[i-1][j]:0;
	}
	/*
	//"destruyendo edificios"  
	//(https://omegaup.com/arena/problem/DesEdificios#problems)
	//va a ayudar a ver cuanto se extiende una determinada altura, tanto a la derecha
	// como a la izquierda
	
	// a diferencia de en Loca People, aqui no se usa el arreglo extiende porque
	//se busca el de toda la matriz, y el arreglo extiende ayuda cuando se va a pedir
	//entre dos filas en especifico 
	*/
	stack<pair<int, int> >pila;
	int como, h_, perimetro;
	for(i = n; 2*(i+m) > max && i > 0; --i)
	for(j = 1; j <= m+1; ++j){
			h_ = h[i][j];
			como = 0;
			while(!pila.empty() && h_ <= pt.first){
				como += pt.second + 1;
				//como es lo que se extiende la altura del tope
				//checa si tienes que actualizar el maximo perimetro
				if( pt.first>0 && (perimetro=2*(pt.first + como)) > max)
					max = perimetro;
				pila.pop();
			}
			pila.push({h_, como});
		}	
	cout<<max<<"\n";
	return 0;
}