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

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 200005;
int n, arre[maxN];
ll x;
void solve(){
    cin>>n>>x;
    loop(i, 0, n){
        cin>>arre[i];
    }
    sort(arre, arre+n);

    ll suma = 0;
    ll indiceMayor = -1;
    loop(i, 0, n){
        if(suma + arre[i] > x)
            break;
        else{
            indiceMayor = i;
            suma += arre[i];
        }
    }
    ll packs = 0;
    ll dayIni= 0, dayFin;
    ll ini, mitad, fin;
    while(indiceMayor!= -1){
        while(indiceMayor != -1 && suma + dayIni*(indiceMayor+1) > x){
            suma -= arre[indiceMayor];
            --indiceMayor;
        }
        if(indiceMayor == -1)
            break;

        ini = dayIni;
        fin = x;
        while(ini != fin){
            mitad = (ini + fin+1)/2;
            if(suma + mitad*(indiceMayor+1) <= x)
                ini = mitad;
            else
                fin = mitad-1;
        }
        dayFin = ini;
        //cout<<(indiceMayor+1)<<" "<<dayIni<<" "<<dayFin<<" "<<suma<<" "<<suma + dayFin*(indiceMayor+1)<<endl;
        
        packs += (indiceMayor+1)*(dayFin-dayIni + 1);
        dayIni = dayFin + 1;
        
        suma -=arre[indiceMayor];
        --indiceMayor;
    }

    cout<<packs<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
