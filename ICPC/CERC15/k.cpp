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

const int maxN = 100005;

void solve(){
    int n;
    cin>>n;
    int ataco[2*n+1];
    int meAtacan[2*n+1];
    fill(meAtacan, meAtacan + 2*n+1, 0);
    
    vector<int>  S, noS;
    for(int i = 1, a; i <= 2*n ; ++i){
        cin>>a;
        ataco[i] =a;
        ++meAtacan[a];
    }

    stack<int> noAtacados;
    loop(i, 1, 2*n+1){
        if(meAtacan[i] == 0)
            noAtacados.push(i);
    }

    bool visited[2*n+1];
    fill(visited, visited + 2*n+1, 0);

    int u, v, w, indx = 1;
    while(S.size() + noS.size() < 2*n){
        //encuentro a un atacante dando prioridad 
        //a lo que no ataca nadie
        if(!noAtacados.empty()){
            u = noAtacados.top();
            noAtacados.pop();
        }
        else{
            while(visited[indx])
                ++indx;
            u = indx;
        }
        //proceso al nodo atacante
        S.push_back(u);
        visited[u] = true;
        
        if(!visited[ataco[u]]){
            noS.push_back(ataco[u]);
            visited[ataco[u]] =true;
            --meAtacan[ ataco[ataco[u]] ];
            if( meAtacan[ ataco[ ataco[u]]] == 0 && !visited[ataco[ataco[u]]])
                noAtacados.push(ataco[ ataco[u]]);
        }
    }

    cout<<S[0];
    for(int i = 1; i < S.size(); ++i)
        cout<<" "<<S[i];
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}

