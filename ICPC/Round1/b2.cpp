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
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
multiset<int> final;
int currentSum, currentElement, numElements, minElements;
int findMinElements(){
    for()

}

void solve(){
    ll p; cin>>p;
    if(p == 41){
        cout<<"1 41\n";
        return;
    }
    if(p == 1){
        cout<<"41 ";
        loop(i, 0, 41)
            cout<<"1"<<" \n"[i==40];
        return;
    }

    final.clear();
    ll suma = 0;
    for(int i = 14; i >= 0; --i){
        while(p%primes[i] == 0){
            final.insert(primes[i]);
            suma += primes[i];
            p /= primes[i];
        }
    }

    if(p != 1 || suma > 41){
        cout<<"-1\n";
        return;
    }

    minElements = 0;
    findMinElements();

    cout<<final.size()<<" ";
    int indx = 0;
    for(int v : final){
        cout<<v<<" \n"[indx++ == final.size() - 1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    loop(i, 1, t+1){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}