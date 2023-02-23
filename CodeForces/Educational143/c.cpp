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

const int maxN = 200005;
int n;

int completos[maxN];
ll sobra[maxN];
ll a[maxN], b[maxN], acumB[maxN];

int binSearch(int target, int indx){
    int ini = 0, fin = n-1, mitad;
    while(ini != fin){
        mitad = (ini+fin+1)/2;
        if(acumB[mitad] - acumB[indx-1] <= target)
        {
            ini = mitad;
        }
        else{
            fin = mitad-1;
        }
    }
    return ini;
}

void update(int a, int i){
    int maxMenor = binSearch(a, i);
    //cout<<"upd "<<a<<" "<<i<<" "<<maxMenor<<endl;
    //son completos desde i hasta maxMenor
    //si maxMenor = i-1, nadie completo y solo sobra
    if(maxMenor == i-1){
        sobra[i] += a;
    }
    else{
        completos[i] += 1;
        completos[maxMenor + 1] -= 1;
        sobra[maxMenor+1] += a - (acumB[maxMenor] - acumB[i-1]); 
    }
}

void solve(){
    cin>>n;
    ++n;
    fill(completos, completos+n+1, 0);
    fill(sobra, sobra+n+1, 0);

    loop(i, 1, n){
        cin>>a[i];
    }

    b[0] = 0;
    acumB[0] = 0;
    loop(i, 1, n){
        cin>>b[i];
        acumB[i] = b[i] + acumB[i-1];
    }

    loop(i, 1, n){
        update(a[i], i);
    }

    loop(i, 1, n){
        completos[i] += completos[i-1];
    }
    loop(i, 1, n){
        cout<<completos[i]*b[i] + sobra[i]<<(i<n-1? " " :"\n");
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