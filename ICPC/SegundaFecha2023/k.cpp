#include<iostream>
#include<algorithm>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin>>n>>k;
    int mat[n][n];
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        cin>>mat[i][j];

    int cont = 0;
    for(int i = 0; i < n-k+1; i++)
    for(int j = 0; j < n-k+1; j++){
        if(mat[i][j] == mat[i][j+k-1] &&
           mat[i][j] == mat[i+k-1][j] &&
           mat[i][j] == mat[i+k-1][j+k-1])
           ++cont;
    }
    cout<<cont<<"\n";

    return 0;
}