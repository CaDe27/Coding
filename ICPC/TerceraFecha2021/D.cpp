#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>
#include <set>

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define m(a,b) (a%b + b)%b
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN =1e6 + 10;
int n, m;
int repre[maxN], fa[maxN];

typedef pair<int, pair<int, int> > arista;
typedef pair<int, int> pii;
bool mayor(const arista &a, const arista &b){
    return a.first > b.first;
}

int repreMayor(int a){
    if(repre[a] == a)
        return a;
    else 
        return repre[a] = repreMayor(repre[a]);
}

void unite(int a, int b){
    repre[repreMayor(a)] = repreMayor(b);
}
int contra(int a){
    return a%2 == 0? a+1 : a-1;
}

bool puedenUnirse(int a, int b){
    a = fa[a];
    b = fa[b];
    return repreMayor(a) != repreMayor(contra(b)) && repreMayor(b) != repreMayor(contra(a));
}

bool insertaAristas(int indx1, int indx2, vector<arista> &aristas){
    int v1, v2;
    for(int z = indx1; z <= indx2; ++z){
        v1 = fa[aristas[z].second.first];
        v2 = fa[aristas[z].second.second];
        unite(v1, contra(v2));
        unite(contra(v1), v2);
        //cout<<"uno "<<v1<<" "<<repreMayor(fa[v1])<<" con "<<v2<<" "<<repreMayor(fa[v2])<<"\n";
        if(repreMayor(v1) == repreMayor(contra(v1))
           || repreMayor(v2) == repreMayor(contra(v2))) 
            return false;
    }
    return true;
}
bool parIgual(pii a, pii b){
    return a.first == b.first || a.first == b.second || a.second == b.first || a.second == b.second;
}

bool dosDiferentes(set<pii> &posibles){
    int size = posibles.size();
    if(size <= 1) 
        return false;

    //checo si el primero tiene alguno con el que no sea igual
    auto it1 = posibles.begin(), it2 = ++posibles.begin();
    while(it2 != posibles.end() ){
        if(!parIgual(*it1, *it2))
            return true;
        ++it2;
    }   
    if(size == 2) return false;

    //si no, checo si el segundo tiene alguno con el que no sea igual
    it1 = posibles.begin();
    it2 = ++posibles.begin();
    while(it1 != posibles.end()){
        if(!parIgual(*it1, *it2))
            return true;
        ++it1;
    }  

    //si no, quiere decir que el elemento que repiten el primero y segundo 
    //esta en todos, o solo hay a lo mas un elemento que no lo tiene
    //buscamos este elemento y vemos si no tiene alguien con quien sea diferente
    int repetido;
    it1 = posibles.begin();
    it2 = ++posibles.begin();
    if( it1 -> first == it2 -> first || it1 -> first == it2 -> second)
        repetido = it1 -> first;
    else
        repetido = it1 -> second;
    
    it1 = ++posibles.begin();
    auto itD = posibles.end();
    while(it1 != posibles.end() && itD == posibles.end()){
        if( it1 -> first != repetido && it1 -> second != repetido)
            itD = it1;
        ++it1;
    }

    //si este elemento diferente no existe, no hay dos pares diferentes
    if(itD == posibles.end())
        return false;
    
    //checamos si hay alguno completamente diferente a este par
    it1 = posibles.begin();
    while(it1 != posibles.end()){
        if(!parIgual(*itD, *it1))
            return true;
        ++it1;
    }

    //si no hay nadie, no hay dos pares diferentes
    return false;
}

void imprime(vector<int> &resp){
    int size = resp.size();
    if(size > 0){
    for(int i = size - 1; i >= 0; --i)
        cout<<resp[i]<<"\n";
    
    }else
        cout<<"IMPOSSIBLE\n";
}


void solve(){
    cin>>n;
    cin>>m;
    int x, y, b;
    vector<arista> aristas; 
    loop(i, 0, m){
        cin>>x>>y>>b;
        --x; --y;
        aristas.push_back( arista(b, make_pair(x, y)));
    }
    sort(aristas.begin(), aristas.end(), mayor);
    loop(i, 0, 2*n+5){
        repre[i] = i;
    }
    loop(i, 0, n){
        fa[i] = 2*i;
    }

    int i =0;
    vector<int> resp; 
    bool aunPosible = true;
    while(i < m && aunPosible){
        int indxInicialValor = i, valorIni = aristas[i].first;
        set<pii> posibles;
        pii repres;
        //encuentro todas las aristas del mismo valor que pueden unirse
        while(i < m && aristas[i].first == valorIni){
            if(puedenUnirse(aristas[i].second.first,  aristas[i].second.second)){
                repres = pii(repreMayor(fa[ aristas[i].second.first ]), repreMayor(fa[aristas[i].second.second]));
                if(repres.first > repres.second) swap(repres.first, repres.second);
                posibles.insert(repres);
            }  
            ++i;
        }

        //si hay dos diferentes, puedo dividir el reino
        if(dosDiferentes(posibles))
            resp.push_back(valorIni);

        //para ver si hay una contradiccion despues de unirlos
        aunPosible = insertaAristas(indxInicialValor, i-1, aristas);        
    }
    if(i == m && aunPosible)
        resp.push_back(0);
    
    imprime(resp);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}