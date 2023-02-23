/*
    Google Code Jam Round 1A problem 2: Pascal Walk
    la idea es aprovechar que la fila r del triangulo de pascal suma 2^(r-1)
    Lo ideal seria construir un numero en binario y sumarle las filas que necesitamos
    pero como tiene que ser un camino continuo, tenemos qe considerar los 1's de la diagonal

    para eso, construimos n-30, y si nos faltan 1's al final, se los sumamos de lo que falta
    de la diagonal
*/
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

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef long double ld;
#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i, a, b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    ll n;
    loopi(t, 1, T){
        cin>>n;
        cout<<"Case #"<<t<<":\n";
        if(n <= 30)
            loopi(i, 1, n) cout<<i<<" 1\n";
        else{
            ll suma = 0;
            ll aux = n-30;
            int r = 1, c = 1;
            while(aux != 0){
                if(aux & 1){
                    suma += (ll(1))<<(r-1);
                    if(c == 1){
                        loopi(i, 1, r)
                            cout<<r<<" "<<i<<"\n";
                        c = r+1;
                    }else{
                        invli(i, r, 1)
                            cout<<r<<" "<<i<<"\n";
                        c = 1;
                    }
                }
                else{
                    suma += 1;
                    if(c == 1)
                        cout<<r<<" "<<c<<"\n"; 
                    else{
                        cout<<r<<" "<<c<<"\n";
                        c = r+1;
                    }
                }
                aux>>=1;
                ++r;
            }
            
            for(; suma < n; ++suma){
                if(c == 1) cout<<r<<" 1\n";
                else cout<<r<<" "<<(c++)<<"\n";
                ++r;
            }

        }
    }
    return 0;
}

