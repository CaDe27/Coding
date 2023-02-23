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
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 100005;
int n;

stack<int> odd, even;
void solve(){
    cin>>n;
    int aux;
    while(!odd.empty()) odd.pop();
        while(!even.empty()) even.pop();
    loop(i, 0, n){
        cin>>aux;
        if(aux%2)
            odd.push(i+1);
        else
            even.push(i+1);   
    }
    if(odd.size() >= 3){
        cout<<"YES\n";
        loop(i, 0, 3){
            cout<<odd.top()<<" ";
            odd.pop();
        }
        cout<<"\n";
    }
    else if(odd.size() >=1 && even.size()>=2){
        cout<<"YES\n";
        cout<<odd.top()<<" ";
        odd.pop();
        cout<<even.top()<<" ";
        even.pop();
        cout<<even.top()<<"\n";
        even.pop();
    }
    else{
        cout<<"NO\n";
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}