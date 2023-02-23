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
#include <array>

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 1e5 +5;
vector< array<int, 4> >incoming[maxN];
map<int, ll> floors[maxN];
ll x[maxN];
int n, m, k;
void solve(){
    cin>>n>>m>>k;
    loop(i,0, n){
        incoming[i].clear();
        floors[i].clear();
        cin>>x[i];
    }

    int a,b,c,d,h;
    loop(i, 0, k){
        cin>>a>>b>>c>>d>>h;
        --a;--c;
        array<int, 4> ladder = {d,a,b,h};
        incoming[c].push_back(ladder);
        floors[a].insert(pair<int, ll> (b,1e18));
    }
    
    if(incoming[n-1].size() == 0){
        cout<<"NO ESCAPE\n";
        return;
    }

    //fill first floor
    map<int,ll>::iterator it;
    for( it = floors[0].begin(); it != floors[0].end(); ++it){
        it->second = (it->first - 1)*x[0];
    }

    //for each intermediate floor
    ll previousDamage;
    int roomOut, roomIn, healthGained;
    loop(i, 0, n-1){
        //update the two closest outgoing rooms 
        if(incoming[i].size()==0 || floors[i].size() == 0)
            continue;

        for(array<int, 4> ladder : incoming[i]){
            roomIn = ladder[0];
            healthGained = ladder[3];
            previousDamage = floors[ladder[1]][ladder[2]];
            
            if(previousDamage == 1e18)
                continue;
            
            it = floors[i].lower_bound(ladder[0]);
            if(it != floors[i].end()){
                roomOut = it->first;
                it->second = min(it->second, previousDamage + (roomOut - roomIn)*x[i] - healthGained);
            }
            
            if(it != floors[i].begin()){
                --it;
                roomOut = it->first;
                it->second = min(it->second, previousDamage + (roomIn - roomOut)*x[i] - healthGained);
            }
        }

        if(floors[i].size() == 1)
            continue;

        map<int,ll>::iterator sig;
        for(it = --floors[i].end(); it != floors[i].begin();){
            sig = it;
            --it;
            it->second = min(it->second, sig->second + (sig->first - it->first)*x[i]);
        }

        map<int,ll>::iterator previous;
        map<int,ll>::iterator ending = --floors[i].end();
        for(it = floors[i].begin(); it != ending;){
            previous = it;
            ++it;
            it->second = min(it->second, previous->second + (it->first - previous->first )*x[i]);
        }
    }
    //fill the last floor
    roomOut = m;
    ll answer = 1e18;
    for(array<int, 4>ladder : incoming[n-1]){
        roomIn = ladder[0];
        healthGained = ladder[3];
        previousDamage = floors[ladder[1]][ladder[2]];
        if(previousDamage == 1e18)
            continue;
        answer = min(answer, previousDamage + (roomOut - roomIn)*x[n-1] - healthGained);
    }
    if(answer == 1e18)
        cout<<"NO ESCAPE\n";
    else
        cout<<answer<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
