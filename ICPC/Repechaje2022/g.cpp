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

ll n;
char ops[8];
int sizeOps = 0;

void addstr(const string &s){
    for(char c : s){
        if(sizeOps == 0){
            ops[sizeOps++] = c;
        }
        else if(ops[sizeOps-1] == c){
            --sizeOps;
        } 
        else{
            ops[sizeOps++] = c;
            if(sizeOps == 8) sizeOps = 0;
        }
    }
}

void add(char c){
    switch(c){
        case 'a':  
            addstr("a");
            break;
        case 'b':  
            addstr("b");
            break;
        case 'c':  
            addstr("bab");
            break;
        case 'd':  
            addstr("aba");
            break;
        default:
            break;
    }
}

ll mapeo(ll x, ll y){
    return (x-1)*n + y;
}

ll answer(int x, int y){
    iloop(i, sizeOps-1, -1){
        if(ops[i] == 'a')
            swap(x, y);
        else
            y = n+1-y;
    }
    return mapeo(x, y);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    int q; 
    cin>>n>>q;
    char c; int x,y;
    loop(i, 0, q){
        cin>>c;
        if(c == 'q'){
            cin>>x>>y;
            cout<<answer(x,y)<<"\n";
        }
        else{
            cin>>c;
            add(c);
        }
    }
    return 0;
}