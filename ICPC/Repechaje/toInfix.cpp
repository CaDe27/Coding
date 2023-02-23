//Repechaje 2019
//Problema L
//Disponible en:https://www.juezguapa.com/problemas/enunciado/lisp-to-infix-translator

#include <iostream>
using namespace std;
string exp;
int it;

string toInfix(char opAnt = '+'){
    string infix = "";
    //veo cual es la operacion a aplicar
    char opAct = exp.at(it);
    it+=2;
    char c;
    //agrego la primera letra o parentesis (para en el proceso siempre poder 
    // agregar antes la operacion y no tener que preguntar si es la primera vez)
    infix = (c = exp.at(it++))=='('? toInfix(opAct): infix+c;
    
    while((c = exp.at(it++)) != ')'){
        if(c != ' '){
            infix+=opAct;
            if(c == '(')
                infix += toInfix(opAct);
            else
                infix += c;
        }
    }
    //si afuera hay una multiplicacion y adentro una suma, debe de llevar parentesis por
    //la jerarquía de las operaciones
    if(opAnt == '*' && opAct == '+')
        infix = '('+infix +')';
    return infix;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //it para iterar sobre la expresion
    int T;
    cin>>T;
    getline(cin, exp);
    for(int t = 0; t < T; ++t){
        getline(cin, exp);
        it = 0;
        //si es una sola letra, la imprimo, si no mando a llamar a la funcion
        if(exp.at(it++) == '(')
            cout<<toInfix()<<'\n';
        else
            cout<<exp<<'\n';
    }
}
