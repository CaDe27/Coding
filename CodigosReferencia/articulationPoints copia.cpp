#include<iostream>
#include <vector>
#include <algorithm>

#define optimize() ios_base::sync_with_stdio(0); cin.tie(0);
#define readMyCase() if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin)
#define loop(i, a, b) for(int i = a; i < b; ++i)
#define endl '\n'
#define vi vector<int>

using namespace std;

const int maxN = 10000;
int n, m;

vi adj[maxN+1];
int discovered[maxN+1], ancestor[maxN+1];
int articulationPoints, nextIndx, root;

void cleanStuff(){
    loop(i, 1, n+1)
        adj[i].clear();
    fill(discovered, discovered+n+1, 0);
    fill(ancestor, ancestor+n+1, 0);
    articulationPoints = 0;
    nextIndx = 0;
    root = 1;
}

void dfs(int f, int nd){
    ancestor[nd] = nd;
    discovered[nd] = ++nextIndx;
    bool ap = false;
    int sccChildren = 0;
    for(int son : adj[nd]){
        if(son != f){
            if(discovered[son] == 0){
                ++sccChildren;
                dfs(nd, son);
                //if you couldn't connect with me or someone older than me, I'm an ap
                // and our bridge is an articulation point
                if(discovered[ancestor[son]] > discovered[nd]){
                    ap = true;
                    cout<<nd<<" "<<son<<" is an art bridge\n";
                }
                else if(ancestor[son] == nd)
                    ap = true;
                //your first-discovered ancestor might be my f-d ancestor as well
                if(discovered[ancestor[son]] < discovered[ancestor[nd]])
                    ancestor[nd] = ancestor[son];
            }
            //if you were already discovered and were discovered first than my f-d ancestor, then you just
            //became my f-d ancestor
            else if(discovered[son] < discovered[ancestor[nd]])
                ancestor[nd] = son;
        }
    }
    //if you are the root, only thing that matters is that at least two of your
    //children are not connected
    if(nd == root)
        ap = sccChildren>1;
    
    if(ap)
        ++articulationPoints;
}


int main(){
    optimize();
    readMyCase();
    
    cin>>n>>m;
    while(!(n == 0 && m == 0)){
        cleanStuff();
        loop(i, 0, m){
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //we can transverse all graph through 1 because we know it's all connected
        dfs(1, 1);
        cout<<articulationPoints<<endl;
        cin>>n>>m;
    }
}