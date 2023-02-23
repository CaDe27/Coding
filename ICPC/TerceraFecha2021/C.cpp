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

#define MINF -1000000000000
#define MOD 1000000007

#define m(a,b) (a%b + b)%b
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 100005;

void solve(){
    int b, l;
    cin>>b>>l;
    int n = 0;
    vector<int> digitos(l);
    loop(i, 0, l){
        cin>>digitos[l-1-i];   
    }

    for(int i = l-1; i >= 0; --i){
        n = (n*b + digitos[i]) % (b+1);
    }
    if(n == 0){
        cout<<"0 0\n";
        return;
    }

    //intentamos decrecer cada digito mas significativo
    int nn, pot, ndig;
    int indxResp = -1;
    for(int i = l-1; i >= 0; --i){
        //le quitamos el valor que tiene el digito
        pot = i %2 == 1? -1:1;
        nn = (n + (b+1 - pot*digitos[i])) % (b+1);
        nn = (b+1 - nn)%(b+1);
        if(pot == 1)
            ndig = nn;
        else
            ndig = (b+1 - nn)%(b+1);
        
        if(ndig < b && ndig < digitos[i]){
            indxResp = (l-i);
            break;
        }
    }
    if(indxResp == -1 ) ndig = -1;
    cout<<indxResp<<" "<<ndig<<"\n";
    
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
