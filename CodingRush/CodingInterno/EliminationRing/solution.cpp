#include <iostream>
#include <set>
using namespace std;

int main(){
    int n; cin>>n;
    set<int> diferentes;
    int num;
    int i = 0; 
    for(int i = 0; i < n; ++i){
        cin>>num;
        if(diferentes.size() < 3)
            diferentes.insert(num);
    }
    
    int resp = diferentes.size() == 2? n/2 + 1 : n;
    cout<<resp<<"\n";
    return 0; 
}