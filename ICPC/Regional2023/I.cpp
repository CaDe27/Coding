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
#include <unordered_map>

using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxR = 101;
int r, c;
int mat[maxR][maxR];

unordered_map<int, pii> coord;

priority_queue<int, vector<int>, greater<int> > minHeap;
int desde(int i, int j){
    int totComidos = 0;
    int ultimoComi = 0;

    while(!minHeap.empty())
        minHeap.pop();

    minHeap.push(mat[i][j]);
    int x, y;
    while(!minHeap.empty()){
        if(minHeap.top() > ultimoComi){
            ++totComidos;
            ultimoComi = minHeap.top();
            minHeap.pop();

            x = coord[ultimoComi].first;
            y = coord[ultimoComi].second;

            if(x > 0 && mat[x-1][y] > ultimoComi)
                minHeap.push(mat[x-1][y]);
            if(x < r-1 && mat[x+1][y] > ultimoComi)
                minHeap.push(mat[x+1][y]);
            if(y > 0 && mat[x][y-1] > ultimoComi)
                minHeap.push(mat[x][y-1]);
            if(y < c-1 && mat[x][y+1] > ultimoComi)
                minHeap.push(mat[x][y+1]);
        }
        else
            minHeap.pop();
    }   
    return totComidos;
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>r>>c;
    loop(i, 0, r)
    loop(j, 0, c){
        cin>>mat[i][j];
        coord[mat[i][j]] = pii(i, j);
    }

    int resp = 0;
    loop(i, 0, r)
    loop(j, 0, c){
        if(i > 0 && mat[i][j] > mat[i-1][j]) continue;
        if(i < r-1 && mat[i][j] > mat[i+1][j]) continue;
        if(j > 0 && mat[i][j] > mat[i][j-1]) continue;
        if(j < c-1 && mat[i][j] > mat[i][j+1]) continue;
        resp = max(resp, desde(i, j));
    }
    
    cout<<resp<<"\n";
    return 0;
}