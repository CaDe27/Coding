#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

#define ll long long
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define loop(i, a, b) for(int i = a; i < b; ++i)
 
using namespace std;
 
const int MAXN = 2e5 + 50;
 
map<char, int> to[MAXN];
// tms has the lengths of each string in the list
vector <int> tms, leaf[MAXN], send[MAXN];
int trieSz = 1, link[MAXN], que[MAXN], endlink[MAXN]; 
void add_str(string &s, int id) {
    int v = 0;
    for(char c: s) {
        if(!to[v].count(c)) to[v][c] = trieSz++;
        v = to[v][c];
    }
    leaf[v].push_back(id);
}
void push_links() {
    queue<int> q; q.push(0);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(pair<char, int> aux : to[v])
        {
            char c = aux.first; int u = aux.second;
            int j = link[v];
            while(j && !to[j].count(c)) j=link[j];
            if(to[j].count(c) && to[j][c]!=u) link[u] = to[j][c];
            endlink[u] = leaf[link[u]].size()>0?link[u]:endlink[link[u]];
            q.push(u);
        }
    }
}
void walk(string s) { // Dado un conjunto de patrones encuentra todas las coincidencias en una string. aka KMP con muchos patrones.
    int v=0;
    loop(i,0,s.size()) {
        char c=s[i];
        while(v && !to[v].count(c)) v=link[v];
        if(to[v].count(c)) v=to[v][c]; 
        for(int u=v;u;u=endlink[u]) for(int x: leaf[u]){
            //x: indice de la palabra:
            //i: donde termina
            ll tami = tms[x];
            send[i-tami+1].push_back(i+1);
        }
            
    }
}
 
string s;
vector <ll> dp;
int n,len;
const ll mod = 1e9+7;
 
void init(){
    dp.assign(len+5,0LL);
}   
 
int main(){
    fast;
    cin>>n;
    tms.resize(n+5);
    for (int i = 0; i<n; i++){
        string t;
        cin>>t;
        tms[i] = t.size();
        add_str(t,i);
    }
    cin>>s;
    push_links();
    walk(s);
    len = s.size();
    init();
    dp[0] = 1;
    for (ll i = 0; i<len; i++){
        for (auto tra : send[i]) dp[tra] = ((dp[tra] + dp[i])%mod)%mod;
    }
    cout<<dp[len]%mod<<'\n';
    return 0;
}