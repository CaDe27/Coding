
/*
    aquí puedes definir una función recursiva
    f(nodoA,nodoB, k) 
        que responde de cuantas formas puedo ir del nodoA
        al nodoB en k pasos
    y eso se puede hacer viendo todos los adyacentes a A
    y reduciendo k en 1. 

    El problema es que esta función tarda como O(N*N*N*K)
        en calcularse completamente para el problema
        y no da en tiempo. 
    
    Y el verdadero problema es que K es demasiado grande
    entonces tenemos que ver como reducir ese factor K 

    la idea es entonces responder preguntas
        f(nodoA, nodoB, k)
        con 
            f(nodoA, nodoC, k/2) 
        es decir
        si quiero ir del nodoA al nodoB en 10000 pasos
        veo en de cuántas formas puedo ir de A a C en 5000 pasos,
        de C a B en 5000 pasos, y los multiplico. 
        Esto lo hago sobre todos los C y entonces la complejidad ahora es

        O( N * N * N * log K) que sí da en tiempo

        y para esto usamos una DP (hacer la recursión, pero guardando 
        cosas que vayamos calculando para reutilizarlas después que las
        necesite de nuevo) 

    eso de k/2 solo funciona si k es par
    si k es impar, nos movemos una unidad, quedamos en un par y ya aplicamos lo de
    k/2;
*/
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
typedef int64_t ll;

#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxK = 100000 + 5, maxN = 100 + 5;
const int logMaxK = 2*20 + 5;
int n, m, k;
bool adj[maxN][maxN];
map<int, int> mapeo;

ll dp[maxN][maxN][logMaxK];
bool visitado[maxN][maxN][logMaxK];
ll DP(int ini, int dest, int pasos){
    int indx = mapeo[pasos];
    //caso base
    //puedo llegar a ti en un paso si eres adyacente a mí,
    // si no no puedo llegar a ti en un paso. 
    if(pasos == 1)
        return adj[ini][dest];

    //caso recursivo
    //si no te he calculado ya, te calculo
    if(!visitado[ini][dest][indx]){
        visitado[ini][dest][indx] = true;
        dp[ini][dest][indx] = 0;
        //si soy impar 
        // entonces me muevo a un adyacente para estar en un caso par
        //(esta condición del if es un AND lógico
        //checa si el primer bit esta prendido)
        if(pasos & 1){
            --pasos;
            loop(i, 1, n+1)
                if(adj[ini][i])
                    dp[ini][dest][indx] = (dp[ini][dest][indx] + DP(i, dest, pasos))%MOD;
        }
        //soy par
        // entonces hago lo de k/2 para cada nodo intermedio
        //  el >> es un shift a la derecha, que equivale a divir entre 2
        //  pasos >>=1 equivale a pasos = pasos>>1
        else{
            pasos>>=1;
            loop(i,1,n+1)
                dp[ini][dest][indx] = (dp[ini][dest][indx] + (DP(ini, i, pasos) * DP(i, dest, pasos))%MOD)%MOD;
        }
    }
    return dp[ini][dest][indx];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>n>>m>>k;
    int a, b;
    //genero la matriz de adyacencias
    //uso matriz porque en este caso la matriz es pequenia
    loop(i, 0, m){
        cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    
    //mapeo los pasos que puedo consultar con un indice de la matriz dp
    //esto es para que si mis pasos a consultar son 
    // 160 80 40 20 10 5 4 2 1
    // no tenga que tener un arreglo de tamanio 160, sino de tamanio a lo
    // mas 2*log2(160)
    int copiaK = k, it = 0;
    while(copiaK > 0){
        if(copiaK & 1){
            mapeo.insert(make_pair(copiaK, it++));
            --copiaK;
        }   
        mapeo.insert(make_pair(copiaK, it++));
        copiaK >>=1;
    }

    ll resp = 0;
    loop(i, 1, n+1)
        resp = (resp + DP(1, i, k))%MOD;
    
    cout<<resp<<"\n";
    return 0;
}