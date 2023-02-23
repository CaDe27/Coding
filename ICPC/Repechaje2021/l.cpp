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
typedef pair<int,int> pii;
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 500005;


int fechaADias(string s){
    int anio, mes, dia;
    anio = mes = dia = 0;
    loop(i, 0, 4){
        anio *= 10;
        anio += s[i] - '0';
    }
    loop(i, 5, 7){
        mes *= 10;
        mes += s[i] - '0';
    }

    loop(i, 8, 10){
        dia *= 10;
        dia += s[i] - '0';
    }
    return dia + mes*50  + anio*20*50;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n; 
    cin>>n;
    int fecha[n];
    string nombre[n];
    string s;
    loop(i, 0, n){
        cin>>nombre[i];
        cin>>s;
        fecha[i] = fechaADias(s);
    }
    //ordeno por fecha de nacimiento
    vector<pii> fechaIndx;
    loop(i, 0, n)
        fechaIndx.push_back(pii(fecha[i], i));
    sort(fechaIndx.begin(), fechaIndx.end());

    set<int> indices;
    int resps[n];
    int sigIndx;
    set<int> :: iterator it;
    vector<int> sameDate;
    //para cada fecha de nacimiento considero todos los indices con esa fecha
    //y para cada uno de ellos checo el indice de la persona mas cercana antes de ellos
    // que nacio despues
    int i = 0;
    while(i < n){
        sameDate.push_back(fechaIndx[i].second);
        ++i;
        while(i < n && fechaIndx[i].first == fechaIndx[i-1].first){
            sameDate.push_back(fechaIndx[i].second);
            ++i;
        }
        
        for(int i = 0; i < sameDate.size(); ++i){
            sigIndx = sameDate[i];
            it = indices.lower_bound(sigIndx);
            resps[sigIndx] = it == indices.begin()? -1: *(--it);
        }

        for(int i = 0; i < sameDate.size(); ++i)
            indices.insert(sameDate[i]);
        sameDate.clear();
    }

    //imprimo las respuestas 
    int m; cin>>m;
    int q;
    loop(i, 0, m){
        cin>>q;
        --q;
        if(resps[q] == -1)
            cout<<"At place #"<<(q+1)<<", no one younger arrived before "<<nombre[q]<<"\n";
        else{
            cout<<"At place #"<<(q+1)<<", the last younger person to arrive before "<<nombre[q]<<" is "<<nombre[resps[q]]<<"(#"<<(resps[q]+1)<<")\n";
        }
    }
    
    return 0;
}