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

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)


const int maxN = 100005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;cin>>n;
    int l, r, cont;
    ll suma = 1;
    l = 1; r = 1; cont = 0;
    while(l < n){
        while(suma + r+1 <= n){
            ++r;
            suma +=  r;
            
            if(suma == n)
                ++cont;
            
        }
        suma -= l;
        if(suma == n)
                ++cont;
        ++l;
    }
    ++cont;
    cout<<cont<<'\n';
}