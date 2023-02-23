#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N,K,T; cin >> N >> K >> T;

    ll a[N+1];

    ll total = 0;

    for(int i=1;i<=N;i++){
        cin >> a[i];
        total += a[i];
    }

    ll cost = N*a[N]- total;

    ll save = 0;
    pair<int,int> ans = {-1,-1};

    int cur = 1;

    for(int i=1;i<=N;i++){
        cur = max(i,cur);
        while(cur+1 <= N && abs(a[cur+1]-a[i]) <= K){ //cur <= N, distancia cool
            cur++;
        }

        if((a[cur]-a[i]-T)*i > save && abs(a[cur]-a[i]) <= K && cur > i){
            ans = {i,cur};
            save = (a[cur]-a[i]-T)*i;
        }
    }

    if(ans.first == -1){
        cout << "-1\n";
    }
    else{
        cout << ans.first << " " << ans.second << " " << cost - save << "\n";
    }






    return 0;
}
