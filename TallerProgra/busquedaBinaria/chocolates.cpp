#include <iostream>
using namespace std;
typedef int64_t ll;
 
 
const int maxN = 1e5 + 5;
int n;
ll paga[maxN];


bool sePuede(ll dieta){
    //para cada dia
    //recibir los chocolates
    // y comer
    //si despues de comer tengo una cantidad negativa, no tenia suficientes
    ll totalChocolates = 0;
    bool respuesta = true;
    int i = 0;
    while(i < n && respuesta==true){
        totalChocolates += paga[i];
        totalChocolates -= dieta;
        if(totalChocolates < 0)
            respuesta = false;
        ++i;
    }
    return respuesta;
}

ll maxChocolates(){
    ll ini, mitad, fin;
 
	//defino cotas
    ini = 0;
    fin = paga[0];
 
	//mientras mi espacio de busqueda no sea de un solo elemento, sigo reduciendolo
    while(ini!=fin){
        mitad= (ini+fin+1)/2;
 
        if(sePuede(mitad))
            ini = mitad;
        else
            fin=mitad-1;
    }
 
    return ini;
}
 
int main(){
	cin>>n;
    for(int i = 0; i < n;++i){
        cin>>paga[i];
    }
 
	cout<<maxChocolates()<<"\n";
 
	return 0;
}