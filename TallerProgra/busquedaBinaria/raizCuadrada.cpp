//codigo para calcular raiz entera de un numero entre 0 y 10^12
#include <iostream>
using namespace std;
typedef int64_t ll;


ll raizEntera(ll M){
    ll ini, mitad, fin;
	
	//defino cotas
    ini = 0;
    fin = 1000000;
    
	//mientras mi espacio de busqueda no sea de un solo elemento, sigo reduciendolo
    while(ini!=fin){
        mitad= (ini+fin+1)/2;
        
        if( mitad*mitad <= M)
            ini = mitad;
        else
            fin=mitad-1;
    }
    	
    return ini;
}

int main(){
	ll M;
	cin>>M;
	
	cout<<raizEntera(M)<<"\n";
	
	return 0;
}