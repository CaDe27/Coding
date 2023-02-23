#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(ll k){
    if(k == 1){
        return "2";
    }
    if(k%2 == 0){
        return "("+solve(k/2)+")^2";
    }
    else{
        return "(2*"+solve(k-1)+")";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;

    while(T--){
        ll k; cin >> k;
        cout << solve(k) << "\n";
    }

    return 0;
}
