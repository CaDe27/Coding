#include <iostream>
#include <cstdint>
#include <cmath>
typedef int64_t ll;
using namespace std;
ll l, c;

//Problem B from the ICPC Mexico 2019 contest
//http://coj.uci.cu/24h/problem.xhtml?pid=4249

//sum of first k squares (1^2 + 2^2 + 3^2 + ... + k^2)
ll sumSquares(ll k){
	k*(k+1)*(2*k+1)/6;
	return k*(k+1)*(2*k+1)/6;
}

//Gauss sum (1 + 2 +3 + ... + k)
ll gaussSum(ll k){
	return k*(k+1)/2;
}

//tells you the max value of c that is in the block 
//-(k+1), ... , 0 , 1, ... L,..., L + gaussSum(k+1) 
ll f(ll k){
	return l*k + (gaussSum(k) + sumSquares(k) - 2)/2;
}

//tells you if c fits in f(k) (for binSearch over k)
bool fitsInBlock(ll k){
	return f(k) >= c;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin>>T;
	ll left, middle, right, answer;
	for(int t = 0; t<T; ++t){
		cin>>l>>c;
		//if c is in the first block
		if(c <= l)
			answer = c;
		else{
			//look for the block in which the counter is 
			left = 2; right =1000000;
			while(left != right){
				middle = (left+right)/2;
				if(fitsInBlock(middle))
					right = middle;
				else 
					left = middle +1;
			}
			//c its the c-f(left-1) element of the block
			//since the block starts in -left-1
			//c has the -left + (c-f(left-1)) index
			answer = -left + c - f(left-1);
		}
		cout<<answer<<'\n';
	}
	return 0;
}