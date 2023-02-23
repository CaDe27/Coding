#include <iostream>
#include <stdio.h>
#include <cstdint>
#define MOD 1000000007
typedef int64_t ll;
using namespace std;
const int maxN = 10000000; 
ll fact[maxN+1], invFact[maxN+1];
int top = 1;

//Problem F from ICPC Mexico 2019
//http://coj.uci.cu/24h/problem.xhtml?pid=4253
ll binPow(ll base, ll exp){
	ll r = 1;
	while (exp > 0){
		if( exp & 1)
			r = (r*base) % MOD;
		exp >>= 1;
		base = (base * base) % MOD;
	}
	return r;
} 

void updateFact(int t){
	if(t > top){
		for(int i = top+1; i <= t; ++i){
			fact[i] = (fact[i-1]*i)%MOD;
			invFact[i] = binPow(fact[i], MOD-2);
		}
	}
	top = t;
}

int main() {
	//read number of test cases
	fact[1] = 1;
	invFact[1] = 1;
	int T, aux, n;
	ll answer;
	scanf("%d", &T);
	char c;
	for(int t = 0; t<T; ++t){
		//read number of digits for each
		n = 0; c = ' ';
		while(scanf("%d%c", &aux, &c), c != '\n' && c!=EOF)
			++n;
		++n;
		updateFact(n-1);
		answer = 0;
		for(int i = 1; i <= n-1; ++i){
			if(i&1)
				answer = (answer + ((n-i)*invFact[i])%MOD)%MOD;
			else
				answer = (answer - ((n-i)*invFact[i])%MOD)%MOD;
		}
		if(answer < 0)
			answer += MOD;
		answer = (answer*fact[n-1])%MOD;
		cout<<answer<<'\n';
		//compute (n-1)! * Sum i=1 -> n-1 ( (-1)^n+1 * (n-i)/i! )
	}
	return 0;
}