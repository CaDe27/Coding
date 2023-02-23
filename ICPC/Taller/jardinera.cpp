#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
/* 
    definimos un posible pico/montania 
    se da una montania en en un punto si es un maximo local
    y esta existe si la altura no la une con otra o si no la hunde
    

    nos damos cuenta que una montana existe (separada de las demas)
    si la altura esta en su rango izquierdo (o su rango derecho)

    el problema se reduce a de un conjunto de rangos, ver el máximo de hechos que se traslapan
    y lo hacemos como un sweep line
*/

using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin>>n;

    int i = 0;

    int mini, maxi;
    int act;

    vector<pii> montanias;
    while(i < n){
        //para buscar cuando decrece
        if(i == 0)
            mini = 0;
        else
            mini = act;
        
        while(i < n && (cin>>act, ++i, mini >= act) ){
            mini = act;
        }

        maxi = act;
        while(i < n && (cin>>act, ++i, maxi <= act) )
            maxi = act;

        montanias.push_back(pii(mini, 1));
        montanias.push_back(pii(maxi, -1));
    }

    sort(montanias.begin(), montanias.end());

    int resp = 0;
    int actual = 0; 
    for(pii m : montanias){
        if(m.second == 1)
            ++actual;
        else
            --actual;
        resp = max(resp, actual);
    }

    cout<<resp<<"\n";

    
}