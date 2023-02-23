
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

#define loop(i,a,b) for(ll i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 105;
int n, m;

struct codigo{
    string stringCodigo;
    vector<int> nivelesAnidados;
}codigos[maxN];

int codigoActual;

void niveles(){
    int parentesisAbiertos = 0, nivel, maxNivel = 0;
    for(char c: codigos[codigoActual].stringCodigo){
        if(c == '['){
            ++parentesisAbiertos;
        }
        else if(c == ']'){
            --parentesisAbiertos;
            if(parentesisAbiertos == 0 && maxNivel > 0){
                codigos[codigoActual].nivelesAnidados.push_back(maxNivel);
                maxNivel = 0;
            }
        }
        else if(c == '+'){
            nivel = parentesisAbiertos + 1;
            if(nivel > 1)
                maxNivel = max(maxNivel, nivel);
            else
                codigos[codigoActual].nivelesAnidados.push_back(1);
        }
    }
    if(codigos[codigoActual].nivelesAnidados.size() == 0)
        codigos[codigoActual].nivelesAnidados.push_back(0);
}

void normalizaVector(){
    stack<int> s;
    vector<int> v = codigos[codigoActual].nivelesAnidados;
    
    for(int numero : v){
        while(!s.empty() && s.top() < numero)
            s.pop();
        s.push(numero);
    }

    stack<int> aux;
    while(!s.empty()){
        aux.push(s.top());
        s.pop();
    }

    codigos[codigoActual].nivelesAnidados.clear();
    while(!aux.empty()){
        codigos[codigoActual].nivelesAnidados.push_back(aux.top());
        aux.pop();
    }
}


bool f(const codigo &a, const codigo &b){
    int it = 0, size = min(a.nivelesAnidados.size(), b.nivelesAnidados.size());
    while(it < size && a.nivelesAnidados[it] == b.nivelesAnidados[it])
        ++it;
    if(it == size)
        return a.nivelesAnidados.size() < b.nivelesAnidados.size();
    else
        return a.nivelesAnidados[it] < b.nivelesAnidados[it];
}

void solve(){
    cin>>n;
    loop(i, 0, n){
        cin>>codigos[i].stringCodigo;
        codigoActual = i;
        niveles();
        normalizaVector();
    }    

    /*
    vector<int> :: iterator it;
    loop(i, 0, n){
        cout<<"niveles del "<<i<<" codigo: ";
        for(it = codigos[i].nivelesAnidados.begin(); it != codigos[i].nivelesAnidados.end(); ++it)
            cout<<*it<<" ";
        cout<<endl;
    }
    */
    
    sort(codigos, codigos + n, f);
    loop(i, 0, n)
        cout<<codigos[i].stringCodigo<<"\n";
    
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}