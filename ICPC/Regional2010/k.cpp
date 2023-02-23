#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define pli pair<long, int>
using namespace std;

const int maxW = 100002;
map<int, int> mapeo;
int k, w;
set <int> adj[2*maxW+1];
bool band;
bool visited[2*maxW+1], enRama[2*maxW+1];
int tamRama;

void dfs(int papa, int nodo){
    if(enRama[nodo] && tamRama < k)
        band = true;
    else if(!visited[nodo]){
        visited[nodo] = enRama[nodo] = true;
        ++tamRama;
        for(int h : adj[nodo]){
            if(h != papa)
                dfs(nodo, h);
            if(band)
                break;
        }
        enRama[nodo] = false;
        --tamRama;
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>k>>w;
    while(!(k==0 && w==0)){
        fill(visited, visited + 2*w+1, 0);
        fill(enRama, enRama+2*w+1, 0);
        band = false; tamRama = 0;
        mapeo.clear();
        for(int i = 0; i < 2*w+1; ++i)
            adj[i].clear();

        int next = 0;
        long a, b;
        for(int i = 0; i < w; ++i){
            cin>>a>>b;
            if(mapeo.find(a) == mapeo.end())
                mapeo.insert(pli(a, ++next));

            if(mapeo.find(b) == mapeo.end())
                mapeo.insert(pli(b, ++next));

            adj[mapeo.find(b)->second].insert(mapeo.find(a)->second);
            adj[mapeo.find(a)->second].insert(mapeo.find(b)->second);
        }
        for(int i = 1; i <= next && !band; ++i){
        	if(adj[i].size() > 2)
        		band = true;
            else if(!visited[i])
                dfs(0, i);
        }
        cout<<(band? "N":"Y")<<'\n';
        cin>>k>>w;
    }
}