//la idea clave es ver que la linea divisora puede ponerse
//de forma que toque al menos dos puntos de uno de los conjuntos
// y que el unico caso en que esto falla es cuando los puntos 
//forman una sola linea
// esto permite ya solo probar como linea divisora a las lineas
//que unen dos de los vertices dados

#include <iostream>
#include<algorithm>
using namespace std;

const int maxN = 500;
int n;
long resp = 500*1000000 + 1;
bool formanLinea = false; //para el caso en el que formen una sola linea

struct point{
    int x, y, p;
}comp[maxN+1]; //companias

void calculaMin(int i, int j){
    //refiriendonos al precio acumulado de cada lado de la linea
    //medio quiere decir que esta en la linea
    long izq, medio, der;
    //nos serviran para hacer las comparaciones y determinar de que lado
    //esta la linea
    long exp1, exp2;

    //guardaremos la informacion de la linea con y = mx+b
    //pero para no perder precicion multiplicamos todo por el denominador
    //de la pendiente
    //obteniendo y*m2 = m1*x + b*m2
    long m1, m2,bm2;
    if(comp[i].x == comp[j].x) //si es una linea vertical solo comparamos en x
            exp2 = comp[i].x;
    else{ 
    //si no lo que haremos es comparar y con mx + b
    // si y = mx +b, estas en la linea
    // si y > mx + b, estas a la izquierda/arriba de la linea
    // si y < mx + b estas a la derecha/abajo de la linea
        m1 = comp[i].y - comp[j].y;
        m2 = comp[i].x - comp[j].x;
        bm2 = m2*comp[i].y - m1*comp[i].x;
    }

    izq = medio = der = 0;
    for(int k = 0; k < n; ++k){
        if(comp[i].x == comp[j].x)
            exp1 = comp[k].x;
        else{
            exp1 = comp[k].y * m2;
            exp2 = m1*comp[k].x + bm2;
        }
        if(exp1 == exp2)
            medio += comp[k].p;
        else if(exp1 < exp2)
            izq += comp[k].p;
        else 
            der += comp[k].p;
    }
    //si estan en una linea, izq y der deben ser 0
    if(izq == 0 && der == 0)
        formanLinea = true;
    //el min en este caso es el minimo de la respuesta actual contra 
    //el minimo de unir los de en medio con los de la derecha o la izquiera
    resp = min(resp, min(abs(izq+ medio - der), abs(der + medio - izq)));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;

    for(int i = 0 ; i < n; ++i)
        cin>>comp[i].x>>comp[i].y>>comp[i].p;

    for(int i = 0; i < n; ++i)
    for(int j = i+1; j < n; ++j){
        calculaMin(i, j);    
        //si forman una sola linea, cortamos los ciclos y checamos aparte
        if(formanLinea)
            i = j = n;
    }

    //si forman una sola linea, creamos un punto que no este en la linea
    //y llamamos al mismo procedimiento
    //podriamos en vez de hacer las comparaciones con cada uno de 
    // i, n, ordenarlos en base a su posicion x e y, obtener la suma total
    // y recorrer hasta donde sea minimo haciendo este caso en n log n
    //pero como son a lo mas 500 datos, n^2 funciona y no tienes que programar
    //mas que esto

    if(formanLinea){
        //creamos un punto fuera de la linea y tratamos todas las lineas
        //de este a un punto en la linea original
   
        //si es una linea vertical
        if(comp[0].x == comp[1].x)
            comp[n].x = comp[n].y = comp[0].x+1;
        else{//si no
            comp[n].x = comp[0].x;
            comp[n].y = comp[0].y+1;
        }
        for(int i = 0; i < n;++i)
            calculaMin(i,n);
    }

    cout<<resp<<'\n';
}