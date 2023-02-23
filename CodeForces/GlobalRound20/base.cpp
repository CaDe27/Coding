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
int n, arre[maxN];
void solve(){
    cin>>n;
    int cont = 1;
    cin>>arre[0];
    int dobles = 0;
    loop(i, 1, n){
        cin>>arre[i];
        if(arre[i] == arre[i-1])
            ++cont;
        else if(cont >= 4){
            while(cont%3 != 1)
                --cont;
            dobles += (cont - 1)/3;
            cont = 0;
        }
    }
    cout<<"Cont "<<cont<<"\n";
    if(cont >= 4){
        while(cont%3 != 1)
            --cont;
        dobles += (cont - 1)/3;
        cont = 0;
    }


    int eq = 0;
    loop(i, 1, n){
        if(arre[i] == arre[i-1])
            ++eq;
    }
    int resp = dobles;
    eq -= 2*dobles;
    if(eq > 1)
        resp += eq - 1;
    cout<<resp<<"\n";


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
