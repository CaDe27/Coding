#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>


using namespace std;

typedef int64_t ll;
typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define loop(i, a, b) for(int i = a; i < b; ++i)
const int maxA = 1000000;
vi adj[maxA+1];
bool esComponente[1000001], enGrafo[1000001];
int n;

// ======== criba
int criba[maxA+1];
void llenaCriba(){
    fill(criba, criba+maxA+1, 0);
    for(int i = 2; i*i <= maxA ; ++i)
        if(criba[i] == 0){
            criba[i] = i;
            for(int j = i * i; j <= maxA; j+=i)
                criba[j] = i;
                
        }
}

// ======== encuentra el menor ciclo en la grafica
int menorCiclo(){
    int resp = (int)(1e8);
    int h[maxA+1];
    pii aux;
    int v, f;
    
    //normalmente es en dominio de adj, pero aqui basta recorrer los menores
    loop(root, 1, 1000){
        if(!esComponente[root])
            continue;

        queue<pii> bfs;
        
        fill(h, h+1000001, -1);
        h[root] = 0;
        bfs.push(pii(root, 0));

        while(!bfs.empty()){
            v = bfs.front().first; 
            f = bfs.front().second;
            bfs.pop();

            for(int s: adj[v])
            {
                if(s == f) 
                    continue;
                
                if(h[s]==-1)
                {
                    h[s] = h[v] + 1;
                    bfs.push(pii(s, v));
                }

                else
                   resp = min(resp, h[s] + h[v] + 1);
            }
        }
    }
    return resp;
}


// main
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    llenaCriba();
    cin>>n;

    int a, p, q;
    bool cuadrado = false, repetido = false;
    loop(i, 0, n){
        cin>>a;
        if(a == 1)
            cuadrado = true;
        else if(criba[a] == 0){
            adj[a].push_back(1);
            adj[1].push_back(a);
        }
        else{
            p = criba[a]; 
            while(  a%(p*p) == 0)
                a /= (p*p);
            if( (a%p) !=0) //p^2 te divide completamente 
                p = 1;

            a /= p;

            q = criba[a];
            if(q!=0) 
                while( a%(q*q) == 0)
                    a /= (q*q);
            
            q = a;
            
            
            if(p==1 && q==1)
                cuadrado = true;

            if(enGrafo[p*q])
                repetido = true;

            enGrafo[p*q] = 1;
            esComponente[p] = esComponente[q] = 1;
            adj[p].push_back(q);
            adj[q].push_back(p);
        }
    }

    if(cuadrado)
        cout<<1<<"\n";
    else if(repetido)
        cout<<2<<"\n";
    else{
        int resp = menorCiclo();
        if(resp > 1000)
            resp = -1;
        cout<<resp<<"\n";
    }
    return 0;

    

}


