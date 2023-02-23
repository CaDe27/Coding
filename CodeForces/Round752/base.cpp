#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;
#define loop(i,a,b) for(int i = a; i < b; ++i)
 
const int maxN = 1e5 +10;
int n; 
int arre[maxN];
 
void solve(){
    cin>>n;
    string resp = "YES";
    for(int i = 1; i < n + 1; ++i)
        cin>>arre[i];
    
    int aux;
    for(int i = 1; i < n + 1; ++i){;
        bool encontre = false;
        for(int j = i+1; j>=2 && !encontre; --j)
            if(arre[i] % j > 0)
                encontre = true;
        if(!encontre)
            resp = "NO";
    }
    cout<<resp<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
