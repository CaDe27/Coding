#include <iostream>
using namespace std;
typedef int64_t ll;

bool siPasa(){
    return true;
}

int binSearch(){
    ll ini, mitad, fin, cotaSuperior;
	
    ini = 0;
    fin = cotaSuperior;

    while(ini!=fin){
        //no siempre mitad se calcula de la misma forma
        mitad= (ini+fin)/2;
        
        if(siPasa())
            fin=mitad;
        else
            ini=mitad+1;
    }
    return ini;
}
