#include <iostream>
#include <vector>
#include <cstdint>

#define loop(i, a, b) for(int i = a; i < b; ++i)
#define endl '\n'
using namespace std;
typedef int64_t ll;

const int maxN = 100002, LogN = 20;
int n;
vector<int> adj[maxN+1];
int table[LogN+1][maxN+1];

struct node{
	int level; 
    ll height;
}nodes[maxN+1];


void clean(){
    loop(i, 0, n){
        nodes[i].level = 0;
        nodes[i].height = 0;
        adj[i].clear();
    }
}


//=================== LCA
void assignParents(int nd, int fa = 0){
    for(int son: adj[nd]){
        if(son != fa){
            nodes[son].height += nodes[nd].height;
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
		for(int nd = 1; nd < n; ++nd){
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

ll query(int a, int b){
    int l = lca(a, b);
    return nodes[a].height + nodes[b].height - 2*nodes[l].height;
}   

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    while(n!=0){
        clean();
        int a;
        //read adjacency list
        for(int i = 1; i < n; ++i){
            cin>>a>>nodes[i].height;
            adj[i].push_back(a);
            adj[a].push_back(i);
        }

        //se inicializan algunas cosas quizas relativas al padre antes de recorrer el arbol
        //asignando alturas y las otras cosas
        assignParents(0);
        createLCATable();

        //procesar queries
        int q; cin>>q;
        int b, c;
        cin>>b>>c;
        cout<<query(b, c);
        loop(i, 1, q){
            cin>>b>>c;
            cout<<" "<<query(b, c);
        }
        cout<<endl;
        cin>>n;
    }
}