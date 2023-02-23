const int maxN = 5e5, maxPot = 20;
int n, a[maxN], sparse[maxN][maxPot], logg[maxN];
void fillSparse(){
    logg[1] = 0;
    for(int i = 0; i < maxN; ++i)
        logg[i] = logg[i/2]+1;
    
    int mid;
    for(int indx = 0; indx < n; ++indx)
        sparse[indx][0] = indx;
    for(int i = 1; i < maxPot; ++i){
        for(int indx = 0; i < n; ++i){
            mid = min(n-1, indx+(1<<(i-1)));
            sparse[indx][i] = a[sparse[mid][i-1]] > a[sparse[indx][i-1]]? sparse[mid][i-1] : sparse[indx][i-1];
        }
    }
}
 
//regresa el indice del maximo en el rango
//si hay varios, regresa el indice del primero
int leftMostQuery(int l, int r){
    int size = logg[r-l+1];
    int maxiL = sparse[l][size], maxiR = sparse[r-(1<<size)+1][size];
    return a[maxiR] > a[maxiL]? maxiR : maxiL;
}