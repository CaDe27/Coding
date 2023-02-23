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
#define loop(i,a,b) for(int i = a; i < b; ++i)
typedef int64_t ll;

const int maxR = 50 + 1, maxS = 1e5+1;
int r, c, n;
string text;
char key[maxR][maxR];

struct tri{
    int x, y, l;
    tri(){x = y = l = 0;}
    tri(int xi, int yi, int ki) : x(xi), y(yi), l(ki){};
};

int rght[maxR][maxR], lft[maxR][maxR], up[maxR][maxR], down[maxR][maxR];
unordered_map<char, vector<int> >indxText;

void fillAdj(){
    int x, y;
    loop(i, 0, r){
    loop(j, 0, c){
        lft[i][j] = rght[i][j] = up[i][j] = down[i][j] = -1;
        
        //right
        y = j;
        while(y < c && key[i][j] == key[i][y]) ++y;
        if(y < c)
            rght[i][j] = y;

        //left
        y = j;
        while(y >= 0 && key[i][j] == key[i][y]) --y;
        if(y >= 0)
            lft[i][j] = y;

        //up
        x = i;
        while(x >= 0 && key[x][j] == key[i][j]) --x;
        if(x>=0)
            up[i][j] = x;

        //down
        x = i;
        while(x < r && key[x][j] == key[i][j]) ++x;
        if(x < r)
            down[i][j] = x;
    }
    }
}

bool queued[maxR][maxR][maxS];
stack<tri> adj;
ll BFS(){
    queue<pair<tri, ll> > bfs;
    bfs.push(make_pair(tri(0, 0, 0), 0));
    queued[0][0][0] = true;

    tri curr, other;
    int i, j, l;
    ll lvl;
    while(!bfs.empty()){
        curr = bfs.front().first;
        lvl = bfs.front().second;
        i = curr.x; j = curr.y; l = curr.l;

        bfs.pop();

        if(curr.l == n) return lvl;
        
        //add adjacent
        if(lft[i][j] != -1)
            adj.push(tri(i, lft[i][j], l));
        if(rght[i][j] != -1)
            adj.push(tri(i, rght[i][j], l));
        if(up[i][j] != -1)
            adj.push(tri(up[i][j], j, l));
        if(down[i][j] != -1)
            adj.push(tri(down[i][j], j, l));
        if(key[i][j] == text[l])
            adj.push(tri(i, j, l+1));
        
        while(!adj.empty()){
            other = adj.top();
            adj.pop();
            if(!queued[other.x][other.y][other.l]){
                queued[other.x][other.y][other.l] = true;
                bfs.push(make_pair(other, lvl + 1));
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>r>>c;
    loop(i, 0, r)
    loop(j, 0, c){
        cin>>key[i][j];
    }
    cin>>text;
    text += "*";
    n = text.size();

    fillAdj();

    int i = 0;
    for(char x : text){
        indxText[x].push_back(i);
        ++i;
    }

    cout<<BFS()<<"\n";
    return 0;
}