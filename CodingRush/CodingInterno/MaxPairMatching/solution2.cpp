#include<iostream>
#include<queue>
using namespace std;

typedef int64_t ll;

int main(){
    int n; cin>>n;
    n<<=1;

    ll resp = 0;     
    ll a, b;
    priority_queue<ll, vector<ll>, greater<ll> >minHeap;
    for(int i = 0; i < n; ++i){
        cin>>a>>b;
        if(a > b) swap(a, b);
        resp += b;

        minHeap.push(a+b);
    }
    
    n>>=1;
    ll v;
    for(int i = 0; i < n; ++i){
        v = minHeap.top();
        minHeap.pop();
        resp -= v;
    }
    cout<<resp<<"\n";
}