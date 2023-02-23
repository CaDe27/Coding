#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

//dado un arreglo/vector/string te dice, para cada posición
vector<int> pre(const string &p){
    int sizeP = p.length();
    vector<int> f(sizeP);
    f[0] = 0;
    int j = 0;
    for(int i = 1; i < sizeP; ++i){
        while(j > 0 && p[i] != p[j])
            j = f[j-1];
        if(p[i] == p[j]) f[i] = ++j;
        else f[i] = 0; //j == 0 y no coinciden
    }
    return f;
}

//funcion que busca encontrar todas las apriciones de un string p
// en un string s utilizando el algoritmo KMP
// Complejidad O(n + m) donde n y m son las longitudes de los strings
// Entrada:
//    p - string a buscar
//    s - string en el que se busca
//    
// salida:
//    un vector con todos los indices donde inicia una aparicion 
//    de p en s
vector<int> KMP(const string &s, const string &p){
    int sizeS = s.length(), sizeP = p.length();
    vector<int> f = pre(p), resp;

    int coincido = 0;
    for(int sig = 0; sig < sizeS; ++sig){
        //mientras no coincida el siguiente, verifico el sig posible
        while(coincido > 0 && s[sig] != p[coincido])
            coincido = f[coincido - 1];
        
        if(s[sig] == p[coincido]) ++coincido;

        //si ya encontramos un match, agregamos la posicion inicial del match
        // al vector respuesta        
        if(coincido == sizeP){
            coincido = f[sizeP-1];
            resp.push_back(sig-sizeP + 1);
        }
    }

    return resp;
}

int main(){
    string s = "aseversevera", p = "severa";
    vector<int> resp = KMP(s, p);
    vector<int> :: iterator it;
    for(it = resp.begin(); it != resp.end(); advance(it, 1)){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0; 

}