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
#define MOD(a,b) (a%b + b)%b

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 501;
int arre[maxN+5];

//vueltas hacia la der que necesita para llegar a su max
int vueltasParaMax(int num){
    int resp = 0;
    int maxi = num;

    loopi(i, 1, 6){
        int unidad = num%10;
        num = num/10 + unidad*1000000;
        if(num > maxi){
            maxi = num;
            resp = i;
        }
    }

    return resp;
}

int indx[3];
int dp[505][505][505];
int DP(int c1, int c2, int c3){
    //casos base
    if(c1 == 0 && c2 == 0 && c3 == 0)
        return 0;
    else if(c1 <0 || c2 < 0 || c3<0)
        return 10000;

    if(dp[c1][c2][c3] == 0){
        int miResp = 1000;
        //uso i para c3
        //    j para c2
        int limitI = min(7, c3);
        int limitJ = min(7, c2);

        loopi(i, 0, limitI)
        loopi(j, 0, limitJ){
            if(i == 0 && j == 0){
                miResp = min(miResp, 6 + DP(c1-7, c2, c3));
            }
            else{
                int need =  indx[0] == 1?  MOD( -(i*indx[2]+j*indx[1]) , 7) :  MOD(i*indx[2] + j*indx[1], 7);
                miResp = min(miResp, i+j+need-1 + DP(c1-need, c2 - j, c3 - i));
            }   
        }
        dp[c1][c2][c3] = miResp;
    }

    return dp[c1][c2][c3];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n; cin>>n;

    loop(i,1,n+1){
        int num;
        cin>>num;
        if(num%1111111 == 0){
            --i; --n;
        }
        else
            arre[i] = vueltasParaMax(num);
        
    }

    arre[0] = arre[n+1] = 0;

    //convertimos a b
    loop(i, 0, n+1){
        arre[i] = arre[i+1] - arre[i];
    }
    
    //llenamos cubeta
    int bucket[7];
    fill(bucket, bucket+7, 0);
    loop(i, 0, n+1){
        ++bucket[ MOD(arre[i],7) ];
    }

    //eliminamos los conjuntos de tamanio 2
    //la respuesta aumenta en 1 por cada uno
    int resp = 0;    
    loopi(i, 1, 3){
        resp += min(bucket[i], bucket[7-i]);
        if(bucket[i] > bucket[7-i]) {
            indx[i-1] = i;
            bucket[i] -= bucket[7-i];
        }
        else{
            indx[i-1] = 7-i;
            bucket[7-i] -= bucket[i];
        }
    }

    cout<<resp+DP(bucket[indx[0]] , bucket[indx[1]], bucket[indx[2]] )<<"\n";
    
}
