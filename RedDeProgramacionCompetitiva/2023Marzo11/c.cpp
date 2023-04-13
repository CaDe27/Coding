#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
	int n,k,d,s; cin >> n >> k >> d >> s;
	
	double p = n*d-k*s;
	p = p/(n-k);
	
	if(0 <= p && p <= 100){
		cout << fixed << setprecision(6) << p << "\n";
	}
	else{
		cout << "impossible";
	}
	
    
    return 0;
}