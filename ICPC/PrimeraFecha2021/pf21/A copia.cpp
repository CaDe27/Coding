#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int R = 2e7;
const int INF = 1e9;
ll dp[R]; //cheapest I can get that weight for

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int B,N; cin >> B >> N;

    vector<int> W,P;

    for(int i=0;i<B;i++){
        int w,p;
        cin >> w >> p;
        W.push_back(w);
        P.push_back(p);
    }

    long double A = 0;

    for(int i=0;i<N;i++){
        int x,y,z; cin >> x >> y >> z;

        vector<int> V = {x,y,z};
        sort(V.begin(),V.end());

        long double a,b,c,s;
        a = V[2];
        b = V[1];
        c = V[0];

        A += (sqrtl((a+(b+c))*(c-(a-b))*(c+(a-b))*(a+(b-c))));
    }

    int WW = ceil(A/120);

    for(int i=0;i<WW+30;i++){
        dp[i] = INF;
    }

    dp[0] = 0;

    for(int i=1;i<WW+30;i++){
        for(int j=0;j<B;j++){
            if(i-W[j] >= 0) dp[i] =  min(dp[i],dp[i-W[j]]+P[j]);
            else{
                dp[i] = min(dp[i],(ll)P[j]);
            }
        }
    }

    ll ans = (1LL<<60);
    for(int i=WW;i<WW+30;i++){
        ans = min(ans,dp[i]);
    }

    cout << ans << "\n";


    return 0;
}
