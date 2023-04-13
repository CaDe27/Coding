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
#define loop(i,a,b) for(int i = a; i < b; ++i)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n; cin>>n;
    string s; cin>>s;
    int w = 0, maxiW;
    loop(i, 0, n){
        if(s[i] == 'W') ++w;
    }
    maxiW = w;
    loop(i, n, 2*n-1){
        //sumo el i
        if(s[i] == 'W')++w;
        // quito el i-n
        if(s[i-n] == 'W') --w;
        maxiW = max(maxiW, w);
    }
    cout<<maxiW<<"\n";
    return 0;
}