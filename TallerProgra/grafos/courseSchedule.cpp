#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;

//tengo "de cuantos dependo"
// adyacencia de quienes dependen de mi
// busco uno que no tenga prerrequisitos, quito dependencias  y meto a ED 
// si ya no tienen dependencias
// si en un momento no hay, y no se visitaron todos, regresa arreglo vacio

vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
    int visitados = 0;
    int numDependencias[numCourses];
    fill(numDependencias, numDependencias + numCourses, 0);
    vector<int> dependenDeMi[numCourses];

    for(vector<int> v :  prerequisites){
        dependenDeMi[v[1]].push_back(v[0]);
        ++numDependencias[v[0]];
    }  

    stack<int> sinPrerrequisitos;
    loop(i, 0, numCourses)
        if(numDependencias[i] == 0)
            sinPrerrequisitos.push(i);

    vector<int> orden;
    int sigNodo;
    while(!sinPrerrequisitos.empty()){
        ++visitados;
        sigNodo = sinPrerrequisitos.top();
        sinPrerrequisitos.pop();

        orden.push_back(sigNodo);

        for(int nodo : dependenDeMi[sigNodo]){
            --numDependencias[nodo];
            if(numDependencias[nodo] == 0)
                sinPrerrequisitos.push(nodo);
        }
    }

    if(visitados < numCourses)
        orden.clear();
    
    return orden;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n,m;
    cin>>n>>m;
    vector< vector<int> > pre;
    int a, b;
    loop(i, 0, m){
        vector<int> curVec;
        cin>>a>>b;
        curVec.push_back(a);
        curVec.push_back(b);
        pre.push_back(curVec);
    }
    vector<int> resp = findOrder(n, pre);
    loop(i, 0, resp.size())
        cout<<resp[i]<<" ";
    cout<<endl;
    return 0; 
}
