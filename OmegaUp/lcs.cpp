#include <iostream>
#include <string>
#include <algorithm>

#define loop(i, a, b) for(int i = a; i < b; ++i)
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);
#define readMyCase() if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin)

using namespace std;
const int maxN = 1000;
int sw1, sw2; 
int dp[maxN][maxN];
string w1, w2;

void limpiaMatrizDP(){
    loop(i, 0, sw1)
        fill(dp[i], dp[i]+sw2, -1);
}

int DP(int pt1, int pt2){
    if(pt1 == sw1 || pt2 == sw2)
        return 0;
    else if(dp[pt1][pt2] == -1){
        if(w1.at(pt1) == w2.at(pt2))
            dp[pt1][pt2] = 1+DP(1+pt1, 1+pt2);
        else{
            dp[pt1][pt2] = max(DP(1+pt1, pt2), DP(pt1, 1+pt2));
        }
    }
    return dp[pt1][pt2];
}

int main(){
    optimize();
    readMyCase();
    cin>>w1>>w2;
    sw1 = w1.size(); sw2 = w2.size();
    limpiaMatrizDP();
    cout<<DP(0, 0)<<endl;

}

