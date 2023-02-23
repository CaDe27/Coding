#include <iostream>
#include <algorithm>
#include <vector>

#define optimize() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
using namespace std;


int main(){
    optimize();
    int n, k;
    cin>>n>>k;
    bool tiles[n+2];
    fill(tiles, tiles+n+2, 0);
    for(int i = 0; i< k; ++i){
        int aux;
        cin>>aux;
        tiles[aux] = 1;
    }
    tiles[n+1] = 1;
    vector<int> pilas;
    int acumulado = 0, xorAcum = 0;
    for(int i = 1; i <= n+1; ++i){
        if(!tiles[i])
            ++acumulado;
        else{
            if(acumulado > 0){
                xorAcum ^= acumulado;
                pilas.push_back(acumulado);
            }
            acumulado = 0;
        }
    }
    if(xorAcum == 0)
        cout<<-1<<'\n';
    else{
        int mini = 1001;
        for(int p : pilas)
            for(int j = 1; j <= p && j < mini; ++j)
                for(int k = 1; k+j-1 <= p && j < mini; ++k)
                    if( (xorAcum^p^(k-1)^(p-(k+j-1)))==0 && j < mini)
                        mini = j;
        if(pilas.size() == 1 && mini == pilas[0])
            mini = -1;
        cout<<mini<<'\n';
    }
}