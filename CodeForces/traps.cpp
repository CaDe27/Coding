#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef int64_t ll;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    ll arre[200000], resp; 
    while(t--){
        int n, k; cin>>n>>k;
        resp = 0;
        for(int i = 0; i < n;++i){
            resp += n-1-i;
            cin>>arre[i];
            arre[i] -= n-1-i;
        }
        sort(arre, arre+n);
        for(int i = 0; i < n-k; ++i){
            resp += arre[i];
        }
        for(int i = 0; i < k; ++i)
            resp -= i;
        cout<<resp<<"\n";
    }
}