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
#define INF 1000000000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;

const int maxN = 500005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    ll l, r, b, k;
    cin>>l>>r>>b>>k;
    
    ll ini = 1, fin = l, mid;
    while(ini != fin){
        mid = (ini + fin)/2;
        if( l <= b*mid)
            fin = mid;
        else
            ini = mid+1;
    } 
    cout<<k*b*ini<<"\n";

    return 0;
}