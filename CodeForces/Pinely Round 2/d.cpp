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
int n, m;
char a[505][505];
char sol[505][505];
int color[2] = {'B', 'W'};

void solve(){   
    cin>>n>>m;
    loop(i, 0, n){
    loop(j, 0, m){
        cin>>a[i][j];
    }
    }

    int parity = 0;
    //check each row
    loop(i, 0, n){
        loop(j, 0, m){
            if(a[i][j] != '.')
                parity ^= 1;
        }
        if(parity == 1){
            cout<<"-1\n";
            return;
        }
    }

    loop(j, 0, m){
        loop(i, 0, n){
            if(a[i][j] != '.')
                parity ^= 1;
        }
        if(parity == 1){
            cout<<"-1\n";
            return;
        }
    }

    int nextColor = 0;
    loop(i, 0, n){
        loop(j, 0, m){
            if(a[i][j] == 'U'){
                sol[i][j] = color[nextColor];
                nextColor ^= 1;
                sol[i+1][j] = color[nextColor];
            }
            else if(a[i][j] == '.')
                sol[i][j] = '.';
        }
    }

    loop(j, 0, m){
        loop(i, 0, n){
            if(a[i][j] == 'L'){
                sol[i][j] = color[nextColor];
                nextColor ^= 1;
                sol[i][j+1] = color[nextColor];
            }
        }
    }

    loop(i, 0, n){
        loop(j, 0, m){
            cout<<sol[i][j];
            if(j == m-1)
                cout<<"\n";
        }
    }
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