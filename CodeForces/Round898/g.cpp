#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>
#define INF 1000000000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;
const int maxN = 500005;
string s; 
void solve(){
    cin>>s;
    int count = 0;
    loop(i, 0, s.size())
        count += s[i] == 'A';
    
    bool twoB = false;
    loop(i, 1, s.size())
        if(s[i] == 'B' && s[i-1] == 'B')
            twoB = true;
    
    if(s[0] == 'B' || s[s.size()-1] == 'B' || twoB){
        cout<<count<<"\n";
    }
    else{
        //elimino menor bloque de a's
        s += "B";
        int minBloque = 1e9, countBloque = 0;
        for(int i = 0; i < s.size(); ++i)
            if(s[i] == 'A')
                ++countBloque;
            else if(i > 0 && s[i] == 'B' && s[i-1] == 'A'){
                minBloque = min(minBloque, countBloque);
                countBloque = 0;
            }
        cout<<(count-minBloque)<<"\n"; 
    }   
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}