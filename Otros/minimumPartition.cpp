#include <stdio.h>
#include <iostream>
#include <algorithm>
#define optimize() ios_base::sync_with_stdio(0);
#define readMyCase() if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin)
using namespace std;

const int maxN = 50;
int n, totalSum;
int dp[maxN*maxN+1][maxN+1], visited[maxN*maxN+1][maxN+1], numbers[maxN];

void cleanDP(){
    for(int i = 0; i < 50*n; ++i)
        fill(visited[i], visited[i]+n, 0);
}

int DP(int sum, int indx){
    if(indx == n)
        return totalSum - 2*sum;
    else if(!visited[sum][indx]){
        visited[sum][indx] = 1;
        int total1 = 2500, total2 = 2500;
        //lo tomo
        if(DP(sum+numbers[indx], indx+1) >= 0)
            total1 = DP(sum+numbers[indx],indx+1);
        //no lo tomo
        if(DP(sum, indx+1) >= 0)
            total2 = DP(sum, indx+1);
        dp[sum][indx] = min(total1, total2);
    }
    return dp[sum][indx];
}

int main() {
    optimize();
    readMyCase();
	int test; cin>>test;
	for(int t = 0; t < test; ++t){
	   cin>>n;
       totalSum = 0;
	   for(int i = 0; i < n; ++i){
	        cin>>numbers[i];
            totalSum += numbers[i];
       }
	   cleanDP();
	   cout<<DP(0,0)<<endl;
	}
	return 0;
}