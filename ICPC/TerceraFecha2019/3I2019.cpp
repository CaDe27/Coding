#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>
using namespace std;

struct planeta{
	int num;
	int64_t temperatura;
};

struct query{
	int a,b,k, index;
};

bool comparaP(const planeta &x, const planeta &y){
	return x.temperatura < y.temperatura;
}

bool comparaQ(const query &x, const query &y){
	return x.k < y.k;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//leer n planetas y R cantidad de uniones
	int n, r;
	cin>>n>>r;
	planeta p[n+1];
	//el camino entre cualesquiera dos es a lo mas 
	//maxCosto*n = 1000*400=4*10^5<10^9 y cabe en un int
	int gfrio[n+1][n+1], gcaliente[n+1][n+1];
	
	//leer y ordenar planetas
	for(int i = 1; i <= n; ++i){
		cin>>p[i].temperatura;
		p[i].num = i;
	}
	sort(p+1, p+n+1, comparaP);
	int tDif[n+1], sDif =1;
	tDif[1]=p[1].temperatura; 
	for(int i = 2; i <= n; ++i){
		if(p[i].temperatura != tDif[sDif])
			tDif[++sDif] = p[i].temperatura;
	}
	//para despues usarlo en floyd warshall
	for(int i = 1; i <= n ; ++i){
		fill(gfrio[i]+1, gfrio[i]+n+1, 1000000);
		fill(gcaliente[i]+1, gcaliente[i]+n+1, 1000000);
		gfrio[i][i] = 0;
		gcaliente[i][i] = 0;
	}
	
	//leer matriz del grafo //coldest y hottest
	int x, y, d;
	for(int i=0; i < r;++i){
		cin>>x>>y>>d;
		//resto uno pues los guardo entre 0 y n-1
		gfrio[x][y] = d;
		gfrio[y][x] = d;
		gcaliente[x][y] = d;
		gcaliente[y][x] = d;
	}
	
	//leer queries, dividirlas por bloque y ordenarlas
	int q;
	cin>>q;
	vector<query> frios, calientes;
	int resp[q];
	query aux;
	int t;
	for(int i = 0; i < q; ++i){
		cin>>aux.a>>aux.b>>aux.k;
		aux.index = i;
		cin>>t;	
		if(t)
			calientes.push_back(aux);
		else
			frios.push_back(aux);
	}
	sort(frios.begin(), frios.end(), comparaQ);
	sort(calientes.begin(), calientes.end(), comparaQ);
	//correr floyd warshall en cada bloque
	int tope, kAct, numP;
	/*tope indica los primeros incluidos como intermedios hasta el momento
	//kAct indica que en este momento utiliza las k temperaturas mas frias o mas
	//		calientes
	//numP va a indicar el planeta que tiene cierta temperatura
	*/
	tope = 0; kAct = 0;
	for(query aux:frios){
		if(kAct < aux.k){
			kAct = min(aux.k, sDif);
			t = tDif[kAct];
			for(int k=tope+1; k<=n && p[k].temperatura<=t; ++k){
				++tope;
				for(int i = 1; i <=n-1; ++i)
				for(int j = i+1; j <= n; ++j){
					numP = p[k].num;
					if(gfrio[i][j] > gfrio[i][numP]+gfrio[numP][j]){
						gfrio[i][j] = gfrio[i][numP]+gfrio[numP][j];
						gfrio[j][i] = gfrio[i][j];
					}
				}
			}
		}
		resp[aux.index] = gfrio[aux.a][aux.b]==1000000? -1:gfrio[aux.a][aux.b];
	}
	
	tope = n+1; kAct = 0;
	for(query aux:calientes){
		if(kAct < aux.k){
			kAct = min(aux.k, sDif);
			t = tDif[sDif+1-kAct];
			for(int k=tope-1; k>=1 && p[k].temperatura>=t; --k){
				--tope;
				for(int i = 1; i <=n-1; ++i)
				for(int j = i+1; j <= n; ++j){
					numP = p[k].num;
					if(gcaliente[i][j] > gcaliente[i][numP]+gcaliente[numP][j]){
						gcaliente[i][j] = gcaliente[i][numP]+gcaliente[numP][j];
						gcaliente[j][i] = gcaliente[i][j];
					}
				}
			}
		}
		//guardar respuesta
		resp[aux.index] = gcaliente[aux.a][aux.b]==1000000? -1:gcaliente[aux.a][aux.b];
	}
	
	//imprimir respuestas
	for(int i = 0; i<q; ++i)
		cout<<resp[i]<<'\n';
	return 0;
}