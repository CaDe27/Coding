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

vector<int> factors[maxN];
void put_factors(){
    for(int i = 1; i < maxN; ++i){
    for(int m = i; m < maxN; m+=i){
        factors[m].push_back(i);
    }
    }
}

string s; 
int bucket[26], bucketEsp[26];
pair<int, char> maxis[26];
int fGanador;

int distancia(int f){
    //van n/f letras con ocurrencia f
    // quiero las n/f letras mas cercanas a la ocurrencia
    int nf = n/f;
    int matches = 0;
    loop(i, 0, nf){
        matches += min(maxis[i].first, f);
    }   
    return n - matches;
}

void armaString(){
    //se arma con ocurrencia fGanador
    //con las letras en letras
    fill(bucketEsp, bucketEsp + 26, 0);
    int nf = n/fGanador;
    loop(i, 0, nf){
        bucketEsp[maxis[i].second-'a'] = fGanador;
    }
    char c, cj;
    for(int i = 0; i < n; ++i){
        c = s[i];
        if(bucket[c-'a'] > bucketEsp[c-'a']){
            --bucket[c-'a'];
            loop(j, 0, nf){
                cj = maxis[j].second;
                if(bucket[cj-'a'] < bucketEsp[cj-'a']){
                    s[i] = cj;
                    ++bucket[cj-'a'];
                    break;
                }
            }
        }
    }
}

void solve(){
    cin>>n;
    cin>>s;
    fill(bucket, bucket + 26, 0);

    for(char c : s){
        ++bucket[c-'a'];
    }


    for(char c = 'a'; c<='z'; ++c){
        maxis[c-'a'] = make_pair(bucket[c-'a'], c);
    }
    sort(maxis, maxis+26);
    reverse(maxis, maxis+26);

    int dist = n+1, distC;
    for(int f : factors[n]){
        if(n/f > 26) continue;
        distC = distancia(f);
        if(dist > distC){
            dist = distC;
            fGanador = f;
        }
    }
    armaString();
    cout<<dist<<"\n";
    cout<<s<<"\n";

}

int main(){
    put_factors();
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}