#include <iostream>
using namespace std;

int mat[1002][1002];
int n,m;

void vertical(){
    int mid = n/2 + 1;
    for(int i = 0; i < mid; ++i){
        for(int j = 0; j <m; ++j)
            swap(mat[i][j], mat[n-i-1][j]);
    }
}

void horizontal(){
    int mid = m/2 + 1;
        for(int j = 0; j < mid; ++j){
            for(int i = 0; i < n; ++i)
                swap(mat[i][j], mat[i][m-j-1]);
        }
}

int main(){
    cin>>n>>m;
    
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
        cin>>mat[i][j];

    int k, v, h;
    cin>>k;
    
    v = 0; 
    h = 0;

    for(int i = 0; i < k; ++i){
        char c;
        cin>>c;
        if(c =='V')
            ++v;
        else
            ++h;
    }

    if(v%2 == 1)
        vertical();
    if(h%2 == 1)
        horizontal();
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)
            cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}