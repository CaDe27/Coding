#include <iostream>
#include <algorithm>
#include <vector>
#define MINF -1000000000000
#define loop(i,a,b) for(int i = a; i < b; ++i)

//Hacemos una DP tomar o no tomar sobre las aristas del arbol
//nota que cada vertice debe tener grado 1 o 2
//MORALEJA de esta DP: deja que los casos invalidos se castiguen a si mismos, no trates de preverlos
//                      en la implementacion
//                      puedes, pero USUALMENTE es mas complicado y no vale la pena el tiempo 
//                      aqui el unico caso que debe castigarse a si mismo es que alguien no este 
//                      conectado a nadie
using namespace std;

typedef int64_t ll;
typedef pair<int,ll> pill;
typedef vector<pill> vill;


const int maxN = 100005;
vill arbol[maxN];
int papa[maxN], cantHijos[maxN];

bool visitedDP[maxN][2], visitedHijos[maxN], visitedCualHijo[maxN];
ll dp[maxN][2], dpHijos[maxN];
pill cualHijo[maxN];

ll DP(int nd, int conectado);
ll DPHijos(int nd);
pill cualHijoMax(int nd);
ll expConectado(int nd, pill h);
ll expConectado(int nd, pill h1, pill h2);

void recorridoInicial(int nd){
    for(pill h: arbol[nd])
        if(h.first != papa[nd])
        {
            papa[h.first] = nd;
            ++cantHijos[nd];
            recorridoInicial(h.first);
        }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int a, b;
    long c;
    loop(i, 0, n-1)
    {
        cin>>a>>b>>c;
        arbol[a].push_back(pill(b,c));
        arbol[b].push_back(pill(a,c));
    }
    recorridoInicial(1);
    cout<<DP(1,0)<<'\n';
}

//calcula cuanto aporta cierto nodo dependiendo de si esta conectado o no con su padre
ll DP(int nd, int conectado){
    //caso base
    if (cantHijos[nd]==0)
        return conectado? 0 : MINF;


    if(!visitedDP[nd][conectado])
    { 
        visitedDP[nd][conectado] = 1;
        //si no esta conectado a nadie (unir a uno o a dos)
        if(!conectado)
        {
            //lo inicializo conectado a uno
            dp[nd][0] = expConectado(nd, cualHijoMax(nd));
            //checo si es mejor conectarlo a dos
            for(pill h: arbol[nd])
                if(h.first != papa[nd] && h.first != cualHijo[nd].first)
                    dp[nd][0] = max(dp[nd][0], expConectado(nd, cualHijo[nd], h)); 
        }

        //si estas ya conectado a alguien, puedes acabar aqui o unirte a alguno de tus hijos
        else 
            dp[nd][1] = max(DPHijos(nd), expConectado(nd, cualHijoMax(nd)));
    }
    return dp[nd][conectado];
}

//esta dp nos calcula la suma de las dps de los hijos si tu no te conectas con ninguno de ellos
ll DPHijos(int nd){
    if(!visitedHijos[nd]){
        visitedHijos[nd] = 1;
        ll resp = 0;
        for(pill h: arbol[nd])
            if(h.first != papa[nd])
                resp += DP(h.first, 0);
        dpHijos[nd] = resp;
    }
    return dpHijos[nd];
}

//esta guarda el hijo al que te conviene conectarte si te conectas con uno
pill cualHijoMax(int nd)
{
    if(!visitedCualHijo[nd])
    {
        visitedCualHijo[nd] = 1;
        for(pill h: arbol[nd])
            if(h.first != papa[nd]){
                if(cualHijo[nd].first == 0 || expConectado(nd, h) >  expConectado(nd,cualHijo[nd]))
                    cualHijo[nd] = h;             
            }
    }
    return cualHijo[nd];
}

//calcula cuanto aportan tus hijos si te conectas con h
ll expConectado(int nd, pill h){
    return h.second + DP(h.first, 1) + DPHijos(nd) - DP(h.first, 0);
}

//calcula cuanto aportan tus hijos si te conectas con h1 y h2
ll expConectado(int nd, pill h1, pill h2){
    return h1.second + DP(h1.first, 1) + h2.second + DP(h2.first, 1) + DPHijos(nd) - DP(h1.first, 0) -  DP(h2.first, 0);
}
