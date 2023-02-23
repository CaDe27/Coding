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

const int maxN = 365;
int n, m;
int arre[maxN];
bool vis[maxN];

int conectados(int indx, int distancia){
    int cadena = 0, indxOriginal = indx;
    while(arre[indx] == 1 && !vis[indx]){
        ++cadena;
        vis[indx] = 1;
        indx = (indx + distancia)%360;
    }
    indx = (indxOriginal + 360 - distancia) % 360;
    while(arre[indx] == 1 && !vis[indx]){
        ++cadena;
        vis[indx] = 1;
        indx = (indx + 360 - distancia)%360;
    }
    return cadena/2;
}

int rota(int distancia){
    int respCaso = 0;
    loop(i, 1, 360){
        if(arre[i] == 1 && !vis[i]){
            respCaso += conectados(i, distancia);
        }
    }
    return respCaso;
}

void solve(){
    cin>>n;
    int aux;
    loop(i, 0, n){
        cin>>aux;
        arre[aux] = 1;
    }

    int resp = 1;
    loop(i, 1, 360){
        fill(vis, vis+maxN, 0);
        resp = max(resp, rota(i));
    }
    cout<<resp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}