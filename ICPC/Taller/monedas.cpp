#include <iostream>
#include <algorithm>
using namespace std;

typedef int64_t ll;

//lo que podemos demostrar es esto
// si en un momento tienes las monedas a1, a2, ... , ak y puedes gastar 
// 1, 2, ..., b
// y te dan una moneda con valor menor o igual a 1+2+...+b , sea de valor m,
// entonces puedes gastar hasta 1+2+...+b+m 

int main(){
    int n;
    cin>>n;

    ll arre[n];
    for(int i = 0; i < n; ++i)
        cin>>arre[i];

    sort(arre, arre+n);

    ll maxi = 0;
    int pos = 0;

    while(pos < n && arre[pos] <= maxi+1 ){
        maxi += arre[pos];
        ++pos;
    }
    cout<<maxi+1<<"\n";

    return 0;
}