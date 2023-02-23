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
    vector<int> glasses(n);
    int total = 0;
    loop(i, 0, n){
        cin>>glasses[i];
        total += glasses[i];
    }

    total /= n;
    int ini=0;
    vector<int> primera(n), segunda(n);
    loop(i, 0, n){
        glasses[i] -= total;
        primera[i] = segunda[i] = glasses[i];
    }

    //clockwise
    ll respClock = 0;
    int it = 0, enMano = 0;
    for(int i = 0; i < 2*n; ++i){
        if(primera[it] > 0){
            enMano += primera[it];
            primera[it] = 0;
        }
        else if(primera[it] < 0){
            if(enMano >= -primera[it]){
                enMano += primera[it];
                primera[it] = 0;
            }
            else{
                primera[it] += enMano;
                enMano = 0;
            }
        }
        respClock += enMano;
        it = (it + 1)%n;
    }

    //counter
    ll respCounter = 0;
    it = 0;
    enMano = 0;
    for(int i = 0; i < 2*n; ++i){
        if(segunda[it] > 0){
            enMano += segunda[it];
            segunda[it] = 0;
        }
        else if(segunda[it] < 0){
            if(enMano >= -segunda[it]){
                enMano += segunda[it];
                segunda[it] = 0;
            }
            else{
                segunda[it] += enMano;
                enMano = 0;
            }
        }
        respCounter += enMano;
        it = (it +n - 1)%n;
    }

    cout<<min(respCounter, respClock)<<"\n";

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
