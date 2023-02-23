#include <iostream>
#include <algorithm>
#include <vector>

#define loop(i, a, b) for(int i = a; i < b; ++i)
#define inverseLoop(i, a, b) for(int i = a; i > b; --i)
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);


using namespace std;
typedef int64_t ll;
const int maxN = 200005, LogN = 20;
int k, n, central;
vector<int> adj[maxN+1], terminales;
int table[LogN+1][maxN+1];

struct node{
	int level; 
    int marca;
}nodes[maxN+1];



//=================== LCA
void assignParents(int nd, int fa = 0){
    int maxMarca = 0;
    for(int son: adj[nd]){
        if(son != fa){
            nodes[son].level = 1 + nodes[nd].level;
            table[0][son] = nd;
            assignParents(son, nd);
            nodes[nd].marca += nodes[son].marca;
            if(nodes[son].marca > maxMarca)
                maxMarca = nodes[son].marca;
        }
    }
    //la marca de mi papa
    if(k - nodes[nd].marca > maxMarca)
        maxMarca = k - nodes[nd].marca;

    if(maxMarca <= k/2)
        central = nd;

}

//creates LCA Binary Lifting table
void createLCATable(){
    int mid;
	for(int k = 1; k<=LogN; ++k){
		for(int nd = 1; nd <= n; ++nd){
           mid = table[k-1][nd];
           table[k][nd] = table[k-1][mid];
        }
    }
}

//to get the k-th father of node i
int jump(int i, int k){
    int x=0;
	while(k > 0){
		if(k&1)
			i = table[x][i];
		++x;
		k>>=1;
	}
	return i;
}

int lca(int i, int j){
	//to put i and j in the same level
    if(nodes[i].level< nodes[j].level)
        j = jump(j, nodes[j].level-nodes[i].level);
    else
        i = jump(i, nodes[i].level-nodes[j].level);
    
    //these happens if one of them was lca of them
    if(i==j)
        return i;
        
	//these is to put both just below the LCA
    for(int d = LogN; d>=0; --d){
        if(table[d][i] != table[d][j]){
            i = table[d][i];
            j = table[d][j];
        }
    }
    //as they were just below the LCA, the LCA is the parent of either of the nodes
    return table[0][i];
}

ll query(){
    ll resp = 0;

    for(int u : terminales){
        resp += nodes[u].level + nodes[central].level - 2*nodes[lca(u, central)].level;
    }

    return resp; 
}   



int main(){
    optimize();
    cin>>n>>k;

    int kaux;
    loop(i, 0, k){
        cin>>kaux;
        nodes[kaux].marca = 1;
        terminales.push_back(kaux);
    }

    int a,b;
    loop(i, 0, n-1){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    assignParents(1);
    createLCATable();
    cout<<query()<<endl;


    return 0;
}