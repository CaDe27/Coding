#include <iostream>
#include <algorithm>

#define optimize() ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define MOD 1000000007

using namespace std;
typedef int64_t ll;

const int maxB = 5001;
ll dp[maxB][maxB], acum1[maxB][maxB], acum2[maxB][maxB];
bool visited[maxB][maxB];

//n es lo que me falta y m lo ultimo que puse


//sumatorio de i=1 hasta m de dp(n-i, i) 
ll acumulado1(int n, int m);
ll acumulado2(int n, int m);
ll DP(int n, int m);


int main(){
    optimize();
    int s, b;
    cin>>s>>b;
    //si me faltan de acomodar 0, solo hay una forma de acomodarlos
    fill(dp[0], dp[0]+s+1, 1);
    fill(visited[0], visited[0]+s+1, 1);
    cout<<DP(b-s, s)<<endl;
}

ll acumulado1(int n, int m){
    if(!visited[n][m]){
        acum1[n][m] = DP(n-m,m);
		if(m>1)
			acum1[n][m] = (acum1[n][m] + acumulado1(n,m-1))%MOD;
    }
    return acum1[n][m];
}

ll acumulado2(int n, int m){
    if(!visited[n][m]){
        acum2[n][m] = (m*DP(n-m,m))%MOD;
		if(m>1)
			acum2[n][m] = (acum2[n][m] + acumulado2(n,m-1))%MOD;
    }
    return acum2[n][m];
}

ll DP(int n, int m){
    if(!visited[n][m]){
    	
        ll resp = 0;
        //si lo puedo tomar
        int t = min(m, n);
        resp += ((m+1)*acumulado1(n, t))%MOD - acumulado2(n,t);
        if(resp < 0)
            resp += MOD;
        dp[n][m] = resp;
        visited[n][m] = 1;
    }
    return dp[n][m];
}