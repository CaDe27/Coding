#include <iostream>
#include <vector>
#include<stack> 
#include <algorithm>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int n = grid.size(), m = grid[0].size();
        bool visited[n][m];
        for(int i = 0; i < n; ++i)
            fill(visited[i], visited[i] + m, 0);
        int islands = 0, curI, curJ, newI, newJ;
        vector< pair<int, int> > movs;
        movs.push_back(pair<int,int>(0, 1));
        movs.push_back(pair<int,int>(1, 0));
        movs.push_back(pair<int,int>(-1, 0));
        movs.push_back(pair<int,int>(0, -1));
        for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j] && grid[i][j] == '1'){
                ++islands;
                visited[i][j] = true;
                stack<pair<int, int> > pila;
                pila.push(pair<int, int>(i, j));
                while(!pila.empty()){
                    curI = pila.top().first;
                    curJ = pila.top().second;
                    pila.pop();
                    for(pair<int, int> u : movs){
                        newI = curI + u.first;
                        newJ = curJ + u.second;
                        if(newI < n && newI >= 0 && newJ>=0 && newJ < m && grid[newI][newJ] == '1' && !visited[newI][newJ]){
                            pila.push(pair<int, int> (newI, newJ));
                            visited[newI][newJ] = true;
                        }
                    }
                }
            }
        }}
        return islands;
    }
};

int main(){
    Solution s;
    int n, m; cin>>n>>m;
    
    vector< vector<char> >grid(n);
    for(int i = 0; i < n; ++i){
        grid[i].resize(m);
        for(int j = 0; j < m; ++j){
            cin>>grid[i][j];
        }
    }
    cout<<s.numIslands(grid)<<endl;;
    return 0;
}