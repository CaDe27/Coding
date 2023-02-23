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
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 100005;
int n;
int it, r1, r2, maxi;
vector<int> maxis, maxis2;
void solve(){
    cin>>n;

    it = 1;
    maxis.clear();
    maxi = 1;
    
    int i = it+1;
    while(i < n+1){
        //itero sobre el arreglo y voy guardando los indices que tienen el mayor
        //gcd con el pivote (it)
        while(i < n+1 && maxis.size() < 2){
            cout<<"? "<<it<<" "<<i<<endl;
            cin>>r1;
            if(r1 > maxi){
                maxi = r1;
                maxis.clear();
            }
            if(r1 == maxi)
                maxis.push_back(i);
            ++i;
        }

        //si ya llegue al final, puedo concluir
        if(i == n+1){
            if(maxis.size() == 1)
                cout<<"! "<<it<<" "<<maxis[0]<<endl;
            else
                cout<<"! "<<maxis[0]<<" "<<maxis[1]<<endl;
            cin>>r1;
        }
        //si hay al menos dos que generan el mismo valor maximo, yo no soy cero
        // y mejor tomo otro pivote
        else if(maxis.size()==2){
            it = maxis[0];
            r1 = maxis[1];
            maxis.clear();
            cout<<"? "<<it<<" "<<r1<<endl;
            cin>>maxi;
            maxis.push_back(r1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}