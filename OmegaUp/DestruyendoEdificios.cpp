#include <iostream>
#include <stack>
#define etop extiende.top()
using namespace std;
//https://omegaup.com/arena/problem/DesEdificios#problems

int N;
long areaMax = 0;
stack< pair<int, int> > extiende;

void actualiza(long area){
	if(area > areaMax)
		areaMax = area;
}

void agrega(int altura){
	long long area, comoDer = 0;
	//como Der es los que el edificio que voy a quitar se puede extender a la derecha
	int comoIzq = 0; //los que el edificio que entra se puede extender a la izq
	while(!extiende.empty() && altura <= etop.first){
		comoIzq += etop.second + 1;
		area = (comoDer + etop.second + 1) * etop.first; 
		//area abarcada por el edificio que quitas
		// (los que come a la der + los que come a la izq + si mismo) * su altura
		actualiza(area);
		comoDer += etop.second + 1; 
		// los que se comio a la izq el que acabas de sacar, tambien son mas
		// altos que el que esta antes en la pila entonces los come a la derecha
		// y 1 por el que sacas de la pila
		extiende.pop();
	}
	extiende.push(make_pair(altura, comoIzq));
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	int altura;
	cin>>N;
	for(int i = 0; i < N; i++){
		cin>>altura;
		agrega(altura);
	}
	agrega(0); //para contar el area abarcada por los ultimos edificios
	cout<<areaMax<<endl;
		return 0;
}