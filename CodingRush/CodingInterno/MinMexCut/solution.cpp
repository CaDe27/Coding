#include<iostream>
#include<string>
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

int main(){
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
