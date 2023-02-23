#include <iostream>
#define loop(i,a,b) for (int i =a; i < b; ++i)
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int maxs = 100005;
    int izq[maxs], der[maxs];
    int b,s;
    cin>>s>>b;
    while( !(b==0 and s == 0)){
        loop(i,1, s+1){
            izq[i] = i-1;
            der[i] = i+1;
        }
        izq[1] = -1;
        der[s] = -1;

        int si,sd;
        loop(i, 0, b){
            cin>>si>>sd;
            if(izq[si] == -1)
                cout<<"* ";
            else {
                cout<<izq[si]<<" ";
                der[izq[si]] = der[sd];
            }
   
            if(der[sd]== -1)
                cout<<"*\n";
            else {
                cout<<der[sd]<<"\n";
                izq[der[sd]] = izq[si];
            }
                
        }
        cout<<"-\n";
        cin>>s>>b;
    }

}