#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

vector<int> PI;
void build_PI(int sizeP, int* P) { ///Visualizando indexado en 1
    ///PI[i] guarda el tamanio del prefijo mas grande de P que es sufijo de P[0...i]
    PI.resize(sizeP);
    PI[0]=0;
    int k=0;
    int i;
    for(i=1;i<sizeP;i++) {
        while(k>0 && P[k]!=P[i]) k=PI[k-1];
        if(P[k]==P[i]) k++;
        PI[i]=k;
    }
}

int KMP_Match(int sizeT, int sizeP, int *T , int *P) {
    build_PI(sizeP, P);
    int q=0, resp = 0;
    for(int i=0;i<sizeT;i++) {
        while(q>0 && P[q]!=T[i]) q=PI[q-1];
        if(P[q]==T[i]) q++;
        if(q==sizeP) {
            ++resp;
            q=PI[q-1];
        }
    }
    return resp;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, n;
    cin>>m>>n;
    if(m == 1){
        cout<<n<<"\n";
        return 0;
    }

    int arreM[m], arreN[n];
    for(int i = 0; i < m; ++i){
        cin>>arreM[i];
        if(i > 0){
            arreM[i-1] = arreM[i]-arreM[i-1];   
        }
    }
    for(int i = 0; i < n; ++i){
        cin>>arreN[i];
        if(i > 0){
            arreN[i-1] = arreN[i]-arreN[i-1];   
        }
    }

    cout<<KMP_Match(n-1, m-1, arreN, arreM)<<"\n";
    return 0; 

}