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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n;

    //dp(1, n)
    // 
    int act[n+1], ultimoCero[n+1];

    //renglon n
    loop(i, 1, n+1){
        act[i] = 1;
    }

    //act[restantes] = dp(turno, restantes)  
    for(int turno = n-1; turno >= 1; --turno){
        ultimoCero[0] = 1;
        loop(i, 1, n+1){
            ultimoCero[i] = act[i]==0? 0 : ultimoCero[i-1] + 1;
        }

        loop(restantes, 1, n+1){
            if(restantes <= turno)
                act[restantes] = 1;
            else{
                act[restantes] = (ultimoCero[restantes-1] <= turno-1)? 1 : 0;
            }
        }  
    }


    string resp;
    if(act[n] == 1)
        resp = "Jane";
    else
        resp = "John";

    cout<<resp<<"\n";
    return 0;
}