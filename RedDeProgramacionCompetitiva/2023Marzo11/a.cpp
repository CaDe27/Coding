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
#define loop(i,a,b) for(int i = a; i < b; ++i)

ll en[101];
bool f(int i, int j){
    if(en[i]*j == en[j]*i) 
        return i < j;
    else
        return en[i]*j < en[j]*i;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    int n, q;
    cin>>n>>q;
    loop(i, 1, n+1)
        cin>>en[i];

    //precalcula los minimos de n+1 a 2n
    ll minSuf[n+1];
    fill(minSuf, minSuf + n+1, 2e9);
    loop(i, 1, n+1){
        //calculamos para n+i
        loop(j, i, n+1)
            minSuf[i] = min(minSuf[i], en[j] + en[n+i-j]);
    }

    // el mejor relacion precio
    int mins[n];
    loop(i, 0, n)
        mins[i] = i+1;
    sort(mins, mins+n, f);

    //calculamos el minimo para
    int s = n*n*(n+1)/2 ;
    ll f[s + 1];
    f[1] = en[1];
    for(int i = 2; i <= s; ++i){
        f[i] = i<=n? en[i] : f[i-1] + en[1];
        for(int j = 1; j < min(i,n+1); ++j)
            f[i] = min(f[i], f[i-j] + en[j]);
    }  
 
    ll k, resp, X, mod; 
    int mini = mins[0];
    ll mods = s % mini;

    for(int Q = 0; Q < q; ++Q){
        cin>>k;
        if(k <= n)
            cout<<en[k]<<"\n";
        else{
            resp = 1e18;
            for(int i = n+1; i <= 2*n ; ++i){
                if(k < i) break;
                if(k - i < s)
                    resp = min(resp, minSuf[i-n] + f[k-i]);
                else{
                    mod = (s - k + i) % mini;
                    //dejamos el mod positivo
                    mod = (mod + mini) % mini;
                    X = s - mod;
                    resp = min(resp, minSuf[i - n] + f[X] + ((k - i - X)/mini * en[mini]));
                }
            }
            cout<<resp<<"\n";
        }   
    }
    return 0;
}