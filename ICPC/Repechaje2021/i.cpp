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

const int maxN = 200005; 
void solve(){
    int n, c, b, w, r, g;
    cin>>n>>c>>b>>w>>r>>g;
    if(b*c + r < n)
        cout<<"Don't even try!\n";
    else{
        int resp = -1;
        if(n <= b*c)
            resp = n;
        else{
            resp = b*c;
            n -= b*c;
            resp += n*c;
        }
        cout<<resp<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0;

}