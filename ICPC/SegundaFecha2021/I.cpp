#include <bits/stdc++.h>
using namespace std;

int p(int N){
    string s = to_string(N);
    int a = 1;
    for(auto u:s){
        a *= u-'0';
    }
    return a;
}

int main()
{

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int c = 0;
        while(N != p(N)){
            N = p(N);
            c++;
        }
        cout << c << "\n";
    }

	return 0;
}
