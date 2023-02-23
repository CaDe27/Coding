//
// key idea is to answe each query trying to find a cycle
//      through firstColumn->firstColumn transitions only

// to update we obtain which range in first column do I change 
// and its new firstColumn destination
// *we update those cells that now choose me, and those that stop
//  choosing me

// if you have a super quick query, and a slow update
//  try to hit a middle point

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

using namespace std;
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define MOD(a,b) (a%b + b)%b

const int maxR = 2005, maxC = 2005;
int r, c;
int mat[maxR][maxC];

struct pos{
    int row, col;
    pos(int i, int j){row = i; col = j;}
    pos(){row = 0; col = 0;}
};

pos current;

bool operator > (const pos &a, const pos &b){
    return mat[a.row][a.col] > mat[b.row][b.col];
}

bool operator < (const pos &a, const pos &b){
    return mat[a.row][a.col] < mat[b.row][b.col];
}

pos move(pos p){
    int nextCol = MOD(p.col+1, c);
    pos next =       pos(  MOD(p.row-1, r), nextCol );
    next = max(next, pos(  MOD(p.row  , r), nextCol));
    next = max(next, pos(  MOD(p.row+1, r), nextCol));
    return next;
}

//nextRow[i] stores the next row position (i,0) arrives when taking c steps
int nextRow[maxR];
void precalculo(){
    loop(i, 0, r){
        pos aux = pos(i, 0);
        loop(j, 0, c)
            aux = move(aux);
        nextRow[i] = aux.row;
    }
}

// =================== Para la query
struct cycleInfo{
    int stepsToCycle, cycleLength, startingRow;
    cycleInfo(int a, int b, int c){stepsToCycle = a; cycleLength = b; startingRow = c;}
};

//we return the info about the first cycle we encounter starting from position
// (row, 0) 
cycleInfo findCycle(int row){
    int visited[maxR];
    fill(visited, visited + maxR, -1);

    int indxVisited = 0;
    visited[row] = indxVisited;
    while(visited[ nextRow[row] ] == -1){
        row = nextRow[row];
        visited[row] = ++indxVisited;
    }
    row = nextRow[row];
    
    //<stepsToCycle, cycleLength, startintRow>
    return cycleInfo(visited[row]*c, (indxVisited+1 - visited[row])*c, row);
}

void query(int steps){
    //me muevo a la primera columna
    while(steps>0 && current.col != 0){
        current = move(current);
        --steps;
    }

    if(steps == 0) return;

    //we detect cycle
    cycleInfo ci = findCycle(current.row);    
    if(ci.stepsToCycle <= steps){
        current = pos(ci.startingRow, 0);
        steps -= ci.stepsToCycle;
        steps %= ci.cycleLength;
    }

    while(steps >= c){
        current = pos(nextRow[current.row], 0);
        steps-=c;
    }

    while(steps){
        current = move(current);
        --steps;
    }
}


void update(pos p, int newVal){
    p.col = MOD(p.col, c);
    p.row = MOD(p.row, r);
    if(newVal > 0)
        mat[p.row][p.col] = newVal;

    //we obtain the range we have to update
    //t for top, b for bottom, col for column
    int t, b, col;
    col = p.col;
    t = b = p.row;

    do{
        int newT = t, newB = b;
        //we update bottom of the range
            int mayores2 = max(mat[MOD(b-1,r)][col], mat[MOD(b-2, r)][col]);
            if( mat[MOD(b,r)][col] > mayores2) --newB;
            else{
                int mis2 =  b==t? mat[MOD(b,r)][col] : max(mat[MOD(b,r)][col], mat[MOD(b+1,r)][col]);
                if(mis2 < mat[MOD(b-1, r)][col]) ++newB;
            }
        //We update top of the range
            mayores2 = max(mat[MOD(t+1,r)][col], mat[MOD(t+2, r)][col]);
            if( mat[MOD(t,r)][col] > mayores2) ++newT;
            else{
                int mis2 =  b==t? mat[MOD(t,r)][col] : max(mat[MOD(t,r)][col], mat[MOD(t-1,r)][col]);
                if(mis2 < mat[MOD(t+1, r)][col]) --newT;
            }
        col = MOD(col-1, c);

        if(newT < newB)
            return;
        
        t = newT; b = newB;

    }while(col != 0);

    //we obtain the new row in column 1 to which the range is going to arrive
    while(p.col != 0)
        p = move(p);   
    
    //we update the range
    if(t-b >= r-1){b = 0; t = r-1;}
    loopi(i, b, t)
        nextRow[MOD(i, r)] = p.row;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    current = pos(0,0);

    cin>>r>>c;    
    loop(i, 0, r)
    loop(j, 0, c)
        cin>>mat[i][j];
    

    precalculo();

    int m; cin>>m;
    loop(i, 0, m){
        string event;
        cin>>event;
        if(event == "move"){
            int steps; cin>>steps;
            query(steps);
            cout<<current.row+1<<" "<<current.col+1<<"\n";
        }
        else{
            int row, col, newVal;
            cin>>row>>col>>newVal;
            --row; --col;
            update( pos(row, col), newVal);
            update( pos(row+1, col), -1);
            update( pos(row-1, col), -1);
            update( pos(row-2, col), -1);
            update( pos(row+2, col), -1);

        }
    }


    
    return 0;
    
}
