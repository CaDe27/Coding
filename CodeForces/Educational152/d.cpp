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

const int maxN = 200005;
int n;
int a[maxN], next0[maxN], cont2[maxN];

bool contains2(int ini, int fin){
    return (cont2[fin] - (ini > 0? cont2[ini-1] : 0)) > 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n;
    loop(i, 0, n)
        cin>>a[i];
    
    int indx0 = n;
    for(int i = n-1; i >= 0; --i){
        next0[i] = indx0;
        if(a[i] == 0)
            indx0 = i;
    }

    cont2[0] = (a[0] == 2);
    for(int i = 1; i < n; ++i){
        cont2[i] = cont2[i-1];
        if(a[i] == 2)
            ++cont2[i];
    }

    int it = 0, coins = 0;
    while(it < n){
        if(a[it] > 0){
            ++coins;
            it = next0[it] + 1;
        }
        else{
            if(next0[it] == it+1){
                ++coins;
                ++it;
            }
            else{
                ++coins;
                if(contains2(it, next0[it]-1)){
                    it = next0[it]+1;
                }
                else{
                    it = next0[it];
                }
            }
        }
    }
    cout<<coins<<"\n";

    return 0;
}