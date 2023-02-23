#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 



const int maxN = 1005;
bool visited[maxN][2];
int dp[maxN][2];
int x, y;
string s;
unordered_map<char, int> mapp;

int miCosto(char a, char b){
    if(a == b) return 0;
    else return a=='C'? x : y; 
}

int DP(int indx, char ant){
    if(indx == s.length()) return 0;

    if(!visited[indx][mapp[ant]]){
        visited[indx][mapp[ant]] = 1;
        int resp;
        if(s[indx] == '?'){
            resp = min(miCosto(ant, 'C') + DP(indx+1, 'C'), miCosto(ant, 'J') + DP(indx+1, 'J'));
        }
        else{
            resp = miCosto(ant, s[indx]) + DP(indx+1, s[indx]);
        }
        dp[indx][mapp[ant]] = resp;
    }
    return dp[indx][mapp[ant]];
}

int solve(){
    cin>>x>>y>>s;
    for(int i = 0; i < s.length();++i)
        fill(visited[i], visited[i]+ 2, 0);
    if(s[0] == '?') return min(DP(1, 'C'), DP(1, 'J'));
    else return DP(1, s[0]);
}

int main(){
    int T; cin>>T;
    mapp.insert(make_pair('C', 0));
    mapp.insert(make_pair('J', 1));

    for(int t = 1; t <= T; ++t){
        cout<<"Case #"<<t<<": "<<solve()<<"\n";
    }
    return 0;
}