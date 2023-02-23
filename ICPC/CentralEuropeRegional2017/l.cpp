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

using namespace std;

typedef int64_t ll;
typedef long double ld;
typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 3010;
int matA[maxN][maxN], matB[maxN][maxN];
double paint[maxN][maxN][4];

int main(){
    int n; cin>>n;
    char c; 
    int x,y,l;
    loop(i,0,n){    
        cin>>c>>x>>y>>l;
        if(c == 'A'){
            matA[x - l/2 + 1500][y - l/2 +  1500] = max(matA[x - l/2 + 1500][y - l/2 +  1500], l);
        }
        else {
            matB[x +  1500][y-l/2 +  1500] = max(matB[x +  1500][y-l/2 +  1500], l/2);
        }
    }//loop


    //process buckets
    loopi(y, 0, 3005){
        loopi(x, 0, 3005){
            if(matA[x][y] > 0){
                --matA[x][y];
                loop(i,0,4) 
                    paint[x][y][i]=0.25;
                //propago
                matA[x][y+1]   = max(matA[x][y+1], matA[x][y]);
                matA[x+1][y+1] = max(matA[x+1][y+1], matA[x][y]);
                matA[x+1][y]   = max(matA[x+1][y], matA[x][y]);
            }
            if(matB[x][y] > 0){
                --matB[x][y];
                paint[x][y][0]     = paint[x][y][3] = 0.25; 
                paint[x-1][y][3]   = paint[x-1][y][2] = 0.25; 
                paint[x-1][y+1][1] = paint[x-1][y+1][2] = 0.25; 
                paint[x][y+1][0] = paint[x][y+1][1] = 0.25; 
                //propago
                matB[x-1][y+1] = max(matB[x-1][y+1], matB[x][y]);
                matB[x][y+2]   = max(matB[x][y+2], matB[x][y]);
                matB[x+1][y+1] = max(matB[x+1][y+1], matB[x][y]);
            }
        }
    }
    
    ld resp = 0;
    loopi(x, 0, 3005)
    loopi(y, 0, 3005)
    loop(i, 0, 4){
        //if(paint[x][y][i] > 0 && paint[x][y][i]!= 0.25) cout<<x<<" "<<y<<" "<<i<<endl;
        resp += paint[x][y][i];
    }
    
    //cout<<paint[1499][1500][3]<<endl;
    //cout<<paint[1499][1500][2]<<endl;
    cout<<setprecision(2)<<fixed<<resp<<"\n";
    
}