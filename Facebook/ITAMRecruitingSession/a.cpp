#include <iostream>
#include <stack>
#define loop(i, a, b) for(int i = a; i < b; ++i)
#define MOD 1000000007
using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;

const int maxN = 1e6 +5;
ll arre[maxN];
ll xbox(int length){
    ll suma = 0, maxi = -1e10;
    int aux;
    
    for(int i = 0; i < length; ++i){
        suma += arre[i];
        maxi = max(maxi, suma);
        if(suma < 0)
            suma = 0;
    } 
    return maxi;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    int le;
    loop(i, 1, t+1){
        pii c[3];
        pii cod;
        cin>>cod.first>>cod.second;
        loop(i, 0, 3){
            cin>>c[i].first>>c[i].second;
        }
        loop(i, 0, 3){
            pii a,b, c;
            a = pii( c[(i+1)%3].first - c[(i+2)%3].first,  c[(i+1)%3].second - c[(i+2)%3].second);
            b = pii( cod.first - c[(i+2)%3].first,  cod.second - c[(i+2)%3].second);
            c = a = pii( c[(i+1)%3].first - c[(i+2)%3].first,  c[(i+1)%3].second - c[(i+2)%3].second);
        }
    }
}