#include <iostream>
#include <string>
using namespace std;

string solve(){
    int n, m; cin>>n>>m;
    int n1 = 0, n2 = 0, m1 = 0, m2 = 0;
    while(n %2 == 0){++n1; n/=2;}
    while(m %2 == 0){++m1; m/=2;}
    while(m %3 == 0){++m2; m/=3;}
    while(n %3 == 0){++n2; n/=3;}
    if(m == n && 0 <= m1-n1 && m1-n1 <= n2-m2)
        return "YES";
    else
        return "NO";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
    return 0;
}