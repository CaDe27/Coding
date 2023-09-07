#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std ;
#define int long long
#define endl '\n'
#define all(a) a.begin() , a.end()
#define alr(a) a.rbegin() , a.rend()
const int mod = 1e9 + 7;
class HashedString {
  private:
	static const long long M = 1e9 + 9;
	static const long long B = 9973;
	static vector<long long> pow;
	vector<long long> p_hash;
  public:
	void init(string &s) {
        p_hash = vector < int > (s.size() + 2);
		while (pow.size() < s.size()) { pow.push_back((pow.back() * B) % M); }
		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
		}
	}
    int HASH(string s) {
        while (pow.size() < s.size()) { pow.push_back((pow.back() * B) % M); }
		int val = 0;
		for (int i = 0; i < s.size(); i++) {
			val = ((val * B) % M + s[i]) % M;
		}
        return val;
    }
	long long getHash(int start, int end) {
		long long raw_val =
		    (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
		return (raw_val % M + M) % M;
	}
};
vector<long long> HashedString::pow = {1};
int Add(int a, int b) {
    a += b; if (a >= mod) a -= mod; 
    return a;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    map < int , int > mp;
    vector < vector < pair < int , int >>> vec(30);
    for(int i = 0 ; i < n ; i ++) {
        string x;
        cin >> x;
        HashedString h;
        vec[x[0] - 'a'].push_back({h.HASH(x), x.size()});
    }
    string x; cin >> x;
    int m = x.size();
    HashedString hash; hash.init(x);
    int dp[m + 10] = {}; dp[m] = 1;
    for(int i = m - 1 ; i >= 0 ; i--) {
        for(auto [hsh, len] : vec[x[i] - 'a']) {
            if(i + len - 1 < m) {
                int val = hash.getHash(i, i + len - 1);
                if(val == hsh) {
                    dp[i] = Add(dp[i], dp[i + len]);
                }
            }
        }
    }
    cout << dp[0] << endl;
    return 0 ;
}