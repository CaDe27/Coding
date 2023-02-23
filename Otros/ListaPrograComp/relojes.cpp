#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > movimientos;
   
int minMovs = 4e9 + 1;
vector<int> optimo;

vector<int> inicial(9);
vector<int> actual(9);
vector<int> prueba(9);
void check(){
    prueba = inicial;

    for(int i = 0; i < 9; ++i){
        //aplica el i-esimo mov lo que diga en actual
        for(int j = 0; j<9; ++j)
            prueba[j] = (prueba[j] + movimientos[i][j]*actual[i])%4;
    }

    int suma = 0;
    for(int i = 0; i < 9; ++i){
        if(prueba[i] != 0)
            return;
        suma += actual[i];
    }
    if(suma < minMovs){
        minMovs = suma;
        optimo = actual;
    }
}

void recursion(int movID){
    for(int i = 0; i < 4; ++i){
        actual[movID] = i;
        check();
        if(movID < 8)
            recursion(movID+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int mov[][9] = {{1,1,0,1,1,0,0,0,0},
                    {1,1,1,0,0,0,0,0,0}, 
                    {0,1,1,0,1,1,0,0,0},
                    {1,0,0,1,0,0,1,0,0},
                    {0,1,0,1,1,1,0,1,0},
                    {0,0,1,0,0,1,0,0,1},
                    {0,0,0,1,1,0,1,1,0},
                    {0,0,0,0,0,0,1,1,1}, 
                    {0,0,0,0,1,1,0,1,1},
                    };
    for(int i=0; i < 9; ++i)
        movimientos.push_back( vector<int>(mov[i], mov[i]+9));
    fill(actual.begin(), actual.end(), 0);
    
    for(int i=0; i < 9; ++i){
        cin>>inicial[i];
        inicial[i] = (inicial[i]/3)%4;
    }
    recursion(0);
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < optimo[i]; ++j)
            cout<<(i+1)<<" ";
    }
    cout<<"\n";


}