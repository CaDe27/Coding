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
const int maxN = 2000001;
int n, a[4*maxN], f[maxN], n4, n3, n2;
int kmpTarget[maxN];
set<int> kmpResps;
int g[8*maxN], ans[8*maxN];


// 0 si menor 1 si igual 2 si mayor
int compareTo(int i){
    if(a[i] < a[i+n])   return 0;
    else if(a[i] == a[i+n]) return 1;
    else return 2;
}

void pre(){
    int sizeP = n;
    f[0] = 0;
    int j = 0;
    for(int i = 1; i < sizeP; ++i){
        while(j > 0 && kmpTarget[i]!= kmpTarget[j])
            j = f[j-1];
        if(kmpTarget[i] == kmpTarget[j]) f[i] = ++j;
        else f[i] = 0; //j == 0 y no coinciden
    }
}

//funcion que busca encontrar todas las apriciones de un string p
// en un string s utilizando el algoritmo KMP
// Complejidad O(n + m) donde n y m son las longitudes de los strings
// Entrada:
//    p - string a buscar
//    s - string en el que se busca
//    
// salida:
//    un vector con todos los indices donde inicia una aparicion 
//    de p en s
void KMP(){
    int sizeS = n3, sizeP = n;
    pre();

    int coincido = 0;
    for(int sig = 0; sig < sizeS; ++sig){
        //mientras no coincida el siguiente, verifico el sig posible
        while(coincido > 0 && compareTo(sig) != kmpTarget[coincido])
            coincido = f[coincido - 1];
        
        if(compareTo(sig) == kmpTarget[coincido]) ++coincido;

        //si ya encontramos un match, agregamos la posicion inicial del match
        // al vector respuesta        
        if(coincido == sizeP){
            coincido = f[sizeP-1];
            kmpResps.insert(sig-sizeP + 1);
        }
    }
}

int manacher() {
    int res = 0;
    for(int i = 0; i < n4-1; ++i){
        g[2*i] = -1;
        g[2*i+1] = a[i];
    }

    g[8*n-2] = -1;
    int nm = 8*n-1;
    // cout<<nm<<endl;
    // loop(i, 0, nm)
    //     cout<<g[i]<<" ";
    // cout<<endl;
    
    fill(ans, ans+nm, 0);
 
    for (int i = 0, l = 0, r = -1; i < nm; i++) {
        int &k = ans[i];
        k = (i < r) ? min(r - i, ans[l + r - i]) : 1;
        while (i - k >= 0 && i + k < nm && g[i - k] == g[i + k])
            k++;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
        // 2*k - 1 == palindrome size
        // then it starts in pos i - k + 1 in the one with -1s
        // 
        // real palindrome has size (2*k-2)/2 = k-1
        // if(g[i] == -1){
        //     cout<<i<<" "<<(i-k+1)/2<<" "<<k-1<<" "<<endl;
        //     cout<<i<<" "<<max( (i-k+1)/2, (i-2*n)/2)<<" "<<min(k-1, 2*n)<<" "<<endl;
        // }
        if (g[i] == -1 && k-1 >= 2*n && kmpResps.find( (i-2*n)/2) != kmpResps.end())
            return (i-2*n)/2;
    }
    return -1;
}

string solve(){
    cin>>n;
    n4 = 4*n;
    n3 = 3*n;
    n2 = 2*n;
    loop(i, 0, 2*n){
        cin>>a[i];
        a[2*n + i] = a[i];
    }


    loop(i, 0, n/2)
        kmpTarget[i] = 0;
    if(n&1)
        kmpTarget[n/2] = 1;
    int half = n&1? n/2+1 : n/2;
    loop(i, half, n)
        kmpTarget[i] = 2;
    
    kmpResps.clear();
    KMP();

    // loop(i, 0, 4*n)
    //     cout<<a[i]<<" ";
    // cout<<endl;

    // for(int x : kmpResps)
    //     cout<<x<<" ";
    // cout<<endl;


    return to_string(manacher());
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