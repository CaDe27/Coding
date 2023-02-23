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

const int maxN = 2e5 + 5;
int n;
int a[maxN];
int resp1[maxN], resp2[maxN];
int oc[maxN];
set<int> once, twice, non;
vector<int> pos[maxN];

void solve(){
    cin>>n;
    once.clear();
    twice.clear();
    non.clear();
    fill(oc, oc+(n+1), 0);
    loop(i, 1, n+1)
        pos[i].clear();

    loop(i, 0, n){
        cin>>a[i];
    }

    loop(i, 0, n){
        oc[a[i]]++;
        pos[a[i]].push_back(i);
        if(oc[a[i]] > 2){
            cout<<"NO\n";
            return;
        }
    }
    
    loop(i, 1, n+1){
        if(oc[i] == 0){
            non.insert(i);
        }
        else if(oc[i] == 1)
            once.insert(i);
        else
            twice.insert(i);
    }

    for(int v : once){
        resp1[pos[v][0]] = v;
        resp2[pos[v][0]] = v;
    }

    for(int v : twice){
        int x = *(non.begin());
        if(x > v) {
            cout<<"NO\n";
            return;
        }
        else{
            non.erase(x);
            resp1[pos[v][0]] = v;
            resp2[pos[v][0]] = x;

            resp2[pos[v][1]] = v;
            resp1[pos[v][1]] = x;
        }
    }
    cout<<"YES\n";
    loop(i, 0, n){
        cout<<resp1[i]<<" ";
    }
    cout<<"\n";
    loop(i, 0, n){
        cout<<resp2[i]<<" ";
    }
    cout<<"\n";

    
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