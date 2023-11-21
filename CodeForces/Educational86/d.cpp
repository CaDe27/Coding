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
const int maxN = 2e5+5;

int n, k;
int c[maxN], bucket[maxN];
vector<int> cases[maxN];

void solve(){
    cin>>n>>k;
    fill(bucket, bucket+k+1, 0);
    loop(i, 0, n) cases[i].clear();

    loop(i, 0, n){
        int x;
        cin>>x;
        bucket[x]++;
    }

    loop(i, 1, k+1) cin>>c[i];

    int totalCases = 1, size = c[k], it = 0;
    for(int i = k; i > 0; --i){
        if(i < k && c[i] > c[i+1])
            size += c[i] - c[i+1];

        while(bucket[i] > 0){
            if(cases[it].size() == size && cases[(it+1)%totalCases].size() == size){
                ++totalCases;
                it = totalCases - 1;
            }
            if(cases[it].size() == size){
                it = (it+1)%totalCases;
            }
            
            while(bucket[i] > 0 && cases[it].size() != size){
                cases[it].push_back(i);
                --bucket[i];
            }
        }
    }

    cout<<totalCases<<"\n";
    loop(i, 0, totalCases){
        cout<<cases[i].size();
        loop(j, 0, cases[i].size())
            cout<<" "<<cases[i][j];
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    solve();
    return 0;
}