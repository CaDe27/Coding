#include <iostream>
#include <cstdint>
#include <vector>
#define mod 188888881
typedef int64_t ll;
using namespace std;
const int maxV = 100002, maxL = 18;

//Problem available in:
//http://coj.uci.cu/24h/bestsolutions.xhtml?pid=4240

ll binPow(ll base, ll exp){
    //by Fermat's Little Theorem, a^(q*mod + r) congruent to a^(q+r)
    exp += -(exp/mod)*mod+(exp/mod);
	ll r = 1;
	while (exp > 0){
		if( exp & 1)
			r = (r*base) % mod;
		exp >>= 1;
		base = (base * base) % mod;
	}
	return r;
} 

//to obtain the inverse of pow(10, a) modulo mod
ll inversePow(ll base, ll exp){
    // by Fermat's Little Theorem; a^-1 congruent to a^p-2
    exp *= (mod - 2);

    //also by Fermat's Little Theorem, a^(q*mod + r) congruent to a^(q+r)
    exp += -(exp/mod)*mod+(exp/mod);

	ll r = 1;
	while (exp > 0){
		if( exp & 1)
			r = (r*base) % mod;
		exp >>= 1;
		base = (base * base) % mod;
	}
	return r;
} 

//to store the nodes of the tree and the tree
struct node{
	int level, code;
    ll ascPath, descPath, lvlCode, lvlPath;
}nodes[maxV+1];
vector<int> adj[maxV+1];

//=================== LCA
int table[maxL+1][maxV+1], v;
//it is also used to assig the code from the node to the root (ascPath)
// and the code from the root to the node (descPath)
// lvlPath is the size of the desc and asc paths
void assignParents(int nd, int fa = 0){
    for(int son: adj[nd]){
        if(son != fa){
            nodes[son].level = 1 + nodes[nd].level;
            table[0][son] = nd;
            nodes[son].lvlPath = nodes[nd].lvlPath + nodes[son].lvlCode;
            nodes[son].descPath = ((binPow(10, nodes[son].lvlCode)*nodes[nd].descPath)%mod + nodes[son].code)%mod;    
            nodes[son].ascPath = ((binPow(10,nodes[nd].lvlPath)*nodes[son].code)%mod + nodes[nd].ascPath)%mod;
            assignParents(son, nd);
        }
    }
}

//creates LCA Binary Lifting table
void createLCATable(){
    int mid;
	for(int k = 1; k<=maxL; ++k){
		for(int nd = 1; nd <= v; ++nd){
           mid = table[k-1][nd];
           if(mid != 0)
               table[k][nd] = table[k-1][mid];
        }
    }
}

//to get the k-th father of i
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
    for(int d = maxL; d>=0; --d){
        if(table[d][i] != table[d][j]){
            i = table[d][i];
            j = table[d][j];
        }
    }
    //as they were just below the LCA, the LCA is the parent of either of the nodes
    return table[0][i];
}

//what we do is to find the code from starting node to lca, and then merge it with 
//  code from lca to ending node
int query(int a, int b){
    int aux = lca(a, b);
    //asc is from starting node to LCA
    //asc = (ascA - ascLCAParent)/pow(10, lvla of LCAParent)
    ll asc = (((nodes[a].ascPath - nodes[table[0][aux]].ascPath)%mod)*inversePow(10, nodes[table[0][aux]].lvlPath))%mod;
    if(asc < 0) asc += mod;
    //desc is from lca to ending node
    //desc = descB - pow(10, lvla of b)*descLCA
    ll desc = (nodes[b].descPath - (binPow(10, nodes[b].lvlPath - nodes[aux].lvlPath)*nodes[aux].descPath)%mod)%mod;
    if(desc <0) desc += mod;

    //we merge both into resp
    ll resp = ((binPow(10, nodes[b].lvlPath - nodes[aux].lvlPath)*asc)%mod + desc)%mod;
    if(resp < 0) resp += mod;
    return resp;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int e;
    cin>>v>>e;
    int a, b;
    //read the code from each node and the number of digits of it
    for(int i = 1; i <= v; ++i){
        cin>>a;
        nodes[i].code = a;
        //no we recycle a and use it to count the number of digits in the code
        if((a = a/10) == 0)
            a = 1;
        else if((a = a/10) == 0)
            a = 2;
        else if((a = a/10) == 0)
            a = 3;
        else
        	a = 4;
        nodes[i].lvlCode = a;
    }

    for(int i = 0; i < v-1; ++i){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    nodes[0].ascPath = 0;
    nodes[0].lvlPath = 0;
    nodes[1].level = 0;
    nodes[1].descPath = nodes[1].code;
    nodes[1].ascPath = nodes[1].code;
    nodes[1].lvlPath = nodes[1].lvlCode;
    assignParents(1);
	createLCATable();
    int aux;
    for(int i = 0; i < e; ++i){
        cin>>a>>b;
        cout<<query(a,b)<<"\n";
    }
    
}