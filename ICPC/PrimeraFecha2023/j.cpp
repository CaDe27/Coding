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
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define sumMod(a, b) ((a + b)%MOD)
#define productMod(a, b) ((a*b)%MOD)
#define substractMod(a,b) ((a-b)%MOD)
#define positiveMod(a)  ((a+MOD)%MOD)

const int maxN = 1e6+1;
int n;
ll query[maxN], runningSum[maxN], energy[maxN];

ll sum(int a, int b){
    if(a == 1)
        return runningSum[b];
    else
        return substractMod(runningSum[b], runningSum[a-1]);
}

ll queryRange(int a, int b){
    if(a == b)
        return energy[a];
    else if(a == 1)
        return query[b];
    else{
        return substractMod(query[b], sumMod(query[a-1], productMod(sum(a, b), sum(1, a-1))));
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int q;
    cin>>n>>q;
    loop(i, 1, n+1)
        cin>>energy[i];

    runningSum[1] = energy[1];
    loop(i, 2, n+1)
        runningSum[i] = sumMod(energy[i], runningSum[i-1]);

    //query[b] = respuesta a query del intervalo [1,b]
    query[2] = energy[1]*energy[2];
    loop(i, 3, n+1)
        query[i] = sumMod(query[i-1], productMod(energy[i], sum(1, i-1)));
    
    int a, b;
    loop(i, 0, q){
        cin>>a>>b;
        cout<<positiveMod(queryRange(a,b))<<"\n";
    }
    return 0;
}