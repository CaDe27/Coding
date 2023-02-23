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
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define INF (1e9*2000)
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 1005;
int n;
int arre[maxN];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    loop(t, 0, T){
        vector<int> op;
        cin>>n;

        bool visited[n+1];
        fill(visited, visited + n+1, 0);

        loop(i, 0, n){
            cin>>arre[i];
            visited[ arre[i] ] = true;
        }

        vector<int> faltantes;
        int sizeF = 0;
        loop(i, 0, n+1){
            if(!visited[i]){
                faltantes.push_back(i);
                ++sizeF;
            }
        }

        sort(faltantes.begin(), faltantes.end());
        int itF = 0;

        fill(visited, visited + n+1, 0);
        //si ya estabas, te modifico
            loop(i, 0, n){
                int v = arre[i];
                if(visited[v]){
                    op.push_back(i);
                    arre[i] = faltantes[itF++];
                    visited[arre[i]];
                }
                else{
                    visited[v] = true;
                }
            }
        cout<<"antes de parte 2"<<endl;
        loop(i, 0, n){
            cout<<arre[i]<<" ";
        }

        //el MEX del resultante va a ser el mas grande de los que estaban 0 veces en el 
        //arreglo inicial
        int mex = faltantes[itF];

        //cada que coloco a uno, lo pongo en su posicion correcta del arreglo 0,1,2,3,...
        // si me toca n, lo pongo en n-1,
        int correctos = 0;
        while(correctos < n){
            if(mex < n)
                ++correctos;
            int pos = min(mex, n-1);
            op.push_back(pos);
            swap(mex, arre[pos]);
        }


        //cuando haya colocado 0, ... , n-1 (max en n+1 operaciones)
        // ya está ordenado
        cout<<"caso "<<t<<"  n= "<<n<<"\nArreglo ordenado: ";
        loop(i, 0, n){
            cout<<arre[i]<<" ";
        }
        cout<<endl;
        cout<<"operaciones: ";
        cout<<op.size()<<"\n";
        for(int x : op){
            cout<<x<<" ";
        }
        cout<<"\n";
       

    }
}

