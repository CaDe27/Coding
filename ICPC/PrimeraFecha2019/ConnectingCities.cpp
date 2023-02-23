#include <iostream>
#include <algorithm>
#include <cstdint>
typedef int64_t ll;
using namespace std;
// maximo de vertices  y de aristas/enlaces 
const int maxN = 10005, maxP = 100005;
int father[maxN], uniones;

struct puente{
    int ini, fin, cost;
}nodes[maxP]; 

int find(int u){
    if(father[u] == u)
        return u;
    else
    	return father[u] = find(father[u]); 
}

bool unite(int a, int b){
    int fa = find(a), fb = find(b);
    if(fa == fb)
    	return false;
    else{
        ++uniones;
        father[fa] = fb;
        return true;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCases, n, c, p, i;
    ll costo;
    /*
    	n cantidad de vertices
    	c cantidad de enlaces iniciales
    	p cantidad de enlaces propuestos
    	uniones cantidad de uniones que se han hecho con union find
    			si uniones == n-1 entonces todos estan conectados
    */
    
    cin >> testCases;
    for(int t = 0; t < testCases; ++t){
        cin>>n>>c;
        for(i = 1; i <= n; ++i)
	        father[i] = i;
        uniones = 0;
        costo = 0;
        
        //lees los enlaces iniciales
        puente a;
        for(i = 0; i < c && uniones < n-1; ++i){
            cin >> a.ini >> a.fin >> a.cost;
            unite(a.ini, a.fin);
        }
        //si ya estan todos conectados solo termino de leer el testcase
        for( ;i < c; ++i)
        	cin >> a.ini >> a.fin >> a.cost;
        
        //lees lo enlaces propuestos
        cin>>p;
        //si ya acabe
        if(uniones == n-1){
            cout << "Thank you, Goodbye" << '\n';
	        for(int i = 0; i < p; ++i)
	            cin >> a.ini >> a.fin >> a.cost;
        }
        else{
        	//si faltan, mientras no esten todos unidos y tengas propuestas
        	//sigues checando si ayudan a enlazar
        	
        	//se ordenan las propuestas por costo
        	for(int i = 0; i < p; ++i)
            	cin >> nodes[i].ini >> nodes[i].fin >> nodes[i].cost;
            sort(nodes, nodes + p, [](const puente &a,const puente &b){return a.cost < b.cost;});
           //se checa si ayudan a enlazar
            
            for(int i = 0; i < p && uniones < n-1; ++i)
                if(unite(nodes[i].ini, nodes[i].fin))
                    costo += nodes[i].cost;
	        if(uniones < n-1)
	            cout << "You better hire someone else" << '\n';
	        else
	            cout << costo << '\n';
        }
    }
    return 0;
}