// para formar un palindromo necesitamos que haya cantidad par de cada letra
// o maximo una con cantidad impar

//para llevar la cuenta utilizamos una mascara de bits
//de modo que el bit de 1 representa a la 'a', el de 2 el 'b' y sucesivamente

//si queremos encontrar todos los rangos con palindromos que terminan en xi
//vemos que si entre xj y xi hay un palindromo (^ se refiere a la operacion XOR)
// 
// xj ^ xi = 0 o (2 a la k) si estamos permitiendo que la k-esima letra tenga 
//una cantidad impar de letras
// pero aplicando ^xi a los dos lados tenemos que es equivalente buscar 
// xj = 0^x(i+1) o (2 a la k) ^ x(i+1)
// de manera que solo tenemos que buscar en una cubeta cuantos xi's ha habido antes
// y podemos seguir a x(i+1) y ahora buscar todos los xj tales que 
// xj = 0^x(i+1) o (2 a la k) ^ x(i+1) 
// de modo que para cada caso (de 0 o k) podemos verificarlo en n

// como la cantidad de numeros que pueden generarse es 2^26 - 1 y no tenemmos tanta memoria,
// usamos un map, pues sabemos que como la longitud es a lo mas 100000, ocupamos solo 100000 de memoria

// de modo que la complejidad de tiempo es O((k+1)*n*logn) = O(27* n log n) = O(nlogn)
// por cada k recorremos el arreglo y en cada uno hacemos 2 queries de complejidad log n
#include <iostream>
#include <map>
#include <iterator>

using namespace std;
map<int, int> cubeta;
map<int, int>::iterator it;

//para limpiar la cubeta antes de iniciar cada caso
//iniciamos 0 en 1 por el caso en el que permitimos impar de la primer letra
// y es importante ponerlo al final porque si en el for se genera xi = 0, regresaria
// cubeta[0] = 0

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    string s;
    cin>>s;
    int n = s.size();
    long total = 0;

    cubeta[0] = 1;
    int xi = 0;
    for(int i = 0; i < n; ++i){
        //actualizamos xi
        xi ^= 1<<(s[i]-'a');

        //caso 0
            it = cubeta.find(xi);
            total += it->second;
        //caso 2^k (cantidad impar de la k-esima letra)
        for(int k = 0; k < 27; ++k){
            it = cubeta.find(xi^(1<<k));
            total += it->second;
        }
        ++cubeta[xi];
    }

    cout<<total<<'\n';
    return 0;
}