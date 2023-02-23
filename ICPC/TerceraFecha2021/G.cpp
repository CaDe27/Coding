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
#include <unordered_map>
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

#define m(a,b) (a%b + b)%b
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 100005;
typedef pair<ll,int> pll;
map<pll, int> dp;
map<pll, int> sig;
vector<ll> fibos(100);
ll n;

bool sePuede(ll rem, int i){
    if(dp.find(pll(rem , i)) != dp.end()) 
        return dp[pll(rem, i)];

    for(int j = i; j >= 2; --j){
        if(rem == fibos[j]){
            sig.insert( make_pair(pll(rem , i), j));
            return dp[pll(rem, i)] = 1;
        }
        else if( rem % fibos[j] == 0){
            if(sePuede(rem/fibos[j], j)){
                sig.insert( make_pair(pll(rem , i), j)); 
                return dp[pll(rem, i)] = 1;
            }
        }
    }
    return dp[pll(rem, i)] = 0;
}

void solve(){
    cin>>n;
    fibos[1] = 1;
    fibos[2] = 2;
    int i = 2;
    while(fibos[i] <= n){
        ++i;
        fibos[i] = fibos[i-1] + fibos[i-2];
    }
    
    bool encontrado =false;
    string resp = ""; 
    for(; i >= 2 && !encontrado; --i){
        if(sePuede(n, i)){
            encontrado = true;
            int aux;
            
            do{
                i = sig[pll(n, i)];
                for(int k = 0; k < i - 1; ++k)
                    resp = resp + "A";
                resp = resp + "B";
                n /= fibos[i];
            }while(n > 1);
        }
    }
    if(!encontrado)
        cout<<"IMPOSSIBLE\n";
    else
        cout<<resp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
