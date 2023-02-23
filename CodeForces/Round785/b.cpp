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
#include <unordered_map>

using namespace std;

typedef int64_t ll;
typedef pair<int,ll> pill;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;
string s;
map<char, int> bucketS;
set<char> sL;
string f(char c){
    unordered_map<char, int> bucket;
    string resp = "YES";
    for(char x : s){
        bucket[x] = 0;
    }
    bucket[c] = 2;

    int ini=0, fin;
    ini = s.find(c);

    fin = ini+1;
    while(s[fin] != c){
        ++bucket[s[fin]];
        ++fin;
    }
    
    while(resp == "YES" && fin != s.size()){
        for(char c : sL){
            if(bucket[c] == 0)
                resp = "NO";
        }
        ++ini;
        while(ini != fin){
            --bucket[s[ini]];
            ++ini;
        }
        ++fin;
        while(fin != s.size() && s[fin]!=c){
            ++bucket[s[fin]];
            ++fin;
        }
    }
    return resp;
}

void solve(){
    string resp = "YES";
    cin>>s;
    for(char c ='a'; c <= 'z'; ++c)
        bucketS[c] = 0;
    sL.clear();
    for(char c : s){
        ++bucketS[c];
        sL.insert(c);
    }
     
    for(char c = 'a'; c<='z'; ++c){
        if(resp == "NO")
            break;
        if(bucketS[c]<=1) continue;
        resp = f(c);
    }
    cout<<resp<<"\n";
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
