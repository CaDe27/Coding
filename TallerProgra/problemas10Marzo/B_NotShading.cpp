//note that if there is a black cell in the grid, you can make it black 
// in at most 2 operations
//  we just need to see if we can do it in 0, 1 or 2.
//  0: operations, it needs to be black already
//  1: is in the same column or row as another black cell
//  2: theres it one black cell
//  we print the first of this
#include <iostream> 
using namespace std;


char grid[55][55];
void solveTestCase(){
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    
    --r;--c;
    bool blackCell = false;
    for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
        cin>>grid[i][j];
        if(grid[i][j] == 'B')
            blackCell = true;
    }}

    int resp;
    if(!blackCell)
        resp = -1;
    else if(grid[r][c] == 'B')
        resp = 0;
    else{
        //we look in the same column and row
        //if there's not a black cell on them, the answer is two
        bool sameRowOrColumn = false;
        int i = 0; 
        while(i < n && !sameRowOrColumn){
            if(grid[i][c] == 'B')
                sameRowOrColumn = true;
            ++i;
        }
        i = 0;
        while(i < m && !sameRowOrColumn){
            if(grid[r][i] == 'B')
                sameRowOrColumn = true;
            ++i;
        }

        if(sameRowOrColumn)
            resp = 1;
        else    
            resp = 2;
    }

    cout<<resp<<"\n";
}
 
int main(){
    int testCases;
    cin>>testCases;
    for(int i = 0; i < testCases; ++i)
        solveTestCase();
    return 0; 
}