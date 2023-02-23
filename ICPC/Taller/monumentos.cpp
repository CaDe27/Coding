#include <iostream>
//puede ser resuelto recursivamente
// F(1) = 1
// F(2) = 2
// F(n) = F(n-2) + F(n-1)
using namespace std;

typedef int64_t ll;
#define MOD 1000000

int main(){
    int n;
    cin>>n;

    int fibo[n+1];
    fibo[1] = 1;
    fibo[2] = 2;

    for(int i = 3; i <= n; i++)
        fibo[i] = (fibo[i-1] + fibo[i-2])%MOD;
    
    cout<<fibo[n]<<"\n";
    return 0;
}