//Regional ICPC 2019
//Disponible en https://www.urionlinejudge.com.br/judge/en/problems/view/3022

//la idea es utilizar el hecho de que entre dos raices consecutivas, todo tiene el mismo signo. 
// asi, cuando cambien en la palabra de A a H, se aniade como raiz el numero impar que va entre
// los representantes
//   de modo que si al inicio tenemos AH, multiplicaremos el polinomio actual que tenemos por (x-3)
// esta forma de construirlo asegura que todos los humanos tienen ya el mismo signo
// para asegurarnos de ser el positivo tenemos que ver si el grado del polinomio es par o impar 
// y quien está inicialmente (si aliens o humanos)

#include <iostream>
#include <cstdint>
#include <cstring>
typedef int64_t ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt","r",stdin);

    ll polinomio[10005];
    int numRaices;

    //inicializamos el polinomio como y = 1
    memset(polinomio, 0, 10005);
    polinomio[0] = 1;
    numRaices = 0;

    string s;
    cin>>s;
    int n = s.length(), aux;
    for(int i = 1; i < n; ++i){
        if(s[i-1] != s[i]){
            //actualizamos el polinomio, lo multiplicamos por x-(2i+1)
            aux = -1*(2*i+1);
            for(int j = ++numRaices; j > 0; --j)
                polinomio[j] += polinomio[j-1]*aux;
        }
    }


    //ahora vemos si los humanos estan en los negativos o en los positivos
    int signo = 1;
    if(s[0] == 'A')
        signo = -1;
    if(numRaices%2 == 1)
        signo*= -1;
    
    cout<<numRaices<<'\n';
    cout<<signo*polinomio[0];
    for(int i = 1; i <= numRaices; ++i)
        cout<<" "<<signo*polinomio[i];
    cout<<'\n';
    return 0;
}
