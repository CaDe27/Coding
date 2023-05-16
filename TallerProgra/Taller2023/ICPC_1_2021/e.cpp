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
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 100005;
int r, c;
char mat[101][101];
int resp[101][101];
bool visited[101][101];


void dfs(int i, int j){
    if(mat[i][j] == '#' || mat[i][j] == 'X')
        return;
    if(visited[i][j])
        return;
    visited[i][j] = 1;
    
    if(i < r mat[i+1][j])
}

int er, ec;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>r>>c;
    loop(i, 0, r){
    loop(j, 0, c){
        cin>>mat[i][j];
        if(mat[i][j] == 'E')
        {
            er = i;
            ec = j;
        }
    }
    }

    dfs(er, ec);


    return 0;
}