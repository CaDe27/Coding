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
#include <fstream>
#include <bitset>
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

//devuelve si n es una posicion ganadora
bool solve(){
    int n, m;
    cin>>n>>m;
    if(n <= m)
        return true;

    bitset<500000001> imparUnos;
    imparUnos[1] = 1;
    //tu cantidad de unos es la de tu mitad (mismo numero recorrido a la derecha)
    // + 1 si eres impar 
    loop(i, 2, n+1)
        imparUnos[i] = imparUnos[i/2] ^ (i&1);
    
    //los primeros m son posiciones ganadoras
    int it = m+1;
    while(imparUnos[it])
        ++it;

    if( it > n)
        return true;

    //ninguna de las m anteriores es perdedora, entonces esta posicion es perdedora
    int ultimaPerdedora = it;
    for( ;it < n+1; ++it){
        //si tengo impar unos o alcanzo la ultima perdedora, esta 
        //posicion es ganadora
        if(!imparUnos[it] && ultimaPerdedora < it - m)
            ultimaPerdedora = it;
    }
    return ultimaPerdedora < n;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    loop(i, 0, t){
        bool ganaAmy = solve();
        if(ganaAmy)
            cout<<"Pay the bill\n";
        else
            cout<<"Free snacks!\n";
    }
    return 0; 
}