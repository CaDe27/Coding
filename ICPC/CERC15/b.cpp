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
typedef pair<int,int> pii;

#define INF 1e13
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 500;

int n; 
pii first[maxN], second[maxN];
int indx[maxN];



vector< vector<ll> > dpAnt, dpCur, aux;
// min time I need to do s1 in first, s2 in second with quests
//from i to n-1
void DP(int s1, int s2){
    dpAnt.resize(s1+1);
    dpCur.resize(s1+1);
    loop(i, 0, s1+1){
        dpAnt[i].resize(s2+1);
        dpCur[i].resize(s2+1);
        fill(dpCur[i].begin(), dpCur[i].end(), INF);
    }
    dpCur[0][0] = 0; 
    for(int i = n-1; i>=0; --i){

        dpCur.swap(dpAnt);
        loop(j, 0, s1+1)
        loop(k, 0, s2+1){
            dpCur[j][k] = dpAnt[j][k];
            if(j > 0){
                if(first[indx[i]].first >= j){
                    dpCur[j][k] = min(dpCur[j][k], ((ll)first[indx[i]].second) + dpAnt[0][max(0, k - (first[indx[i]].first - j))]);
                }
                else{
                    dpCur[j][k] = min(dpCur[j][k], ((ll)first[indx[i]].second) + dpAnt[max(0, j - first[indx[i]].first)][k]);
                }
            }
            if(k > 0){
                dpCur[j][k] = min(dpCur[j][k], ((ll)second[indx[i]].second) + dpAnt[j][max(0, k - second[indx[i]].first)]);
            }
        }
        
    }
}


bool f(int a, int b){
    return first[a].first < first[b].first;
}

void solve(){
    int s1, s2;
    cin>>n>>s1>>s2;
    loop(i, 0, n){
        cin>>first[i].first>>first[i].second>>second[i].first>>second[i].second;
        indx[i] = i;
    }

    sort(indx, indx + n, f);
    //loop(i, 0, n)
    //    cout<<indx[i]<<" "<<first[indx[i]].first<<endl;
    DP(s1, s2);
    ll resp = dpCur[s1][s2];
    if( resp >= INF)
        resp = -1;
    cout<<resp<<"\n";
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}

