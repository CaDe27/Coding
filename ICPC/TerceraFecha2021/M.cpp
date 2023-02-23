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

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define m(a,b) (a%b + b)%b
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 100005;


int state[maxN];
int repre[maxN];
int monarca = 1;

priority_queue<int, vector<int>, greater<int> > descendants[maxN];

int dfs(int x){
    if(state[x] == 1) return x;
    else{
        int firstAlive = -1, son;
        while(firstAlive == -1 && !descendants[x].empty()){
            son = descendants[x].top();
            firstAlive = dfs(son);
            if(firstAlive == -1)
                descendants[x].pop();
        }
        return firstAlive;
    }
}

void solve(){

    int q; cin>>q;
    int t, x, firstAlive;
    int nextId = 2;
    loop(i, 0, q){
        cin>>t>>x;
        if(t == 1){
            descendants[x].push(nextId);
            state[nextId] = 1;
            repre[nextId] = x; 
            ++nextId;
        }
        else{
            state[x] = 0;
            if(x == monarca){
                firstAlive = dfs(x);
                while(firstAlive == -1){
                    x = repre[x];
                    descendants[x].pop();
                    firstAlive = dfs(x);
                } 
                monarca = firstAlive;
            }
            cout<<monarca<<"\n";
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
