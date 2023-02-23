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

const int maxN = 50+5;
int n, arre[maxN*maxN], mat[maxN][maxN];

void solve(){
    cin>>n;
    for(int num = 1, indx = 0; indx < n*n ; indx+=2, num += 1){
        arre[indx] = num;
    }
    for(int num = n*n, indx = 1; indx < n*n ; indx+=2, num -= 1){
        arre[indx] = num;
    }
    for(int i = 0; i < n; i += 2){
        loop(j, 0, n)
            mat[i][j] = arre[i*n + j]; 
    }
    for(int i = 1; i < n; i += 2){
        loop(j, 0, n)
            mat[i][n-1-j] = arre[i*n + j]; 
    }

    loop(i, 0, n){
        loop(j, 0, n)
            cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
    
}