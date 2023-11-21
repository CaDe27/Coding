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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n; cin>>n;
    int mini = 1e9, a[n];
    loop(i, 0, n)
        cin>>a[i];

    loop(i, 0, n)
        mini = min(mini, a[i]);
    
    bool possible = true;
    loop(i, 0, n){
        if(a[i]%mini != 0 && mini > (a[i]-1)/2)
            possible = false;
    }

    cout<<(possible? mini : mini/2)<<"\n";
    return 0;
}
