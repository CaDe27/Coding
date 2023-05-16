#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k, l;
    cin>>n>>k>>l;
    if(n*k % l ==0){
        cout<<n*k/l<<"\n";
    }
    else{
        cout<<n*k/l + 1<<"\n";
    }
    return 0;
}