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
int n;
string s, t, z;

bool check(int i, int j){
    loop(it, i, j){
        if(z[it] == z[it+1])
            return false;
    }
    return true;
}
string solve(){
    int a, b; cin>>a>>b;
    a+=b;
    cin>>s>>t;
    reverse(t.begin(), t.end());
    z = s+t;

    int it = 0;
    while(it < a-1 && z[it] != z[it+1])
        ++it;
    
    if(it == a-1)
        return "YES";
    
    //cout<<"it "<<it<<endl;
    if(check(0, it) && check(it+1, a-1))
        return "YES";
    else
        return "NO";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
    return 0;
}