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

    int mnss[n+2];
    mnss[n-1] = arreglo[n-1];
    mnss[n-2] = max(arreglo[n-2], arreglo[n-1]);
    for(int i = n-3; i>= 0; --i){
        mnss[i] = max(arreglo[i] + mnss[i+2], mnss[i+1]);
    }
    cout<<mnss[0]<<endl;

}