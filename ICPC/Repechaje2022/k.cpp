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
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)


char mapeo(char x){
    if(x <= 'r')
        return ((x-'a')/3 + 2)+'0';
    if(x == 's')
        return '7';
    if(x <= 'v')
        return '8';
    return '9';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n, q; cin>>n>>q;
    string s; 
    map<string, int> queries;
    loop(i, 0, n){
        cin>>s;
        string nex = "";
        loop(i, 0, s.size()){
            nex += mapeo(s[i]);
        }
        ++queries[nex];
    }

    loop(i, 0, q){
        cin>>s;
        cout<<queries[s]<<"\n";
    }
    
    return 0;
}