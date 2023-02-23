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
    int n, a, b, impresos, numberIt;
    cin>>n>>a>>b;
    if( (a<b && n-1-(a-1) >= n/2 && b-1 >= n/2) 
        ||
        (a>b && n - (a-1) >= n/2 && b >= n/2)
        )
    {
        cout<<a<<" ";
        numberIt = n;
        impresos = 1;
        while(impresos < n/2){
            if(numberIt != a && numberIt != b){
                cout<<numberIt<<" ";
                ++impresos;
            }
            --numberIt;
        }

        cout<<b<<" ";
        impresos = 1;
        numberIt = 1;
        while(impresos < n/2){
            if(numberIt != a && numberIt != b){
                cout<<numberIt<<" ";
                ++impresos;
            }
            ++numberIt;
        }
        cout<<"\n";
    }
    else{
        cout<<"-1\n";
    }
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
