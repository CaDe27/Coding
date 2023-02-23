#include <iostream>

using namespace std;

int main(){
    
    int n;
    cin>>n;

    int a, maxA, sumElements;
    maxA = 0;
    sumElements = 0;

    for(int i = 0; i < n; i++){
        cin>>a;
        maxA = max(a, maxA);
        sumElements += a;
    }
    cout<<maxA*n - sumElements<<"\n";

    return 0;
}