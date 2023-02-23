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

using namespace std;

typedef int64_t ll;
typedef pair<int,ll> pill;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;
int n, arre[maxN];
string s; 
void solve(){
    cin>>s;
    int val  = 0;
    loop(i,0,s.size())
    {
        val += s[i]-'a' + 1;
    }
    int alice, bob;
    
    if(s.size()%2 == 0)
        alice = val;
    else
        alice = max(val - (s[0]-'a'+1), val -(s[s.size()-1]-'a'+1));
    
    bob = val - alice;
    //cout<<alice<<" "<<bob<<endl;
    if(alice > bob){
        cout<<"Alice "<<alice-bob<<"\n";
    }
    else{
        cout<<"Bob "<<bob-alice<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
