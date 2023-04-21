#include<iostream>
using namespace std;

typedef int64_t ll;

const int maxN = 1000, maxM = 1000;
int n, m, mat[maxN][maxM];

bool visitado[maxN][maxM];
ll dp[maxN][maxM];

ll subProblema(int i, int j){
    if(i > n-1 || j > m-1) 
        return -1000000000000000000;
    else if(i == n-1 && j == m-1) 
        return mat[i][j];
    else{
        //solo calculalo una vez
        if(!visitado[i][j]){
            visitado[i][j] = 1;
            dp[i][j] = mat[i][j] + max(subProblema(i+1, j), subProblema(i, j+1));
        }
        return dp[i][j];
    }
}

int main(){
    clock_t ini = clock();
    cin>>n>>m;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
        cin>>mat[i][j];
    }
    
    cout<<subProblema(0, 0)<<endl;
    clock_t fin = clock();
    cout<<(fin-ini)/CLOCKS_PER_SEC<<endl;
}