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
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;

void solve(){
    int n, k, nk, cont;
    cin>>n>>k;
    nk = n*k;
    bool resp;
    if(nk%2 == 0)
        resp = ( (nk/2) % k) == 0; 
    else
        resp = ((nk-1)/2)%k == 0 && ((nk+1)/2)%k == 0;
    if(resp){
        cout<<"YES\n";
        //impares
        cont = 0;
        for(int i = 1; i<= nk; i +=2){
            cout<<i<<" ";
            ++cont;
            if(cont == k){
                cout<<"\n";
                cont = 0;
            }
        }
        //pares
        cont = 0;
        for(int i = 2; i<= nk; i +=2){
            cout<<i<<" ";
            ++cont;
            if(cont == k){
                cout<<"\n";
                cont = 0;
            }
        }
    }
    else{
        cout<<"NO\n";
    }
    
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

