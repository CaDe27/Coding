#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string s;
bool puedeSerCero(){
    //tiene que no haber ceros
    bool hayCero = false;
    int i = 0; 
    while(i < s.length() && !hayCero){
        if(s[i] == '0')
            hayCero = true;
        ++i;
    }
    return !hayCero;
}

bool puedeSerUno(){
    //tendriamos que poder dividir al string en substrings
    // de los cuales haya a lo mas uno con respuesta 1 
    // y todos los demas con respuesta 0
    
    //esto se reduce en que los ceros esten todos juntitos
    int bloquesDeCeros = 0;
    if(s[0] == '0')
        ++bloquesDeCeros;
    
    int i = 0; 
    for(int i = 1; i < s.length(); ++i){
        if(s[i] == '0' && s[i-1] == '1')
            ++bloquesDeCeros;
    }

    return bloquesDeCeros <= 1;
}

int main() {
    const string GRUPO = "cases/g1."; // sin_grupo/, easy/, ...
    for(int i = 0; i < 19; ++i){
        string CASO = to_string(i); 
        
        ifstream in(GRUPO + CASO + ".in");

        streambuf *cinbuf = cin.rdbuf();
        cin.rdbuf(in.rdbuf());
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);
            
        ofstream out(GRUPO + CASO +".out");
        streambuf *coutbuf = cout.rdbuf(); 
        cout.rdbuf(out.rdbuf()); 

        cin>>s;
        int resp;
        if(puedeSerCero()) 
            resp = 0;
        
        else if(puedeSerUno())
            resp = 1;
        
        else 
            resp = 2;
        cout<<resp<<"\n";
    }
}