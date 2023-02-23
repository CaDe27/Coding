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
typedef pair<int,int> pii;
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 200005;
int r, c, e; 
int mat[25][25];
char sim[25][25];

void solve(){
    loop(i, 1, r+1)
    loop(j, 1, c+1)
        cin>>sim[i][j];

    //lleno la matriz de ceros
    loop(i, 0, 25)
        fill(mat[i], mat[i]+25, 0);
    //marco lo de afuera de la matriz con -1
    //si llego a -1 ya sali
    
    fill(mat[0], mat[0] + 25, -1);
    fill(mat[r+1], mat[r+1]+25, -1);
    for(int i = 0; i <= r+1; ++i)
        mat[i][0] = mat[i][c+1]=-1;

    //inicio en 1, e
    int x = 1, y = e; 
    int cont = 0;
    while(!(mat[x][y] == -1 || mat[x][y] > 0)){
        mat[x][y] = ++cont;
        if(sim[x][y] == 'N')
            --x;
        else if(sim[x][y] == 'S')
            ++x;
        else if(sim[x][y] == 'W')
            --y;
        else
            ++y; 
    }       


    if(mat[x][y] == -1)
        cout<<cont<<" step(s) to exit\n";
    else{
        int loopSize = cont - mat[x][y] + 1;
        cout<<mat[x][y]-1<<" step(s) before a loop of "<<loopSize<<" step(s)\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>r>>c>>e;
    while(!(r == 0 && c == 0 && e == 0)){
        solve();
        cin>>r>>c>>e;
    }
    return 0;

}