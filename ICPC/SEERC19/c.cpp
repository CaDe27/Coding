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
    string s; 
    cin>>s;

    int n = s.size()/2;
    int bucket[27];
    fill(bucket, bucket + 27, 0);

    for(char c : s){
        ++bucket[c - 'a'];
    }

    string alfa = "abcdefghijklmnopqrstuvwxyz";
    vector<pair<int, char> > ocurrencias;
    loop(i, 0, 26){
        if(bucket[i] > 0)
            ocurrencias.push_back(make_pair(bucket[i], alfa[i]));
    }
    sort(ocurrencias.begin(), ocurrencias.end());
    reverse(ocurrencias.begin(), ocurrencias.end());

    string resp = "";
    //busca el de mas de n si hay
     bool sePuede = true; 

    if(n == 1){
        sePuede = ocurrencias[0].first == 1;
        if(sePuede)
            resp+= ocurrencias[0].second;
            resp+=ocurrencias[1].second;
    }
    else if(n == 2){
        sePuede = ocurrencias[0].first <= 2;
        for(auto u : ocurrencias){
            loop(i, 0, u.first)
                resp += u.second;
        }
    } 
    else{
        if(ocurrencias[0].first >= 2*n-1)
            sePuede = false;
        else if(ocurrencias[0].first == 2*n-2 && ocurrencias.size() == 2)
            sePuede = false;
        
        if(sePuede){
            if(ocurrencias[0].first > n){
                loop(i, 0, n)
                    resp += ocurrencias[0].second;
                resp += ocurrencias[1].second;
                --ocurrencias[1].first;
                ocurrencias[0].first -= n;
                for(auto u : ocurrencias){
                    loop(i, 0, u.first)
                        resp += u.second;
                }
            }else{
                for(auto u : ocurrencias){
                    loop(i, 0, u.first)
                        resp += u.second;
                }
            }
        }
    }

   if(sePuede){
       cout<<"YES\n";
       cout<<resp<<"\n";
   }
   else{
       cout<<"NO\n";
   }


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
