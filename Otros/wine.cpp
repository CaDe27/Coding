#include<iostream>
using namespace std;
//from video: https://www.youtube.com/watch?v=pwpOC1dph6U&list=PLl0KD3g-oDOGJUdmhFk19LaPgrfmAGQfo&index=3

int main(){
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //llenar en las que falta uno
    //a partir de las de dos
    /*
        wine arreglo con indices [0 ... total - 1]
        for(int i = total-2; i >= 0; --i)
            for(int j = 0 ; j <= i; ++j)
                dp[j][i-j] = max(dp[j+1][i-j] + (i+1)*wine[j], dp[j][i-j+1] + (i+1)*wine[(total-1)-(i-j)])
    /*/
    int total;
    cin>>total;
    int wine[total];
    for(int i = 0; i < total; ++i)
        cin>>wine[i];

    int dp[total][total];
    //lleno en las que sólo falta una
    for(int i = 0; i < total; ++i)
        dp[i][total-1-i] = total*wine[i];

    //lleno las demas donde he vendido i
    //y es el maximo entre vender el de la izq y el de la derecha
    for(int i = total-2; i >= 0; --i)
        for(int j = 0 ; j <= i; ++j)
            dp[j][i-j] = max(dp[j+1][i-j] + (i+1)*wine[j], dp[j][i-j+1] + (i+1)*wine[(total-1)-(i-j)]);

    cout<<dp[0][0]<<'\n';

}