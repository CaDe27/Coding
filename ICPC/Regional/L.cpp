#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>
#include <sstream>

using namespace std;

typedef int64_t ll;
typedef long double ld;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define MINF -1000000000000
#define MOD 1000000007

#define m(a,b) (a%b + b)%b
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)

const int maxN = 1005;
int n, m;


stack<pii> alturas;
int extension[maxN];
int entreFilas[maxN][maxN];
char matc[maxN][maxN];
int mat[maxN][maxN];

void leeAlturas(){
    for(int j = 0; j < m ; ++j)
    for(int i= n-1; i >= 0; --i){
        cin>>matc[i][j];
    }
    
    for(int i = 0; i < n;  ++i)
    for(int j = 0; j < m; ++j){
        if( i>0 && matc[i][j] == matc[i-1][j]){
            mat[i][j] = 1+mat[i-1][j];
        }
        else{
            mat[i][j] = 1;
        }
    }
}

void clear(){
    stack<pii> empty;
    swap(empty, alturas);
    fill(extension, extension + maxN, 0);    
}

void agrega(int h){
    int como = 0;
    while(!alturas.empty() && alturas.top().first >= h){
        como += alturas.top().second + 1;

        int tope = alturas.top().first;
        alturas.pop();
        
        //tu extension es todo lo que yo puedo comerme
        extension[tope] = max( extension[tope], como);

    }
    
    alturas.push(pii(h, como));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    cin>>m>>n;
    
    leeAlturas();
    ll area= 0, lado;
    

    for(int i = 0; i < n ; ++i){
        
        clear();
        
        //destruyendo edificios para calcular maxima extension de cada altura
        for(int j = 0; j< m; ++j)
            agrega(mat[i][j]);
        agrega(0); 
        
        //extension maxima para cada altura es la maxima entre la tuya y la de las alturas mayores
        for(int j = i; j >=1; --j){
            extension[j] = max(extension[j], extension[j+1]);
        }

        for(int j = 1; j <= i+1; ++j){
            lado = min(j, extension[j]);
            area= max(area, lado*lado);            
        }


    }

    cout<<area<<"\n";
    return 0;

}

