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
int n, m;
int arre[maxN], satisfied;
int bucket[maxN];

vector<int> factors[maxN];
void put_factors(){
    loop(i, 1, maxN){
    for(int multiple = i; multiple < maxN; multiple += i){
        factors[multiple].push_back(i);
    }
    }
}

void count_factors(int num){
    for(int v : factors[num]){
        if(v > m) continue;
        if(bucket[v] == 0){
            ++satisfied;
        }
        ++bucket[v];
    }
}

void take_factors(int num){
    for(int v : factors[num]){
        if(v > m) continue;
        if(bucket[v] == 1){
            --satisfied;
        }
        --bucket[v];
    }
}

void solve(){
    cin>>n>>m; 
    fill(bucket, bucket+m+1, 0);
    satisfied = 0;

    loop(i, 0, n) cin>>arre[i];
    sort(arre, arre+n);

    int left_p = 0, right_p = 0;
    count_factors(arre[0]);

    int resp = -1;
    while(left_p < n){
        //calculate right p
        while(satisfied != m && right_p < n - 1){
            ++right_p;
            count_factors(arre[right_p]);
        }

        //cout<<left_p<<" "<<right_p<<" "<<satisfied<<endl;
        //update answ
        if(satisfied == m){
            if(resp == -1) 
                resp = arre[right_p] - arre[left_p];
            else
                resp = min(resp, arre[right_p] - arre[left_p]);
        }
        else{
             break;
        }
        //increase left
        take_factors(arre[left_p]);
        if(left_p == right_p)
            ++right_p;
        ++left_p;
        
    }

    cout<<resp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    put_factors();
    while(t--){
        solve();
    }
    return 0;
}