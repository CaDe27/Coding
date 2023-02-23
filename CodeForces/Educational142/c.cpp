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

int l[4*maxN+1], r[4*maxN+1], f[4*maxN+1]; 
    
    //procedure to initiliaze segment tree
    void init(int i, int a, int b){
        l[i] = a;
        r[i] = b;
        if(a==b) return;
        
        int m = (a+b)/2;
        init(2*i, a, m);
        init(2*i+1, m+1, b);
    }
    
    void SegmentTree(int n){
        init(1, 1, n);
    }

    void update(int a, int val){
        int i = 1;
        while(!(l[i]==a && r[i]==a)){
            if(r[i<<1]>=a)
                i = i<<=1;
            else
                i = (i<<=1)+1;
        }
        f[i] = val;

        while(i != 1){
            f[i>>1] = i&1? max(f[i], f[i-1]) : max(f[i], f[i+1]);
            i>>=1;
        }
    }

    int query(int i, int a, int b){
        if(b < l[i] || r[i] < a)
            return 0; 
        
        if(a <= l[i] && r[i] <= b)
            return f[i];
        else{
            //BE CAREFUL with overflow
            int leftQ =  query(2*i, a, b);
            int rightQ = query(2*i+1, a, b);
            return max(leftQ, rightQ);
        }
    }

    int query(int a, int b){
        return query(1, a, b);
    }


int indx[maxN];
void solve(){
    cin>>n;
    int v;
    
    loop(i, 0, n){
        cin>>v;
        indx[v] = i+1;
    }
    int ri = 0, resp = n;
    loop(i, 1, n+1){
        ri = max(ri, query(indx[i], n));
        update(indx[i], i);
        resp = min(resp, max(n-i, ri));
    }
    cout<<resp<<"\n";
    
    loop(i, 1, n+1){
        update(indx[i], 0);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    SegmentTree(200000);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}