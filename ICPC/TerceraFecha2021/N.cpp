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
typedef long long ll;

vector<int> P;
vector<int> bit;
const int MAXN = 3e5+10;

int sum(int i){
    int sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= i&(-i);
    }
    return sum;
}

void add(int i){
    while(i <= MAXN){
        bit[i]++;
        i += i&(-i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int y,n; cin >> y >> n;
    
    P.push_back(0);
    
    vector<int> pos[MAXN];
    
    for(int i=0;i<y;i++){
        int a; cin >> a;
        P.push_back(a);
        pos[a].push_back(i+1);
    }
        
    vector<vector<int>> queries;
    
    for(int i=0;i<n;i++){
        int a,p,f; cin >> a >> p >> f;
        queries.push_back({-p,a,a+f,i});
    }
    
    sort(queries.begin(),queries.end());
    
    bit.assign(MAXN+1,0);
    
    int ans[n];
    
    int prev = MAXN-1;

    for(auto Q:queries){
        int p = -Q[0];
        int l = Q[1];
        int r = Q[2];
        if(P[l] < p){
            for(int i=prev-1;i >= p; i--){
                for(auto j:pos[i]){
                    add(j);
                }
            }
            prev = p;
            ans[Q[3]] = sum(r)-sum(l-1);
        }
        else{
            ans[Q[3]] = 0;
        }
    }
    
    for(int i=0;i<n;i++){
        cout << ans[i] << "\n";
    }
    

    return 0;
}
