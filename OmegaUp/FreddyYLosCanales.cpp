#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
const int maxN = 100002, maxL = 18;

//Graph
struct node{
	int left, right;
}nds[maxN+1];
vector<int> adj[maxN+1];

//=================== LCA
int level[maxN+1], table[maxL+1][maxN+1], n;
void createLCATable(){
    int mid;
	for(int k = 1; k<=maxL; ++k){
		for(int nd = 1; nd <= n; ++nd){
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
    if(level[i] < level[j])
        j = jump(j, level[j]-level[i]);
    else
        i = jump(i, level[i]-level[j]);
    //these happens if one of the was lca of them
    if(i==j)
        return i;
        
	//these is to put them just below the LCA
    for(int d = maxL; d>=0; --d){
        if(table[d][i] != table[d][j]){
            i = table[d][i];
            j = table[d][j];
        }
    }
    return table[0][i];
}

//=================== tour
int cont = 0;
void tour(int actual, int fa = 0)
{
	nds[actual].left = ++cont;
	for(int h: adj[actual]){
		if(h!=fa){
			level[h] =1 + level[actual];
			table[0][h] = actual;
			tour(h, actual);
		}
	}
	nds[actual].right = ++cont;
}

//==================== BIT/Fenwick Tree
int bit[maxN*2 + 4], maxBit;
int getSum(int index){ 
    int sum = 0;
    while(index > 0){
    	sum+=bit[index];
    	index -= (index & -index);
    }
    return sum; 
} 
 
void update(int index, int value) {
    while(index<=maxBit){
        bit[index]+= value;
        index+= index&-index;
    }
}  

//====================
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int m;
	cin>>n>>m;
	//read adjacency list
	int a,b;
    for(int i = 0; i < n-1; ++i){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //create tour array
	tour(1);
	
    //create LCA
    createLCATable();
	//process queries
	char c;
	int aux;
	maxBit = 2*n+3;
	for(int i = 0; i < m; ++i){
		cin>>c>>a>>b;
		if(c == 'P'){
			aux = lca(a,b);
			update(nds[a].right, 1);
			update(nds[b].right, 1);
			update(nds[aux].right, -2);
		}
		else{
			if(level[a] < level[b])
				a = b;
			cout<<getSum(nds[a].right) - getSum(nds[a].left - 1)<<'\n';
		}
	}
	return 0;
}