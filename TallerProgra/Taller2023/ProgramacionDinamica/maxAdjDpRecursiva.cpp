#include <iostream>
using namespace std;

const int maxN = 1000000;
int n;
int arreglo[maxN];

int dp[maxN];
bool visited[maxN];
int mnss(int i){
    if( i > n-1)
        return 0;
    else{
        if( !visited[i] ){
            visited[i] = 1;
            //el maximo entre tomar y no tomar
            dp[i] = max(arreglo[i] + mnss(i+2), mnss(i+1));
        }
        return dp[i];
    }
}

int main(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>arreglo[i];
    }
    cout<<mnss(0)<<"\n";
        
}