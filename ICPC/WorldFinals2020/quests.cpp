/*
    despues de ordenar adecuadamente 
    dp[i][p] dice si dentro de las primeras i quests, se pueden generar p puntos
    
    dp[i+1][...] solo depende de dp[i][...]
    entonces se va reciclando, reutilizo el vector de dp[i][...] y lo convierto al de 
    i+1, validando los nuevos puntajes que ahora son alcanzables con esta nueva quest

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#define loop(i, a, b) for(int i = a; i < b; ++i)
using namespace std;

const int maxN = 2001;

typedef int64_t ll;
typedef pair<int, ll> pii;
int n, v, totalPoints;
ll c;

vector<pii> quests;

bool f(pii a, pii b){
    return a.first*c + a.second < b.first*c + b.second;
}

bitset<maxN*maxN> dp;

int tope(int a, ll b){
    int ini = a, fin = totalPoints, mitad;
    while(ini != fin){
        mitad = (ini + fin + 1)>>1;
        if( (mitad - a)*c < b)
            ini = mitad;
        else 
            fin = mitad - 1;
    }
    return ini;
}

void fillDP(){
    dp.reset();
    dp[0] = 1;
    dp[quests[0].first] = 1;

    loop(i, 1, n){
        for(int p = tope(quests[i].first, quests[i].second); p >= quests[i].first; --p){
            dp[p] = dp[p] | dp[p-quests[i].first];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>v>>c;
    quests.resize(n);
    totalPoints = 0;
    loop(i, 0, n){
        cin>>quests[i].first>>quests[i].second;
        quests[i].second *= v;
        totalPoints += quests[i].first;
    }
    sort(quests.begin(), quests.end(), f);
    fillDP();
    for(int i = totalPoints; i >= 0; --i){
        if(dp[i]){
            cout<<i*c + (totalPoints - i)<<"\n";
            break;
        }
    }
    return 0;
}