#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> pll;
const int maxN = 1e6+5;
ll altura[maxN];
ll areaMax;

stack<pll> s; 
void agrega(ll h){
    ll como = 0; 
    while(!s.empty() && h <= s.top().first ){
        como += s.top().second + 1;
        areaMax = max(areaMax, s.top().first*como);
        s.pop();
    }
    s.push(pll(h, como));
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll altura;
    areaMax = 0;
    for(int i = 0; i < n; ++i){
        cin>>altura;
        agrega(altura);
    }
    agrega(0);

    cout<<areaMax<<"\n";

}