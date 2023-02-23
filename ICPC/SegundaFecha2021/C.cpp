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
#include <fstream>

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(ll i = a; i < b; ++i)

const int maxP = 1e6+10;
int n, m;

void solve(){
    string s;
    cin>>s;
    int ini = 0;
    int suma = 0;
    loop(i, 0, s.size()){
        if(s[i] == 'B')
            ++suma;
        else
            --suma;
        if(suma < 0){
            ini = i+1; suma = 0;
        }
    }

    s= s.substr(ini, s.size()-ini) + s.substr(0, ini);
    suma = 0;
    loop(i, 0, s.size()){
        if(s[i] == 'B')
            ++suma;
        else
            --suma;
        if(suma < 0){
            cout<<"-1"<<"\n";
            return;
        }
    }
    cout<<ini<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t;
     cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}