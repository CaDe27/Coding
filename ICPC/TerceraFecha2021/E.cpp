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
int n;

void solve(){
    cin>>n;
    vector<int> izq, der;
    int aux, d;
    loop(i, 0, n){
        cin>>aux>>d;
        if(d == 0)
            der.push_back(aux);
        else
            izq.push_back(aux);    
    }
    int lastTime = 0;
    int itd = 0, iti = 0;
    while(itd < der.size() || iti < izq.size()){
        if(iti >= izq.size() || (itd < der.size() && der[itd] < izq[iti]) ){
            while(itd + 1 < der.size() && der[itd + 1] <= lastTime)
                ++itd;
            der[itd] = max(der[itd],lastTime);
            do{
                lastTime = der[itd]+10;
                ++itd;
            }
            while(itd < der.size() && der[itd] < lastTime);
        }
        else{
            while(iti + 1 < izq.size() && izq[iti + 1] <= lastTime)
                ++iti;
            izq[iti] = max(izq[iti],lastTime);
            do{
                lastTime = izq[iti] + 10;
                ++iti;
            }
            while(iti < izq.size() && izq[iti] < lastTime);
        }
    }
    cout<<lastTime<<"\n";
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
