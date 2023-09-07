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
int n, m;
string s;
int sig1[maxN], ant0[maxN];
set<pii> st;

bool modifies(pii a){
    if(sig1[a.first] == -1 || ant0[a.second] == -1)
        return false;
    return sig1[a.first] < ant0[a.second];
}

void solve(){
    cin>>n>>m;
    cin>>s;
    st.clear();

    int indxUno = -1;
    for(int i = n-1; i >= 0; --i){
        if(s[i] == '1')
            indxUno = i;
        sig1[i] = indxUno;
    }

    int indxCero = -1;
    loop(i, 0, n){
        if(s[i] == '0')
            indxCero = i;
        ant0[i] = indxCero;
    }

    pii a;
    bool nonModifiedExists = false;
    loop(i, 0, m){
        cin>>a.first>>a.second;
        --a.first; --a.second;
        if(modifies(a)){
            st.insert(pii(sig1[a.first], ant0[a.second]));
        }else{
            nonModifiedExists = true;
        }
    }
    cout<<nonModifiedExists + st.size()<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}