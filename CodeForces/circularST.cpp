//Available in https://codeforces.com/contest/52/problem/C

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <climits>
 
#define loop(i, a, b) for(int i = a; i < b; ++i)
 
using namespace std;
typedef int64_t ll;
 
const int maxN = 200000;
int n;
 
// ======================== Segment Tree ================================
int l[4*maxN+1], r[4*maxN+1];
ll funct[4*maxN+1], delta[4*maxN+1]; 
//if instead of incrementing, you need other aggregate update function, 
// change propagate, update and incrementI and queryI
void init(int i, int a, int b){
    l[i] = a;
    r[i] = b;
    funct[i] = 0;
    delta[i] = 0;
    if(a==b) return;
    int m = (a+b)/2;
    init(2*i, a, m);
    init(2*i+1, m+1,b);
}

void SegmentTree(int n){
    init(1, 0, n-1);
}
 
void propagate(int i){
    delta[2*i] += delta[i];
    delta[2*i + 1] += delta[i];
    delta[i] = 0;
}
 
void update(int i){
    //its now implemented with min
    funct[i] =  min(funct[2*i] + delta[2*i], funct[2*i+1] + delta[2*i+1]);
}
 
void incrementI(int i, int a, int b, ll val){
    if(b < l[i] || r[i] < a)
        return;
        
    if( a<=l[i] && r[i]<=b ){
        delta[i] += val;
        return;
    }
        
    propagate(i);
    incrementI(2*i, a, b, val);
    incrementI(2*i+1, a, b, val);
    update(i);    
}
 
void increment(int a, int b, ll val){
    incrementI(1, a, b, val);
}
 
ll queryI(int i, int a, int b){
    if(b < l[i] || r[i] < a)
        return 200001000001;
        
    if(a <= l[i] && r[i] <= b)
        return funct[i] + delta[i];
        
    propagate(i);
    ll leftQ =  queryI(2*i, a, b);
    ll rightQ = queryI(2*i+1, a, b);
    update(i);
    return min(leftQ, rightQ);
}
 
ll query(int a, int b){
    return queryI(1, a, b);
}
// ================================================================
 
ll leeV(string s){
    ll v = 0, signo = 1;
    int size = s.size();
    int j = 1;
    if(s[j] == '-'){
        signo = -1;
        ++j;
    }
    while(j < size && s[j]<='9' && s[j] >= '0'){
        v = v*10 + (s[j]-'0');
        ++j;
    }
    return v*signo;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
 
    SegmentTree(n);
    loop(i, 0, n){
        int val; cin>>val;
        increment(i,i, val);
    }
    int m; cin>>m;
    loop(i, 0, m){
        string s;
        int a, b;
        cin>>a>>b;
        getline(cin, s);
        if(s[0] == ' '){
            ll v = leeV(s);
            if(a > b){
                increment(0, b, v);
                increment(a, n-1, v);
            }
            else
                increment(a, b, v);
        }else{
            if(b < a){
                cout<<min(query(0, b), query(a, n-1))<<endl;
            }else
                cout<<query(a, b)<<endl;
        }
    }
    return 0;
}