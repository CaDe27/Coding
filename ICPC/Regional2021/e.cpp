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
int n;
int arre[maxN];
int mi[maxN], md[maxN];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    cin>>n;
    loop(i, 0, n){
        cin>>arre[i];
    }
    fill(mi, mi+n, -1);
    fill(md, md+n, -1);

    stack<int> pila;
    int v;
    loop(i, 0, n){
        v = arre[i];
        while(!pila.empty() && arre[pila.top()] < v){
            md[pila.top()] = i;
            pila.pop();
        }
        mi[i] = pila.empty()? -1 : pila.top();
        pila.push(i);
    }

    int resp[n], izq, der;
    fill(resp, resp + n, 0);
    loop(i, 0, n){
        //updateo a la izq
        izq = mi[i] == -1? 0 : (i+mi[i]+2)/2;
        der = md[i] == -1? n-1 : (md[i]+i-1)/2;

        //updateo a la der
        resp[izq] += 1;
        resp[i] -= 1;
        resp[i+1] += 1;
        resp[der+1] -= 1;
    }

    cout<<resp[0];
    loop(i, 1, n){
        resp[i] += resp[i-1];
        cout<<" "<<resp[i];
    }
    cout<<"\n";
    
    
    
    return 0;
}