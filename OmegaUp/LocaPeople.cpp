#include <iostream>
#include <algorithm>
#include <stack>
#define ptop pila.top()
using namespace std;

const int max_n = 1002, max_m = 1002;
int h[max_n][max_m], maxA[max_n][max_m], maxABase[max_n][max_m];
int n, m;
void leeAlturas(){
	int aux;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++){
			cin>>aux;
			h[i][j] = aux? (h[i-1][j] + 1) : 0;
			maxA[i][j] = -1;
	}
} 

void maxAreaBase(int j){
	int extiende[j+2], como, ancho, i, h_;
	fill(extiende, extiende+j+2, 0);
	stack< pair<int, int> > pila;
    pair<int,int> aux;
	for(i = 1; i <= m+1; ++i){
		h_ = h[j][i];
		como = 0;
		while(!pila.empty() && h_ <= pila.top().first){
			//el ancho del que voy a sacar es igual a los que me he comido
			//los que me he comido son los que ese se come a la derecha y los que agrego 
			//son los que el se come a la izq
			//asi los que como en total hasta ahora se vuelven el ancho del que saco
			como += pila.top().second + 1;
			if(como > extiende[pila.top().first])
				extiende[pila.top().first] = como;
			pila.pop();
		}
        aux.first = h_; aux.second = como;
		pila.push(aux);
	}
	for(i = j; i >= 0; --i)
		extiende[i] = max(extiende[i], extiende[i+1]);
	for(i = j; i >= 0; --i)
		extiende[i]*=i;
	for(i = 1; i<=j; ++i){
		extiende[i]	= max(extiende[i], extiende[i-1]);
		maxABase[j-i+1][j] = extiende[i];
	}
}

int maxArea(int i, int j){
	if(i > j) return 0;
	if(maxA[i][j] == -1)
		maxA[i][j] = max(maxArea(i,j-1), maxABase[i][j]);
	return maxA[i][j];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt","r")) freopen("case.txt","r",stdin);
	cin>>n>>m;
	leeAlturas();
	for(int j = 1; j <= n; ++j)
		maxAreaBase(j);
	int p, a, b;
	cin>>p;
	for(int i = 0; i < p; ++i){
		cin>>a>>b;
		cout<<maxArea(a, b)<<"\n";
	}
	return 0;
}