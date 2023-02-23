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
vector<int> bits[maxN];
int bucket[maxN];

void solve(){
    int k;
    cin>>n;
    loop(i, 0, n){
        cin>>k;
        bits[i].clear();
        bits[i].resize(k);
        loop(j, 0, k){
            cin>>bits[i][j];
            ++bucket[bits[i][j]];  
        }
    }

    bool resp = false;
    loop(i, 0, n){
        resp = true;
        loop(j, 0, bits[i].size()){
            if(bucket[bits[i][j]] == 1)
                resp = false;
        }
        if(resp)
            break;
    }
    
    loop(i, 0, n){
        loop(j, 0, bits[i].size()){
            bucket[bits[i][j]] = 0;
        }
    }
    cout<<(resp? "Yes" : "No")<<'\n';
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