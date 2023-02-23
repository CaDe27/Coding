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

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)


// calcula la suma ini + (ini + d) + (ini + 2d) + ... + (ini + (m-1)d) 
ll sumaAritmetica(ll ini, ll m, ll d){
    ini%=MOD;
    d%=MOD;
    if (m%2 == 0)
        return  ( m/2%MOD * ( 2*ini%MOD  + (m-1)*d%MOD )%MOD )%MOD;
    else
        return ( m%MOD * ( ini%MOD + ( ((m-1)/2 *d)%MOD )%MOD))%MOD;
}

ll sumOfR(ll n, ll m){

    ll resp, ini;
    if(m >= n){
        resp = ((m-n)%MOD)*(n%MOD);
        ini = 1;
    }
    else {
        ini = n/m;
        resp = (MOD - sumaAritmetica( n % (n/ini), n/ini - m, ini))%MOD;
        //cout<<sumaAritmetica( n % (n/ini), n/ini - m, ini)<<endl;
        //cout<<resp<<endl;
    }

    ll i;
    long double sqr  = sqrt(n);
    for(i = ini; i <= sqr ; ++i){
        //cout<<i<<" de "<<(n/i)<<" a "<<(n/(i+1))<<" con "<<(n % (n/i))<<" "<<(n/i - n/(i+1))<<" ";
        //cout<<sumaAritmetica(n % (n/i), n/i - n/(i+1), i)<<endl;
        resp = (resp + sumaAritmetica(n % (n/i), n/i - n/(i+1), i)) %MOD; 
    }
    for(i = n/(i); i >= 2; --i)
        resp = (resp + n%i)%MOD;
    
    return resp;

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m;
    cin>>n>>m;
    cout<<sumOfR(n,m)<<'\n';

}
