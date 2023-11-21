#include <iostream>
#include <vector>
using namespace std;

#define loop(i, a, b) for(int i = a; i < b; ++i)
char mat[55][55];
int n; 

typedef pair<int,int> pii;

int waysToWinIfMissingXIs1(){
    int countX, countO, ways = 0;;
    pii lastDot = pii(0, 0);
    bool visited[n][n];
    loop(i, 0, n)
        fill(visited[i], visited[i] + n, 0);
    loop(i, 0, n){
        countX = countO = 0;
        loop(j, 0, n){
            if(mat[i][j] == 'X') ++countX;
            else if(mat[i][j] == 'O') ++countO;
            else lastDot = pii(i, j);
        }
        if(countO == 0 && countX == n-1 && !visited[lastDot.first][lastDot.second]){
            ++ways;
            visited[lastDot.first][lastDot.second] = true;
        }
    }

    loop(j, 0, n){
        countX = countO = 0;
        loop(i, 0, n){
            if(mat[i][j] == 'X') ++countX;
            else if(mat[i][j] == 'O') ++countO;
            else lastDot = pii(i, j);
        }
        if(countO == 0 && countX == n-1 && !visited[lastDot.first][lastDot.second]){
            ++ways;
            visited[lastDot.first][lastDot.second] = true;
        }
    }

    return ways;
}

void updateMinX(int countX, int countO, int colOrRow, int &minX, int &waysToWin){
    if(countO == 0){
        int missingX = n-countX;
        if(minX == missingX){
            waysToWin += 1;
        }
        else if(missingX < minX){
            minX = missingX;
            waysToWin = 1;
        }
    }
}

void countRow(int &countX, int &countO, int i){
    loop(j, 0, n){
        if(mat[i][j] == 'X') ++countX;
        else if(mat[i][j] == 'O') ++countO;
    }
}

void countColumn(int &countX, int &countO, int j){
    loop(i, 0, n){
        if(mat[i][j] == 'X') ++countX;
        else if(mat[i][j] == 'O') ++countO;
    }
}

string solve(){
    cin>>n;
    loop(i, 0, n)
    loop(j, 0, n){
        cin>>mat[i][j];
    }

    //I check if I can win for each row and columns, 
    //and also check the number of X's missing
    int minX = 100, waysOfWin = 0;
    
    //we check for rows
    loop(i, 0,  n){
        int countX = 0, countO = 0;
        countRow(countX, countO, i);
        updateMinX(countX, countO, i, minX, waysOfWin);
    }
    // we check for columns 
    loop(j, 0, n){
        int countX = 0, countO = 0;
        countColumn(countX, countO, j);
        updateMinX(countX, countO, j, minX, waysOfWin);
    }
    if(minX == 100)
        return "Impossible";
    else if(minX == 1)
        return to_string(minX)+" "+to_string(waysToWinIfMissingXIs1());
    else
        return to_string(minX)+" "+to_string(waysOfWin);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    loop(i, 1, t+1){
        cout<<"Case #"<<i<<": "<<solve()<<"\n";
    }
    return 0;
}