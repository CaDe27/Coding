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
typedef pair<pii,int> piii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(ll i = a; i < b; ++i)

const int maxP = 1e6+10;
int n, m;
int fE,cE;

char matc[1005][1005];
int mat[1005][1005];
bool v[1005][1005];
void BFS(){
    queue<piii> q;
    q.push(piii(pii(fE, cE), 0));
    while(!q.empty()){
        int f = q.front().first.first, c = q.front().first.second;
        int llegada = q.front().second;
        q.pop();

        if(!v[f][c]){
            v[f][c] = true;
            if(mat[f][c] != -1){
                mat[f][c] = llegada;
                if(f-1 >=0) q.push(piii(pii(f-1, c), llegada+1));
                if(f+1 < n) q.push(piii(pii(f+1, c), llegada+1));
                if(c-1 >=0) q.push(piii(pii(f, c-1), llegada+1));
                if(c+1 < m) q.push(piii(pii(f, c+1), llegada+1));
            }
        }
    } 
}

void solve(){
   cin>>n>>m;
    loop(i, 0, n)
    loop(j, 0, m){
        cin>>matc[i][j];
        mat[i][j] = -2;
        if(matc[i][j] == 'E'){
            fE = i; cE = j;
        }
        else if(matc[i][j]=='X' || matc[i][j]=='#')
            mat[i][j] = -1;
    }
    BFS();
    int q; cin>>q;
    int a,b;
    loop(i, 0, q){
        cin>>a>>b;
        --a;--b;
        if(matc[a][b] == 'X'){
            cout<<"X\n";
        }
        else if(matc[a][b] == '#'){
            cout<<"W\n";
        }
        else if(matc[a][b] == 'E'){
            cout<<"E\n";
        }
        else{
            if(mat[a][b] == -2)
                cout<<"?\n";
            else if(b-1>=0 && mat[a][b-1]>=0 && mat[a][b-1] < mat[a][b])
                cout<<"L\n";
            else if(a+1<n && mat[a+1][b] >= 0 && mat[a+1][b] < mat[a][b])
                cout<<"D\n";
            else if(b+1<m && mat[a][b+1] >= 0 && mat[a][b+1] < mat[a][b])
                cout<<"R\n";
            else if(a-1>=0 && mat[a-1][b]>= 0 && mat[a-1][b] < mat[a][b])
                cout<<"U\n";
        }
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