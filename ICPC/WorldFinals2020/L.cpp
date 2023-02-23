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
#include <fstream>

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(ll i = a; i < b; ++i)
const int maxN = 200000 + 5;
int n, k;

int r[maxN], d[maxN];
vector<pii> h[maxN], v[maxN];
void solve(){
    cin>>n>>k;
    ll heights[maxN];
    fill(heights, heights + maxN, 0);

    char c; 
    int paridad;
    int x1, x2, radio;
    loop(i, 0, k){
        cin>>c>>x1>>x2;
        if(c == 'R'){
            r[x1] += 1;
            r[x2 + 1] -= 1;
        }
        else if(c == 'D'){
            d[x1] -= 1;
            d[x2 + 1] += 1;
        }
        else if(c == 'H'){
            radio = (x2 - x1 + 1)/2;
            paridad = (x2 - x1 + 1) % 2;
            h[x1].push_back(pii(1, 0));
            h[x1 + radio].push_back(pii(-1, -radio));
            v[x1 + radio].push_back(pii(1, radio + paridad + 1));
            v[x2 + 1].push_back(pii(-1, -1));
        }
        else{
            radio = (x2 - x1 + 1)/2;
            paridad = (x2 - x1 + 1) % 2;
            v[x1].push_back(pii(1,0));
            v[x1 + radio].push_back(pii(-1, radio));
            h[x1 + radio].push_back(pii(1, -(radio + paridad) - 1));
            h[x2 + 1].push_back(pii(-1, 1));
        }
    }

    ll add = 0, activosH = 0, activosV = 0;
    loop(i, 1, n+1){
        add += r[i];
        add += d[i];
        for(pii p : h[i]){
            activosH += p.first;
            add += p.second;
        }
        for(pii p : v[i]){
            activosV += p.first;
            add += p.second;
        }
        add += activosH;
        add -= activosV;
        heights[i] = add;
    }

    loop(i, 1, n+1){
        cout<<heights[i]<<"\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}