#include <iostream>
#include <vector>
using namespace std;
const int maxN = 100002, LogN = 18;
struct node{
	int level;
}nodes[maxN+1];
vector<int> adj[maxN+1];

//=================== LCA
//asumiento que los nodos van de 1 a n
// si van de 0 a n-1 cambia el create LCA Table en el for nd = 1; nd < n
//siempre asigna a la raiz como su propio padre
int table[LogN+1][maxN+1], n;
void assignParents(int nd, int fa = nd){
    for(int son: adj[nd]){
        if(son != fa){
            nodes[son].level = 1 + nodes[nd].level;
            table[0][son] = nd;
            //aqui puedes aprovechar para agregar funcionalidad que ocupes para el
            //problema especifico
            assignParents(son, nd);
        }
    }
}

//creates LCA Binary Lifting table
void createLCATable(){
    int mid;
	for(int k = 1; k<=LogN; ++k){
		for(int nd = 2; nd <= n; ++nd){
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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    int a, b;
    //read adjacency list
    for(int i = 0; i < n-1; ++i){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //se inicializan algunas cosas quizas relativas al padre antes de recorrer el arbol
    //asignando alturas y las otras cosas
    assignParents(1);
	createLCATable();

    //procesar queries
}
