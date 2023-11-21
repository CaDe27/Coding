#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef int64_t ll;
int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b;
    cin>>n;
    ll resp = 0;
     
    vector<int> proms;
    n <<=1;
    for(int i=0; i<n; ++i){
        cin>>a>>b;
        if(a > b) swap(a,b);
        resp += (b-a);
        proms.push_back(a+b);
    }
    sort(proms.begin(), proms.end());
    n>>=1;
    for(int i = 0; i < n; ++i){
        resp += proms[2*n-1-i] - proms[i];
    }
    resp >>=1;
    cout<<resp<<"\n";
    return 0;
}