//  BoxDelivery 
//  http://coj.uci.cu/24h/problem.xhtml?pid=4238
//

#include <iostream>
#include <string>
#include <stdio.h>
#define MOD 986444689
using namespace std;
long fact[2*100000+5];
int top = 0;

void updateFact(int t){
	if(t > top){
		for(int i = top+1; i <= t; ++i)
			fact[i] = (fact[i-1]*i)%MOD;
	}
	top = t;
}

long binPow(long base, long exp){
	long long r = 1;
	while (exp > 0){
		if( exp & 1)
			r = (r*base) % MOD;
		exp >>= 1;
		base = (base * base) % MOD;
	}
	return r;
} 

long combMod(long n, long k){
    return ((fact[n]*binPow(fact[k],MOD-2))%MOD * binPow(fact[n-k], MOD-2))%MOD;
}

int sumBossSup(int n){
	int days[n+1];
	fill(days, days+n+1, 0);
    int sum = 0, aux;
    char c;
	do{
		scanf("%d%c", &aux, &c);
		++days[aux];
		++sum;
	}while(c != '\n');
	
    do{
		scanf("%d%c", &aux, &c);
		sum += days[aux]? 1:2;
	}while(c != '\n');
    return sum;
}

int sumBossSup2(int n){
	int days[n+1];
	fill(days, days+n+1, 0);
    int sum = 0, aux;
    char c;
	do{
		scanf("%d%c", &aux, &c);
		++days[aux];
		++sum;
	}while(c != '\n');
	int a = scanf("%d%c", &aux, &c);
    do{
		sum += days[aux]? 1:2;
		a = scanf("%d%c", &aux, &c);
    }while(a == 2);
    return sum;
}


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fact[0] = 1;
    int t; //test cases
    scanf("%d", &t);
    int n, k;
    for(int i = 0; i < t; ++i){
        scanf("%d %d", &n, &k);
        /*
         because there's still an end of line and using getline
         without this in sumIntLine would make input = ""
        */
        if(i == t-1)
        	k-= sumBossSup2(n);
    	else
        	k -= sumBossSup(n);
        if(k < 0)
        	cout<<0<<'\n';
        else{
	        updateFact(k+n-1);
	        cout<<combMod(k+n-1, n-1)<<'\n';
        }
    }
    return 0;
}

