#include <iostream>
#include <map>

int mat[5][5];
int v[50];

int mapeo(int i, int j){
    return i*5 + j;
}

void imprimeV(){

}
int main(){
    //genera vector z
    int v[50];
    for(int i = 0 ; i < 25; ++i)
        v[i] = 1;
    for(int i = 25 ; i < 50; ++i)
        v[i] = 0;
    
    for(int i = 0; i < 5; ++i)
    for(int j = 0; j < 5; ++j){
        mat[i][j] = mapeo(i,j);
    }


    //genera restricciones
    for(int i = 0; i < 5; ++i)
    for(int j = 0; j < 5; ++j){
        mat[i][j] = mapeo(i,j);
    }
}