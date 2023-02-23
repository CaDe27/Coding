#include <iostream>

//podemos colorear todo el tablero 
// como en ajedrez si todas las casillas son buneas
// si alguna es mala, ponemos '-' pero las casillas adyacentes buenas
//siguen siendo de color distinto

using namespace std;

int main(){
    
    int n, m;
    cin>>n>>m;

    char c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
        {
            cin>>c;
            if(c == '.'){
                if( (i+j)%2 == 0)
                    cout<<"B";
                else
                    cout<<"W";   
            }
            else{
                cout<<"-";
            }
        }
        cout<<"\n";
    }

    return 0;
}