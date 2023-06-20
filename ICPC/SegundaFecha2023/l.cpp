#include <iostream>
#include <algorithm>
using namespace std;

typedef int64_t ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m, k;
    cin>>n>>m>>k;
    if(m*k <= n)
        cout<<"Iron fist Ketil\n";
    else
        cout<<"King Canute\n";
    return 0;
}