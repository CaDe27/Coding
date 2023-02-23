#include <iostream>

using namespace std;

int n;
const int maxN = 1e5 +5;
int arre[maxN], comp[maxN], prox1[maxN], proxM1[maxN];

int compara(int a, int b){
    if(a == b) return 0;
    else if(a < b) return 1;
    else return -1;
}

bool EsMontania(int ini, int fin){
    
    if(fin - ini +1 <= 2) return false;
    if(arre[ini+1] != -1 && arre[ini] != -1 && comp[ini+1] == -1) return false;

    int nextM1 = proxM1[ini+1];
    if(nextM1 > fin){
        return comp[fin] == 0 || arre[fin] == -1 || arre[fin-1] == -1;
    }
    else if(nextM1 == fin)
        return true;
    else 
    {
        int next1 = prox1[nextM1+1];
        return next1 > fin || (next1 == fin && arre[fin] == -1);
    }
}

bool TryPartition(int size){
    bool resp = true;
    int it = 0;
    while(it < n && resp){
        resp = EsMontania(it, min(it + size - 1, n-1));
        it += size;
    }
    return resp;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    
    for(int i = 0; i < n; ++i)
        cin>>arre[i];
    
    for(int i = 1; i < n; ++i){
        if(arre[i-1] == -1 && arre[i] == -1) 
            comp[i] = 0;
        else if(arre[i-1] == -1)
            comp[i] = i-1 == 0 || arre[i-2] == -1? 0 : compara(arre[i-2], arre[i]);
        else if(arre[i] == -1)
            comp[i] = i == n-1 || arre[i+1] == -1? 0 : compara(arre[i-1], arre[i+1]); 
        else
            comp[i] = compara(arre[i-1], arre[i]);
    }

    int indxM1 = n, indx1 = n;
    for(int i = n-1; i > -1; --i){
        if(comp[i] == 1) indx1 = i;
        else if(comp[i] == -1) indxM1 = i;
        prox1[i] = indx1;
        proxM1[i] = indxM1;
    }

    //for each size we try to partition the array into subarrays of this length
    bool resp = false;
    int size = 3;
    while(size <= n && !resp){
        resp = TryPartition(size);
        ++size;
    }
    cout<<(resp? "Y" : "N")<<"\n";
    return 0;
}