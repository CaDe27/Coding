#include <iostream>
using namespace std;

int main(){
    int64_t arre[1000000];
    fill(arre, arre+1000000, 0);
    int n; cin>>n;
    for(int i = 0, a;i < n; ++i){
        cin>>a;
        ++arre[a];
    }
    if(n == 1){
        cout<<"N\n";
        return 0;
    }
    int bitsPrendidos = 0;
    for(int i = 0; i < 1000000; ++i){
        if(arre[i]%2 == 1) ++bitsPrendidos;
        arre[i+1] += arre[i]>>1;
    }
    if(bitsPrendidos <= 2){
        cout<<"Y\n";
    }
    else{
        cout<<"N\n";
    }
    return 0;

    
}