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
int n,k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>k;
    int mat[n][n];
    loop(i, 0, n)
    loop(j, 0 ,n){
        cin>>mat[i][j];
    }

    int cont = 0;
    loop(i, 0, n-k)
    loop(j, 0, n-k){
        if(mat[i][j] == mat[i][j+k] &&
           mat[i][j] == mat[i+k][k] &&
           mat[i][j] == mat[i+k][j+k])
           ++cont;
    }
    cout<<cont<<"\n";

    return 0;
}