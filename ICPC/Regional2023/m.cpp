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

#define INF 1000000000000

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)
#define mod(a, b) (a + 3*b)%b
const int maxR = 1005, maxC = 105;
int R, C;
vector<int> tics;
string rows[maxR];

bool DFS[maxR][maxC];
bool visited[maxR][maxC];

bool puedoIzq(int r, int c){
    int offset = c - tics[0];
    for(int v : tics){
        if(rows[r][ mod(v + offset - 1, C) ] == '1')
            return false;
    }
    return true;
}

bool puedoDer(int r, int c){
    int offset = c - tics[0];
    for(int v : tics){
        if(rows[r][ mod(v + offset + 1, C) ] == '1')
            return false;
    }
    return true; 
}

bool puedoAbajo(int r, int c){
    int offset = c - tics[0];
    for(int v : tics){
        if(rows[r+1][ mod(v + offset, C) ] == '1')
            return false;
    }
    return true;
}

bool puedoArriba(int r, int c){
    if(r == 0)
        return false;

    int offset = c - tics[0];
    for(int v : tics){
        if(rows[r-1][ mod(v + offset, C) ] == '1')
            return false;
    }
    return true;
}

bool dfs(int r, int c){
    if(!visited[r][c]){
        visited[r][c] = true;
        DFS[r][c] = false;
        //muevo abajo
        if(!visited[r+1][c] && puedoAbajo(r, c)){
            if(r == R-2)
                return true;
            DFS[r][c] = dfs(r+1, c);
        }
        
        //muevo der
        if(!DFS[r][c] && !visited[r][ (c+1) % C ] && puedoDer(r, c)){
            DFS[r][c] = dfs(r, (c+1)%C );
        }

        //muevo izq
        if(!DFS[r][c] &&  !visited[r][ (c + C - 1) % C ] && puedoIzq(r, c)){
            DFS[r][c] = dfs(r, (c + C - 1)%C );
        }

        //muevo arriba
        if(!DFS[r][c] && r > 0 && !visited[r-1][c] && puedoArriba(r, c)){
            DFS[r][c] = dfs(r-1, c);
        }
        
    }
    return DFS[r][c];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>R>>C;
    ++R;

    string aux;
    cin>>aux;
    loop(i, 0, aux.size()){
        if(aux[i] == '1')
            tics.push_back(i);
    }
    if(tics.size() == 0){
        cout<<"Y\n";
        return 0;
    }
        

    rows[0] = string(C, '0');
    loop(i, 1, R)
        cin>>rows[i];

    if(dfs(0, 0)){
        cout<<"Y\n";
        return 0;
    }

    loop(i, 0, tics.size()){
        tics[i] = C - 1 - tics[i];
    }
    

    reverse(tics.begin(), tics.end());

    loop(i, 0, R){
        fill(visited[i], visited[i] + C, 0);
    }

    if(dfs(0, 0)){
        cout<<"Y\n";
        return 0;
    }

    cout<<"N\n";
    
    return 0;
}