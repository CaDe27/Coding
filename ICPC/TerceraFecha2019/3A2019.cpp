#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*problema A tercera fecha ICPC Mexico 2019
//https://www.urionlinejudge.com.br/judge/en/problems/view/2962

//basicamente, el problema se reduce a dando un rectangulo y dos vertices opuestos,
				   b
		     ___________		//sean c y d paredes iniciales, 
		a	|			| c		// y a y b paredes finales
			| __________|
				  d
			
// verificar si existe una cadena de círculos que una a una pared inicial con una final

// de haber un camino que cumpla esto, debera estar uno de sus circulos conectado
// a la inicial, y el ultimo conectado a la final

//lo que hacemos es primero meter todos los ciculos que estan conectados a una de
//las paredes iniciales a una lista que llamamos "camino" y los demas a una que 
//se llame "espera"

//despues, en cada paso, veremos para cada circulo en espera si esta conectado
//con algunos de los que estan ahora en camino, de ser asi, pasara a la nueva
// lista camino. Si no, pasara a la nueva lista espera.

//Los circulos que estan actualmente en camino seran eliminados despues de checar 
//donde estan todos los de espera, pues, de pertenecer a un camino que bloquea, 
//ya habrian conectado con el siguiente circulo en ese camino

//las iteraciones continuan mientras haya circulos tanto en camino como en espera,
// de no haber en alguna, quiere decir que no hay tal camino

//es claro que no se entra en un ciclo infinito porque en cada iteracion se 
// eliminan circulos "del total", y se genera una nueva lista de camino que a su
// vez se eliminara, o de no haber, acabara el proceso
// como la cantidad de circulos del sistema siempre decrece o camino se queda 
// sin circulos, hay un fin

//tambien siempre se garantiza la solucion correcta. De hecho, si hay varios caminos, 
//y el menor tiene tamanio z, entonces en z iteraciones acaba el proceso. Pues, 
//	en cada iteracion se conecta con el siguiente circulo.

// la complejidad es en el peor de los casos, k^2, en el caso de que se vaya metiendo
// solo un elemento a camino en cada iteracion, de modo que se hacen
// k comparaciones en la primera
// k-1 en la segunda
// ...
// 1 en la ultima
// con un total de k*(k+1)/2
// y la complejidad es O(k^2), pero funciona pues k <= 1000
// y en el peor del mejor de los casos es O(k+(k-1)+...+(k-(z-1))) = O(k*z - z*(z-1)/2)
  = O((z)((k-z+1)/2) = O(z(k-z)) 
*/
int n, m;

struct circulo{
	int x, y, s;
};

//te dice si dos circulos se intersectan
bool conectados(circulo a, circulo b){
	return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2)) <= a.s + b.s;
}

//te dice si el circulo toca a una de las paredes "finales"
bool conectadoFin(circulo c){
	return c.x <= c.s || n - c.y <= c.s;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
	//leemos los datos
	int k;
	cin>>m>>n>>k;
	circulo c;
	vector<circulo> espera, camino, auxEspera, auxCamino;
	//si el circulo toca la pared inicial lo meto a camino
	//si no, a espera
	for(int i = 0; i < k; ++i){
		cin>>c.x>>c.y>>c.s;
		//si estas concetado a la pared inicial
		if(m - c.x <= c.s || c.y <= c.s){
			//si estas conectado a ambas, acabas
			if(conectadoFin(c)){
				cout<<"N\n";
				return 0;
			}
			else
				camino.push_back(c);
		}
		else
			espera.push_back(c);
	}
	
	//realiza el proceso de ir buscando los circulos en secuencia con los que
	//estan en camino
	int i, s;
	bool conectado;
	while(!camino.empty() && !espera.empty()){
		s = camino.size();
		for(circulo c:espera){
			i = 0;
			conectado = false;
			while(i < s && !conectado){
				if(conectados(c, camino[i])){
					conectado = true;
					//si perteneces a una secuencia de las paredes iniciales
					//y tocas la final, si hay camino que obstruye
					if(conectadoFin(c)){
						cout<<"N"<<endl;
						return 0;
					}
					else
						auxCamino.push_back(c);
					//pues solo me interesa conectarlo a uno
				}
				++i;
			}
			if(!conectado)
				auxEspera.push_back(c);
		}
		camino.clear(); espera.clear();
		swap(camino, auxCamino);swap(espera, auxEspera);
	}
	//si llega aqui, no hay secuencia de sensores que conecte a las paredes;
	cout<<"S\n";
	return 0;
}
