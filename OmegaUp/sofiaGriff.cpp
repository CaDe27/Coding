//ahora la clase es que solo necesitas el vector de dp[indx][k]
// no el de todos
 
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

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin>>n>>k;

    int monedas[n];
    loop(i, 0, n)
        cin>>monedas[i];

    bool posibles[k+5];
    bool DPA[k+5], DPB[k+5];
    bool numsA[k+5][k+5], numsB[k+5][k+5];

    auto dpA = &DPA;
    auto dpB = &DPB;
    decltype(dpA) aux1;
    auto nA = &numsA;
    auto nB = &numsB; 
    decltype(nA) aux2;

    fill(posibles, posibles+k+5, 0);
    fill(DPB, DPB+k+5, 0);
    DPB[0] = 1;
    loop(i, 0, k+5)
        fill(numsB[i], numsB[i]+k+5, 0);
    numsB[0][0] = 1;
    
    
    posibles[0] = 1;
    total = 1;

    loop(indx, 0, n){
        loop(ptj, 0, k+1){
            //aqui estamos en el estado (indx, ptj)
			
			(*dpA)[ptj] = 0;
            loop(j, 0, k+1)
                (*nA)[ptj][j] = 0;

            //si tomo la moneda
            if( ptj>= monedas[indx] && (*dpB)[ptj - monedas[indx]]){
                (*dpA)[ptj] = 1;
                //agrego los numeros sin usarme
                loop(j, 0, k+1)
                    (*nA)[ptj][j] = (*nB)[ ptj- monedas[indx] ][j];
                
                for(int j = 0; j+monedas[indx]<=k; ++j )
                    if( (*nB)[ptj- monedas[indx]][j] )
                        (*nA)[ptj][j+monedas[indx]] = 1;
            }
            
            //si no la tomo
            if( (*dpB)[ptj]){
                (*dpA)[ptj] = 1;
                loop(j, 0, k+1)
                    if((*nB)[ptj][j])
                        (*nA)[ptj][j] = 1;
            }

        }
        aux1 = dpA;
        dpA = dpB;
        dpB = aux1;

        aux2 = nA;
        nA = nB;
        nB = aux2;
    }

    if(dpB[k]){
        string resp;
        int total = 0;
        loop(i, 0, k+1){
            if((*nB)[k][i]){
                resp += to_string(i)+" ";
                ++total;
            }  
        }
        cout<<total<<"\n";
        cout<<resp<<"\n";
    }
    else
        cout<<0<<endl;



    return 0;
    
}

