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

const int maxN = 2e5+5;
int n;

string s;
int resp[maxN];

bool balanced(){
    int sum = 0;
    loop(i, 0, n){
        if(s[i] == '(')
            ++sum;
        else
        {
            if(sum == 0)
                return false;
            else
                --sum;
        }
    }
    return true;
}

void solve(){
    cin>>n;
    cin>>s;
    if(n%2 == 1){
        cout<<"-1"<<"\n";
        return;
    }

    int cont = 0; 
    loop(i, 0, n){
        if(s[i] == '(')
            ++cont;
    }
    if(cont != n/2){
        cout<<"-1"<<"\n";
        return;
    }

    if(balanced()){
        cout<<"1\n";
        loop(i, 0, n-1)
            cout<<"1 ";
        cout<<"1\n";
        return;
    }
    
    reverse(s.begin(), s.end());
    if(balanced()){
        cout<<"1\n";
        loop(i, 0, n-1)
            cout<<"1 ";
        cout<<"1\n";
        return;
    }

    reverse(s.begin(), s.end());
    int sum = 0;
    cont = 0;
    loop(i, 0, n)
    {
        if(s[i] == '('){
            ++sum;
            resp[i] = 1;
        }
        else{
            if(sum > 0){
                --sum;
                resp[i] = 1;
            }
            else{
                resp[i] = 2;
                ++cont;
            }
        }
    }
    int it = n-1;
    while(cont > 0){
        if(s[it] == '('){
            resp[it] = 2;
            --cont;
        }
        --it;
    }

    cout<<"2\n";
    loop(i, 0, n-1)
    {
        cout<<resp[i]<<" ";
    }
    cout<<resp[n-1]<<"\n";
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