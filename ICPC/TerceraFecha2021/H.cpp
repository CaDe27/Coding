#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k; cin >> n >> k;
    
    pair<int,int> V[n];
    
    vector<int> P[n+1];
    for(int i=0;i<n;i++){
        cin >> V[i].first >> V[i].second;
        P[V[i].second].push_back(i);
    }
    
    sort(V,V+n);
    
    vector<int> Q[n+1];
    
    for(int i=0;i<n;i++){
        Q[V[i].second].push_back(i);
    }
    
    bool works = true;
    
    for(int i=0;i<=n;i++){
        sort(P[i].begin(),P[i].end());
        sort(Q[i].begin(),Q[i].end());
        if(P[i] != Q[i]) works = false;
    }
    
    cout << (works ? "Y\n" : "N\n");
    
 
 
    return 0;
}
