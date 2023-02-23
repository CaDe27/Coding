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
#include <sstream>

using namespace std;

typedef int64_t ll;
typedef long double ld;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define MINF -1000000000000
#define MOD 1000000007

#define m(a,b) (a%b + b)%b
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)

const int maxN = 1005;
int n, m;

string s;
vector<int> sf;


// O(nlogn)
vector<int> suffix_array(string& s) {
    s.push_back('$');
    int N = s.size();
    vector<int> p(N), c(N);
    {  // k = 0
        vector< pair<char, int> > a(N);
        for (int i = 0; i < N; ++i)
            a[i] = make_pair(s[i], i);
        sort(a.begin(), a.end());
        for (int i = 0; i < N; ++i)
            p[i] = a[i].second;
        for (int i = 1; i < N; ++i)
            c[p[i]] = a[i].first == a[i - 1].first ? c[p[i - 1]] : c[p[i - 1]] + 1;
    }
    for (int k = 0; (1 << k) < N; ++k) {
        for (int i = 0; i < N; ++i)
            p[i] = (p[i] - (1 << k) + N) % N;
        {  // Counting sort
            vector<int> cnt(N), pos(N), p_new(N);
            for (auto x : c)
                cnt[x]++;
            for (int i = 1; i < N; ++i)
                pos[i] = pos[i - 1] + cnt[i - 1];
            for (auto x : p)
                p_new[pos[c[x]]++] = x;
            p = p_new;
        }
        vector<int> c_new(N);
        for (int i = 1; i < N; ++i) {
            pii prev = make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % N]);
            pii now = make_pair(c[p[i]], c[(p[i] + (1 << k)) % N]);
            c_new[p[i]] = now == prev ? c_new[p[i - 1]] : c_new[p[i - 1]] + 1;
        }
        c = c_new;
    }
    s.pop_back();
    return vector<int>(p.begin() + 1, p.end());
}

string ss;
int sizeA;
int itS;

bool menorIgual(int itS, int pos){
    int it1 = pos, it2 = itS;
    while(it1 < n  && it2 < sizeA && ss[it2] == s[it1]){++it1; ++it2;}
    return it1 == n || (it2 < sizeA && ss[it2] >= s[it1]); 
}

bool mayorIgual(int itS, int pos){
    int it1 = pos, it2 = itS;
    while(it1 < n && it2 < sizeA && ss[it2] == s[it1]){++it1; ++it2;}
    return it2 == sizeA || (it1 < n && ss[it2] <= s[it1]); 
}


int maxCoinci(int itS, int pos){
    int it1= pos, it2 = itS;
    while(it1 < n && it2 < sizeA && ss[it2] == s[it1]){++it1; ++it2;}
    return it1 - pos;
}

int lower(int itS){
    int ini = 0, fin = n-1, mitad;
    
    // + + + + + - - - - 
    //queremos maximo +
    while(ini != fin){
        mitad = (ini + fin + 1)/2;
        if( menorIgual(itS, sf[mitad]))
            ini = mitad;
        else
            fin = mitad - 1;
    }
    return maxCoinci(itS, sf[ini]);
    
}

int upper(int itS){
    int ini = 0, fin = n-1, mitad;
    
    // - - - - - + + + + 
    //queremos mínimo + 
    while(ini != fin){
        mitad = (ini + fin)/2;
        if( mayorIgual(itS,  sf[mitad] ))
            fin = mitad;
        else
            ini = mitad + 1;
    }
    return maxCoinci(itS, sf[ini]);
}
int query(string ss){
    int itS = 0;
    int cont = 0;
    bool sePuede = true;    
    while(sePuede && itS < sizeA){
       ++cont;
       int maxCoincidencia = max(lower(itS), upper(itS));
       if(maxCoincidencia == 0) sePuede = false;
       itS = itS + maxCoincidencia;
    }
    return sePuede? cont : -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    cin>>s;

    sf = suffix_array(s);
    n = s.size();
    
    int q; cin>>q;
    loop(i, 0, q){
        cin>>ss;
        sizeA = ss.size();
        cout<<query(ss)<<"\n";
    }
    return 0;

}

