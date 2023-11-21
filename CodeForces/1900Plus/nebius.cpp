//https://codeforces.com/contest/1804/problem/D
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
string f;
void solve(){
    int n, m;
    cin>>n>>m;
    ll mini = 0, maxi = 0;
    while(n--){
        cin>>f;
        ll ones = 0;
        loop(i, 0, m) ones += f[i] =='1';

        //min
        ll maxDoubleOnes = 0, maxContainsCero = 0;
        int i = 1;
        while(i < m){
            //cout<<"mini"<<endl;
            if(f[i] == '1' && f[i-1] == '1'){
                ++maxDoubleOnes;
                i+=2;
            }
            else
                i+=1;
        }
        maxDoubleOnes = min(maxDoubleOnes, (ll)m/4);

        //max
        i = 0;
        int lastUsed = -1;
        while(i < m){
            //cout<<"maxii"<<endl;
            if(i > 0 && f[i] == '0' && lastUsed != i-1){
                ++maxContainsCero;
                lastUsed = i;
                ++i;
            }
            else if(f[i] == '0' && i+1 < m){
                ++maxContainsCero;
                lastUsed = i+1;
                i+=2;
            }
            else
                ++i;
        }
        maxContainsCero = min(maxContainsCero, (ll)m/4);

        mini += ones - maxDoubleOnes;
        maxi += ones - ((ll)m)/4 + maxContainsCero;
    }
    cout<<mini<<" "<<maxi<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    solve();
    return 0;
}