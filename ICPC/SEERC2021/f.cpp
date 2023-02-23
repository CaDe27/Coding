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
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;

void solve(){
    int n;
    ll x, r, p, k;
    cin>>n>>x>>r>>p>>k;
    ll xDamage = x*n;
    vector<ll> regeneration(n, 0), poison(n, 0);
    for(int i= n-1; i>=0; --i){
        regeneration[i] = r*(n-i);
        poison[i] = p*(n-i);
    }

    string s; cin>>s;
    vector<int> posR, posP;
    int totReg = 0;
    loop(i, 0, n){
        if( s[i] == '0'){
            regeneration[i] = 0;
            posP.push_back(i);
        }
        else{
            ++totReg;
            posR.push_back(i);
        }
    }

    //first 
    int itP, itR;
    ll answer, answerCase = xDamage;
    if(totReg < k){
        itP = k - totReg;
        itR = totReg - 1;
        loop(i, 0, itP)
            answerCase += poison[posP[i]];
        loop(i, 0, totReg)
            answerCase += poison[posR[i]];
        answer = answerCase;
    }
    else{
        itP = 0;
        for(int i = totReg-1; i >= k; --i)
            answerCase -= regeneration[posR[i]];
        for(int i = k-1; i>=0; --i)
            answerCase += poison[posR[i]];
        itR = k-1;
        answer = answerCase;
    }

    while(itP < (n-totReg) && itP != k){
        answerCase += poison[posP[itP++]];
        answerCase -= regeneration[posR[itR]];
        answerCase -= poison[posR[itR]];
        answer = max(answerCase, answer);
    }

    cout<<answer<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
