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

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;

#define MINF -1000000000000
#define MOD 

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)


const int maxN = 100005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    ll maxi, acum;
    cin>>n>>k;

    ll arre[n];
    cin>>arre[0];

    acum = 0;
    loop(i, 1, k){
        cin>>arre[i];
        acum += arre[i] - arre[i-1];
    }

    maxi = acum;

    loop(i,k, n){
        cin>>arre[i];
        acum += arre[i] - arre[i-1];
        acum -= arre[i-k+1] - arre[i-k];
        maxi = max(maxi, acum);
    }

    cout<<maxi<<'\n';
    
}
