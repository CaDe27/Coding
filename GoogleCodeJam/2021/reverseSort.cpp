#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int solve(){
    int n; cin>>n;
    vector<int> L(n);
    for(int i = 0 ; i <n; ++i)
        cin>>L[i]; 
    
    int cost = 0, pos;
    for(int i = 1; i < n;++i){
        //look for i
        pos = i-1;
        while(L[pos] != i)
            ++pos;
            
        //sum cost
        cost += pos-(i-1)+1;
        
        //reverse
        reverse(L.begin() + (i-1) , L.begin() + pos+1);
    }
    
    return cost;
}

int main(){
    int T; cin>>T;
    for(int t = 1; t <= T; ++t){
        cout<<"Case #"<<t<<": "<<solve()<<"\n";
    }
    return 0;
}