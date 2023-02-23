
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

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 100005;

void swap(int a, int b){
	int aux;
	aux = a;
	a = b;
	b = aux;
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    loop(T, 0, t){
        ll a, b;
        cin>>a>>b;

        ll ini = 0, fin = (ll)(1e9), mitad;
        while(ini != fin){
            mitad = (ini + fin + 1)/2 ;
            if(a >= mitad && b >= mitad && a+b >= 3*mitad )
                ini = mitad;

            else
                fin = mitad - 1;
        }
        cout<<ini<<"\n";
    }
    
}
