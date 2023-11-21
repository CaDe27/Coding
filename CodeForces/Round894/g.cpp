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
const int maxN = 200005;
int n; 
multiset<int> dif;
multiset<int> a;
int ori[maxN];

void agrega(int ai){
    if(a.size() == 0){
        a.insert(ai);
        return;
    }

    multiset<int> :: iterator it = a.lower_bound(ai);
    if(it == a.end()){
        dif.insert(ai - *(--it));
    }
    else if(it == a.begin()){
        dif.insert(*it - ai);
    }
    else{
        dif.erase(dif.find(*it - *(--it)));
        ++it;
        dif.insert(*it - ai);
        dif.insert(ai - *(--it));
    }
    a.insert(ai);
}

//asuming it is inside the set
void quita(int ai){ 
    if(a.size() == 1){
        a.clear();
    }

    multiset<int> :: iterator it = a.lower_bound(ai);
    if(it == a.begin()){
        dif.erase(dif.find( *(++it) - ai));
    }
    else if(++it == a.end()){
        --it;
        --it;
        dif.erase(dif.find(ai - *it));
    }
    else{
        int sig = *it;
        --it;--it;
        int before = *it;
        dif.erase(dif.find(sig - ai));
        dif.erase(dif.find(ai - before));
        dif.insert(sig - before);
    }
    a.erase(a.find(ai));
}

void solve(){
    cin>>n;
    a.clear();
    dif.clear();

    loop(i, 0, n){
        cin>>ori[i];
        a.insert(ori[i]);
    }
    for(multiset<int>::iterator it = a.begin(); ++it != a.end(); ++it){
        dif.insert(*it - *(--it));
    }
    
    int q; cin>>q;
    loop(i, 0, q){
        int indx, num;
        cin>>indx>>num;
        if(n == 1){
            cout<<num<<" \n"[i==q-1];
        }
        else{
            --indx;
            quita(ori[indx]);
            ori[indx] = num;
            agrega(ori[indx]);

            cout<< (*(--a.end()))+(*(--dif.end()))<<" \n"[i==q-1];
        }
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