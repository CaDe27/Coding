#include <iostream>
#include <algorithm>
#include <vector>

#define loop(i, a, b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;

const int maxAlto = 100005;
const int maxN = 10005;
int n, p;
int rx1, ry1, rx2, ry2;

// ======================== Segment Tree (modificado)========================
    int lft[4*maxAlto+4], rgth[4*maxAlto+4], completo[4*maxAlto+4], hijos[4*maxAlto +4]; 
    void init(int i, int a, int b){
        lft[i] = a;
        rgth[i] = b;
        completo[i] = hijos[i] = 0;
        if(b-a <= 1) return;
        int m = (a+b)/2;
        init(2*i, a, m);
        init(2*i+1, m,b);
    }

    void SegmentTree(int inf, int sup){
        init(1, inf, sup);
    }

    void incrementI(int i, int a, int b, int val){
        //cout<<i<<" "<<lft[i]<<" "<<rgth[i]<<" "<<val<<endl;
        if(b <= lft[i] || rgth[i] <= a)
            return;
        
        if(a<=lft[i] && rgth[i]<=b){
            completo[i] += val;
            return;
        }

        else{
            incrementI(2*i, a, b, val);
            incrementI(2*i+1, a, b, val);
            hijos[i] = completo[2*i] > 0? rgth[2*i] - lft[2*i] : hijos[2*i];
            hijos[i] += completo[2*i+1] > 0? rgth[2*i+1] - lft[2*i+1] : hijos[2*i+1];
        }
        
    }

    void increment(int a, int b, int val){
        incrementI(1, a, b, val);
    }

    int queryI(int i, int a, int b){
        if(b <= lft[i] || rgth[i] <= a)
            return 0;
        
        if(a <= lft[i] && rgth[i] <= b)
            return completo[i] >= 1? rgth[i]-lft[i] : hijos[i];
        else{ 
            int leftQ =  queryI(2*i, a, b);
            int rightQ = queryI(2*i+1, a, b);
            return leftQ + rightQ;
        }
    }

    int query(int a, int b){
        return queryI(1, a, b);
    }

// ============================== Definicion de los eventos 
struct event{
    int x, abajo, arriba;
    bool ini; // true si si, false si fin
    
    event(int x1, int abajo1, int arriba1, bool ini1){
        x = x1;
        arriba = arriba1;
        abajo = abajo1;
        ini = ini1;
    }

    event(){
        x = arriba = abajo = ini = 0;
    }
};

bool comp (const event &e1, const event &e2){ 
    return e1.x < e2.x;
}

vector<event> events;

//========================sweep line
ll sweepLine(){
    ll total = 0;
    //aqui se ordena el arreglo de eventos
 
    sort(events.begin(), events.end(), comp);
    
    //se limpia el arrego de los eventos/ funcion del segment tree
    fill(completo, completo + 4*maxAlto+4, 0);
    fill(hijos, hijos + 4*maxAlto+4, 0);
    //procesamos los eventos
    
    int izq = rx1;
    ll aux;
    for(event e : events){
        aux = 1;
        aux *= (e.x - izq);
        aux *= query(ry1, ry2);
        total += aux;
        izq = e.x;
        if(e.ini)
            increment(e.abajo, e.arriba, 1);
        else
            increment(e.abajo, e.arriba, -1);
    }
    //cout<<"total: "<<total<<endl;*/
    return total;
}

//======================== definicion de rios
struct river{
    int x1, y1, x2, y2;
    river(int x,int y,int z,int w){
        x1 = x;
        y1 = y;
        x2 = z;
        y2 = w;
    }
    river(){
        x1 = y1 = x2 = y2 = 0;
    }
}rivers[maxN+5];



//========================funcion para la busqueda binaria
ll area(int r){
    events.clear();
    int izq, der, abajo, arriba;
    //cout<<"r: "<<r<<endl;
    loop(i, 0, n){
        izq =       max(rx1, rivers[i].x1 - r); 
        der =       min(rx2, rivers[i].x2 + r);
        abajo =     max(ry1, rivers[i].y1 - r);
        arriba =    min(ry2, rivers[i].y2 + r);
        events.push_back(event(izq, abajo, arriba, true));
        events.push_back(event(der, abajo, arriba, false));
    }
    return sweepLine();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;

    //leemos los rios y rectangulo
    loop(i, 0, n){
       int x,y,z,w;
       cin>>x>>y>>z>>w;
       rivers[i] = river(x,y,z,w);  
    }
    cin>>p;
    cin>>rx1>>ry1>>rx2>>ry2;

    SegmentTree(ry1, ry2);

    //hacemos bin search sobre el minimo
    int ini = 0, fin = max(ry2 - ry1, rx2 - rx1), mitad;
    long double areap = 1;
    areap *= (rx2-rx1);
    areap *= (ry2-ry1);
    areap *= p;
    areap /= 100;
    while(ini != fin){
        mitad = (ini + fin)/2;
        if(area(mitad) >= areap)
            fin = mitad;
        else 
            ini = mitad + 1;
    }
    cout<<ini<<'\n';
    return 0;
}