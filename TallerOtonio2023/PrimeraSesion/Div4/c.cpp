#include <iostream>
using namespace std;

char mat[8][8];
void solveTestCase(){
    for(int i = 0; i < 8; ++i)
    for(int j = 0; j < 8; ++j){
        cin>>mat[i][j];
    }

    int filaPrimero = -1, columnaPrimero = -1;
    for(int i = 0; i < 8 && filaPrimero == -1; ++i)
    for(int j = 0; j < 8 && filaPrimero == -1; ++j){
        if(mat[i][j] != '.'){
            filaPrimero = i;
            columnaPrimero = j;
        }
    }

    int itFila = filaPrimero;
    string resp = "";
    while(itFila < 8 && mat[itFila][columnaPrimero] != '.'){
        resp += mat[itFila][columnaPrimero];
        ++itFila;
    }
    cout<<resp<<"\n";

}

int main(){
    int t; cin>>t;
    while(t > 0){
        solveTestCase();
        --t;
    }
    return 0;
}