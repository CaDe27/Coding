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
int arre[maxN];
string s, b = "FBFFBFFB";
string solve(){
    cin>>n;
    cin>>s;
    bool no;
    for(int i = 0; i < 8; ++i){
        no = false;
        loop(j, 0, n)
            if(b[i+j] != s[j])
                no = true;
        if(no == false)
            return "YES";
    }
    return "NO";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
     b +=b;
     b += b;
    while(t--){
        cout<<solve()<<"\n";
    }
    return 0;
}