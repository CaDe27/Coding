#include <iostream>
#include <algorithm>

using namespace std;
typedef int64_t ll;

const int maxN = 1005;
int n;

ll v[maxN][maxN];
ll dp[maxN][maxN];
bool visited[maxN][maxN];

ll DP(int d, int pos){
    if(d + pos >= n)
        return 0;

    if(!visited[d][pos]){
        visited[d][pos] = 1;
        dp[d][pos] = max(v[d][pos] + DP(d+1, max(0, pos-1)), DP(d, pos+1));
    }

    return dp[d][pos];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    while(n != 0){
        for(int j = n-1; j >= 0; --j)
        for(int i = 0; i < n-j; ++i){
            visited[i][j] = false;
            cin>>v[i][j];
            if(i+j < n-1)
                v[i][j] += v[i][j+1]; 
        }
        cout<<DP(0, 0)<<endl;
        cin>>n;
    }
}