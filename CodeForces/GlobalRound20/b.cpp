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
bool solve(){
    string s;
    cin>>s;
    if(s.size() <= 1)
        return false;
    
    if(s[0] != 'A' || s[s.size()-1] != 'B')
        return false;

    int sum = 0;
    loop(i, 0, s.size()){
        if(s[i] == 'B')
            --sum;
        else
            ++sum;
        
        if(sum < 0)
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    loop(i, 0, t){
        if(solve())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0; 
}
