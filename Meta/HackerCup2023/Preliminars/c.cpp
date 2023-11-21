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
#define INF 1000000000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;
const int maxN = 600005;
ll n, size;
ll a[maxN], suma, aux[maxN];
multiset<ll> arre;

ll caso1MinSigue(){
    ll nuevo = (a[size-1] + a[0])*n - suma;
    if(nuevo <= 0)
        return -1;
    
    ll target = a[size-1] + a[0];
    
    arre.insert(nuevo);

    int indx = 0;
    for(int v : arre){
        aux[indx++] = v;
    }

    arre.erase(arre.find(nuevo));

    loop(i, 0, n)
        if(aux[i] + aux[size-i] != target)
            return -1;

    return nuevo;         
}

ll caso1MinCambia(){
    ll nuevo = (a[size-2] + a[0])*n - suma;
    if(nuevo <= 0)
        return -1;
    
    ll target = a[size-2] + a[0];
    arre.insert(nuevo);

    int indx = 0;
    for(int v : arre){
        aux[indx++] = v;
    }

    arre.erase(arre.find(nuevo));

    loop(i, 0, n)
        if(aux[i] + aux[size-i] != target)
            return -1;

    return nuevo;        
}

ll respMaxSigue(){
    ll resp1 = caso1MinCambia(), resp2 = caso1MinSigue();
    if(resp1 == -1) return resp2;
    else if(resp2 == -1) return resp1;
    else return min(resp1, resp2);
}


ll respMaxEsNuevo(){
    ll nuevo = (a[size-1] + a[1])*n - suma;
    if(nuevo <= 0)
        return -1;
    
    ll target = a[size-1] + a[1];
    arre.insert(nuevo);

    int indx = 0;
    for(int v : arre){
        aux[indx++] = v;
    }

    arre.erase(arre.find(nuevo));

    loop(i, 0, n)
        if(aux[i] + aux[size-i] != target)
            return -1;
    return nuevo;  
}

ll solve(){
    cin>>n;
    size = 2*n-1;
    loop(i, 0, size)
        cin>>a[i];
    if(n == 1)
        return 1;

    suma = 0;
    arre.clear();

    loop(i, 0, size)
        suma += a[i];
    sort(a, a+size);
    loop(i, 0, size)
        arre.insert(a[i]);
        
    ll respA = respMaxSigue();
    ll respB = respMaxEsNuevo();
    if(respA == -1)
        return respB;
    else if(respB == -1)
        return respA;
    else 
        return min(respA, respB);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    for(int i = 1; i <= t; ++i){
        cout<<"Case #"<<i<<": "<<solve()<<"\n";
    }
    return 0;
}