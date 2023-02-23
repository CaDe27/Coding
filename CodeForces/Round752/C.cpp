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

#define MINF -1000000000000
#define MOD 1000000007

#define m(a,b) (a%b + b)%b
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 100005;
int n; 
int arre[maxN];

const int maxP = 31630;
vector<int> prime;
bool primo[maxP];

void sieve () {
    fill (primo, primo + maxP, true);
    primo[0] = primo[1] = false;
    for (int i = 2; i < maxP; ++i) {
        if (primo[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] < maxP; ++j) {
            primo[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}

void solve(){
    cin>>n;
    sieve();
    int size = prime.size();
    string resp = "YES";
    loop(i, 2, n+2){
        cin>>arre[i];
        bool encontre = false;
        int it = 0;
        while(it < size &&  prime[it] <= i  && !encontre){
            if(arre[i] % prime[it] != 0)
                encontre = true;
            ++it;
        }
        if(!encontre)
            resp = "NO";
    }
    cout<<resp<<"\n";
    
    
   
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
