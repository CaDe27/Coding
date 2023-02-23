#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A,T; cin >> A >> T;

    vector<int> D[2*T+1];
    vector<int> H[2*T+1];


    for(int i=0;i<A;i++){
        int h,d,t; cin >> h >> d >> t;
        for(int j=0;j<t;j++){
            int x; cin >> x;
            D[x+d].push_back(d);
            H[x+d].push_back(h);
        }
    }

    int dp[2*T+1];

    memset(dp,0,sizeof(dp));

    for(int i=0;i <= 2*T; i++){
        for(int j=0;j<D[i].size();j++){
            dp[i] = max(dp[i-D[i][j]]+H[i][j],dp[i]);
        }
        if(i > 0) dp[i] = max(dp[i],dp[i-1]);
    }

    cout << dp[2*T] << "\n";




    return 0;
}
