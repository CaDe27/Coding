#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>

using namespace std;
typedef long long ll;

const int R = 2e7;
const int INF = 1e9;
ll dp[R]; //cheapest I can get that weight for

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T,D,M; cin >> T >> D>>M;

    vector<int> W;
    W.push_back(0);

    for(int i=0;i<M;i++){
        int w;
        cin >> w;
        W.push_back(w);
    }

    W.push_back(D);
    int k;
    k=W.size()-1;

    for(int i=0;i<k;i++){
        if(W[i+1]-W[i]>=T){
            cout<<'Y';
            return 0;
        }
    }

    cout<<'N';

    return 0;
}
