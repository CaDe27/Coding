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
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 200005;
int n;
ll arre[maxN], xors[maxN];
int sigImparCero[maxN];
int ceros[maxN];
map<ll, vector<int> > mapeo;

void solve(){
    int q;
    cin>>n>>q;
    ++n;
    arre[0] = xors[0] = 0;
    ceros[0] = 1;  

    loop(i, 1, n){
        cin>>arre[i];

        if(arre[i] == 0)
            ceros[i] = 1;

        xors[i] = arre[i] ^ xors[i-1];
        ceros[i] += ceros[i-1];

    }

    fill(sigImparCero, sigImparCero + n + 2, n+2);
    loop(i, 0, n){
        if(!mapeo[xors[i]].empty() && ((i - mapeo[xors[i]][0])%2==1) ){
            for(int v : mapeo[xors[i]]){
                sigImparCero[v+1] = i;
            }
            mapeo[xors[i]].clear();
        }  
        mapeo[xors[i]].push_back(i);
    }

    int a, b, cerosRango;
    for(int Q = 0; Q < q; ++Q){
        cin>>a>>b;
        //cout<<(xors[b]^xors[a-1])<<" "<<sigImparCero[a]<<endl;
        if( (xors[b]^xors[a-1]) == 0 && sigImparCero[a] <= b){
            cerosRango = ceros[b] - ceros[a-1];
            if(cerosRango == b-a + 1)
                cout<<"0\n";
            else if( (b-a+1)%2 == 1 || arre[a]==0 || arre[b] == 0){
                cout<<"1\n";
            }
            else
                cout<<"2\n";
        }else{
            cout<<"-1\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
        solve();
    return 0;
}