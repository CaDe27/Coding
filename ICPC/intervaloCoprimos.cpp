
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
#include <bitset>
using namespace std;

typedef int64_t ll;
typedef pair<ll,int> plli;


const int maxN = 10000005;

int size_primes;
vector<ll> primes;
bitset<maxN> bit;

void generaPrimos(){
    bit.set();

    size_primes = 1;
    primes.push_back(2);

    ll i;
    for( i = 3; i <= 1e7; i+=2){
        if(bit[i]){
            primes.push_back(i);
            ++size_primes;
            if(i*i < maxN){
                for(int j = i*i; j < maxN; j+= i)
                    bit[j] = 0;
            }
        }
    }
	
}

vector<plli> squareFree;
void generaSquareFree(int i, ll acum, int paridad){
	
    if(i == size_primes){
    	if(acum <= 1e7)
        	squareFree.push_back(plli(acum , paridad));
        return;
    }
    
    //si ya me paso, no pruebo a nadie despues
    if(acum*primes[i] > 1e7){
    	squareFree.push_back(plli(acum , paridad));
    }
    else{
    	generaSquareFree(i+1, acum*primes[i], (paridad+1)%2);
    	generaSquareFree(i+1, acum, paridad);
    }
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    
    generaPrimos();
    
    generaSquareFree(0, 1, 0);
    
    ll resp = 0;
    for(plli p : squareFree){
        int f  = p.first;
        int paridad = p.second;
    	
        ll dividoA = (b/f - (a-1)/f) * (d/f - (c-1)/f);
        resp += paridad&1? -dividoA : dividoA;
    }
	
    cout<<resp<<"\n";    
}

