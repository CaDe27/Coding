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
typedef int64_t ll;

using namespace std;
const int maxN = 500005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n = 100000, t = 2;
    cout<<t<<endl;
    for(int i = 0; i < t; ++i){
        cout<<n<<" "<<n<<endl;
        loop(i, 2, n+1)
            cout<<i<<" ";
        cout<<1<<endl;

    }
    return 0;
}