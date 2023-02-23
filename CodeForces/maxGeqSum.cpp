//para cada numero checo el arreglo de maxima suma donde
// ese es el máximo
//si este no cumple, no cumple ningún otro

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
typedef int64_t ll;

#define loop(i, a, b) for(int i =a; i < b; ++i)
const int maxN = 2e5 + 5;
int a[maxN], n;

int sig[maxN], ant[maxN];
ll acum[maxN];
stack<int> pila;
void sigAnt(){
    loop(i, 0, n){
        while(!pila.empty() && a[pila.top()] < a[i]){
            sig[pila.top()] = i;
            pila.pop();
        }
        ant[i] = pila.empty()? -1:pila.top();
        pila.push(i);
    }
    while(!pila.empty()){
        sig[pila.top()] = n;
        pila.pop();
    }
}

int l[4*maxN], r[4*maxN];
ll mini[4*maxN], maxi[4*maxN];
void ST(int le, int ri, int i){
    l[i] = le;
    r[i] = ri;
    if(le < ri){
        int mid = (le+ri)>>1;
        ST(le, mid, 2*i);
        ST(mid+1, ri, 2*i+1);
        mini[i] = min(mini[2*i], mini[2*i+1]);
        maxi[i] = max(maxi[2*i], maxi[2*i+1]);
    }
    else{
        mini[i] = maxi[i] = acum[le];
    }
}

ll queryMin(int le, int ri, int i){
    if(le <= l[i] && r[i] <= ri){
        return mini[i];
    }
    else if(ri < l[i] || le > r[i])
        return 1e15;
    else{
        return min(queryMin(le, ri, 2*i), queryMin(le, ri, 2*i+1));
    }
}

ll queryMax(int le, int ri, int i){
    if(le <= l[i] && r[i] <= ri){
        return maxi[i];
    }
    else if(ri < l[i] || le > r[i])
        return -1e15;
    else{
        return max(queryMax(le, ri, 2*i), queryMax(le, ri, 2*i+1));
    }
}

bool solve(){
    cin>>n;
    ++n;
    a[0] = 0;
    loop(i, 1, n){
        cin>>a[i];
        acum[i] = a[i];
        if(i > 0)
            acum[i] += acum[i-1];
    }
    //obtengo el siguiente y anterior mas grande
    sigAnt();
    
    //construyo segTree para RMQ
    //le quiero quitar el minimo de los acumulados anteriores
    // y quiero la suma maxima de los de despues 
    ST(0, n-1, 1);

    ll qMin, qMax;
    loop(i, 1, n){
        //checo el arreglo de suma maxima donde yo 
        //soy el maximo
        qMin = queryMin(ant[i], i-1, 1);
        qMax = queryMax(i, sig[i]-1, 1);
        if(a[i] < qMax - qMin)
            return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t;
    while(t--){
        if(solve())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}