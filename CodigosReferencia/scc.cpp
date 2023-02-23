//Print all strongly connected components

//Based on Kosaraju's algorithm.
//https://www.geeksforgeeks.org/strongly-connected-components/

//


/*
//why do es it work?
//  the main real question is "why does dfs[v] on transpose graph prints the scc of v?"
//  Prove by contradiction.
//      Suppose there's a vertex x in dfs[v] over transpose, 
//      (a ->b means there's a path from a to b) such that v ->x, but ~(x->v).
//      Since we are computing dfs[v] first than dfs[x], it means we first visited all the x non yet visited branch 
//      before v's in original dfs. But, since there's a path from x to v, it means v was visited first
//      (if not, since v is a son of x, v's branch would have been visited first).
//      Since there's no path from v to x, v was visited first, and it's whole branch to. That means we first visited all
//      the v non yet visited branch, a contradiction. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const int maxN = 1e6;
vector<int> adj[maxN], transpose[maxN];
bool visited[maxN];
stack<int> next;
void dfs1(int v){
    visited[v] = true;
    for(int son: adj[v])
        if(!visited[son])
            dfs1(son);
    next.push(v);
}

int repre[maxN];
int repreActual;
void dfs2(int v){
    visited[v] = true;
    repre[v] = repreActual;
    for(int son: transpose[v])
        if(!visited[son])
            dfs2(son);
}

int main(){
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //supose nodes are from 0 to v-1
    for(int i = 0; i < e; ++i){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        transpose[b].push_back(a);
    }

    stack<int> next;
    fill(visited, visited+v, false);
    for(int i = 0; i < v; ++i){
        if(!visited[i])
            dfs1(i);
    }

    fill(visited, visited+v, false);
    while(!next.empty()){
        int aux = next.top(); next.pop();
        if(!visited[aux]){
            repreActual = aux;
            dfs2(aux);
        }
    }


}