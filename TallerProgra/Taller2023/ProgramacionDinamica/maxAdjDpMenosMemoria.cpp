#include <iostream>
using namespace std;

const int maxN = 1000000;
int n;
int arreglo[maxN];

int main(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>arreglo[i];
    }
    if(n==1){
        cout<<arreglo[0]<<endl;
        return 0;
    }

    int caso_i, caso_imas1, caso_imas2;
    caso_imas2 = arreglo[n-1];
    caso_imas1 = max(arreglo[n-2], arreglo[n-1]);
    for(int i = n-3; i>= 0; --i){
        caso_i = max(arreglo[i] + caso_imas2, caso_imas1);

        caso_imas2 = caso_imas1;
        caso_imas1 = caso_i;     
    }
    cout<<caso_i<<endl;

}