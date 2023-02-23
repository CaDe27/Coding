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
#include <array>

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define INF 1000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 1e5 +5;
void solve(){
    int n, k; cin>>n>>k;
    vector<vector<int> > down_edge(k+1, vector<int>(k+1, 0)), 
                         right_edge(k+1, vector<int>(k+1, 0)),
                         distOrigin(k+1, vector<int>(k+1, INF));
    loop(i, 0, n){
        int r1, c1, r2, c2;
        cin>>r1>>c1>>r2>>c2;
        --r1;--r2;--c1;--c2;
        if(r1 == r2){
            if(c1 > c2) swap(c1, c2);
            ++down_edge[r1][c2];
            ++down_edge[k-r1-1][k-c2];
        }else{
            if(r1 > r2) swap(r1, r2);
            ++right_edge[r2][c1];
            ++right_edge[k-r2][k-c1-1];
        }
    }

    priority_queue<array<int, 3>, vector<array<int, 3> >, greater<array<int, 3> > > djikstra;
    array<int, 3> aux = {0, 0, 0};
    djikstra.push(aux);

    while(!djikstra.empty()){
        int d = djikstra.top()[0], r = djikstra.top()[1], c = djikstra.top()[2];
        djikstra.pop();
        if(d >= distOrigin[r][c])
            continue;
        distOrigin[r][c] = d;
        //up
        if(r > 0 && d + down_edge[r-1][c] < distOrigin[r-1][c]){
            array<int, 3> up = {d+down_edge[r-1][c], r-1, c};
            djikstra.push(up);
        }
        //down
        if(r < k && d + down_edge[r][c] < distOrigin[r+1][c]){
            array<int, 3> down = {d+down_edge[r][c], r+1, c};
            djikstra.push(down);
        }
        //right
        if(c < k && d + right_edge[r][c] < distOrigin[r][c+1]){
            array<int, 3> right = {d+right_edge[r][c], r, c+1};
            djikstra.push(right);
        }
        //left
        if(c > 0 && d + right_edge[r][c-1] < distOrigin[r][c-1]){
            array<int, 3> left = {d+right_edge[r][c-1], r, c-1};
            djikstra.push(left);
        }
    }
    cout<<n - distOrigin[(k+1)/2][(k+1)/2]<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    loop(i, 0, t)
        solve();
    return 0; 
}
