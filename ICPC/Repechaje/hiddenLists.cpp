#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdint>
typedef int64_t ll;
using namespace std;
const int maxN = 61;
int n[maxN+1], s;
int cn[maxN+1][maxN+1];
int64_t dp[maxN+1][maxN+1];

//ICPC Repechaje Latinoamerica 2019
//Problema H
//Disponible en:https://www.juezguapa.com/problemas/enunciado/hidden-lists

//La idea es ver que puedes recorrer el numero y en cada numero puedes decidir concatenar
//el numero hacia los que llevas concatenados atras o si apartir de ese formar un nuevo
//numero
//de modo que usamos dp para calcular todas las posibilidades

//====================================================================

//quita los ceros iniciales y lo traslada a n(un string de digitos)
void procesaString(string N){
	int i = 0;
	s = N.length();
	//vemos hasta donde estan los ceros
	while(i < s && N[i] == '0')
		++i;
	//asignamos lo restante a n
	for(int j = i; j < s; ++j)
		n[j-i] = N[j]-'0';
	//acutualizamos s
	s -= i;
}

//aqui llenamos cn que en cn[i][j] guarda cuantos numeros necesitamos despues 
//de n[i] para formar un numero mayor al formado por los ultimos j digitos 
//concatenados

//guardaremos -1 en caso de que no pueda generarse tal numero que sea mayor o igual
//o que no este entre 1 y 10^6
void llenaCN(){
    int i, j;

    //solo tiene sentido hablar de este dato mientras estamos en algun digito
    //en especifico
    for(i =0 ; i < s; ++i)
        memset(cn[i], -1, sizeof(cn[i]));

    int aVencer, num, cuantos, maxi;
    for(i = 1; i < s; i++){ 
        //aVencer es el numero al que tienes que ser mayor
        //num el numero que se ha concatenado desde ti
        //cuantos la cantidad de digitos adicionales que forman num
	    aVencer = 0;
		num = n[i];
	    cuantos = 0;
        //pueden tenerse hasta 7 concatenados hacia atras, pero apartir del 8, 
        //solo es valido si los digitos que agregamos son ceros

        maxi = min(7, i); //checas maximo 7 en este caso
        for(j = 1; j <= maxi; ++j){
	        //actualizamos aVencer
	        aVencer += n[i-j]*int(pow(10, j-1));
	                
	        //mientras haya digitos que puedas concatenarte y no seas a mayor
	        while( (cuantos+i) < s-1 && (num == 0 || num < aVencer) ){
                ++cuantos;
				num = 10*num + n[i+cuantos];
            }
            //si eres un numero valido y le ganas a aVencer
            if(num <= 1000000 && num >= aVencer && num > 0)
                cn[i][j] = cuantos;
			//si no pudiste con todas las opciones siguientes, entonces tampoco podras
        	//con mas numeros concatenados hacia atras
            //y hacemos break
            else break;
        }
        //aqui actualizamos los casos con mas de 7 concatenados hacia atras
        while(j <= i && n[i-j] == 0){
            cn[i][j] = cn[i][j-1];
            ++j;
        }

    }
}

// lo concateno o no
//dp[i][j] =  dp[i+1][j+1] + dp[i+c[i][j]+1][1]
void llenaDP(){    
    int i;
    //llenamos los dp de 0's
    for(i = 0; i < s+1; ++i)
    	memset(dp[i], 0, sizeof(dp[i]));
    
    //si llegaste al final del numero con un numero valido hay una forma
    int num = 0;
    int maxi = min(7, s);
    //como en cn, los primeros 7 se llenan normal
    //los otros podrian llenarse igual pero al ser tantos digitos puede haber overflow
    //en un int o incluso en un int64_t
    for(i = 1; i <= maxi; ++i){
    	num	+= n[s-i]*int(pow(10,i-1));
    	if(num > 0 && num <= 1000000)
    		dp[s][i] = 1;
    	else
    		dp[s][i] = 0;
    }
    //apartir del 8 digito, si aparece un digito distinto de 0, las dp siguientes son 0
    //si no eres igual a los anteriores
    //si es un cero, eres igual al caso anterior
    while(i < s && n[s-i]==0){
        dp[s][i] = dp[s][i-1];
        ++i;
    }

    //llenamos desde el ultimo digito hasta el primero	
    for(i = s-1; i >= 1; --i){
    	//vemos cuantos puede tener concatenados como maximo
	    for(int j = 1; j <= i; ++j){
	        //lo concateno
			dp[i][j] += dp[i+1][j+1];
			//no lo concateno
			//solo se puede si hay un numero despues que permita crear un numero mayor
            // al ahora concatenado
	        if(cn[i][j] != -1)
	            dp[i][j] +=  dp[i+cn[i][j]+1][1+cn[i][j]];
	    }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt","r")) freopen("case.txt","r",stdin);
    string N;
    cin>>N;
    procesaString(N);
    
    //si todos eran ceros, no hay tal lista
    if(s == 0){
    	cout<<0<<endl;
    	return 0;
    }

    //antes pense hacer la matriz contando que hubiera maximo 8 detras
    //pero no contaba con que quizas cargar mas de 8 puede ser valido si el
    //numero tiene ceros iniciales
    //como en 10000000000000011

    llenaCN();
    llenaDP();

    //imprimimos en el que estamos en el segundo digito, y imprimimos todas 
    //las posibilidades de si empezamos un numero desde ahi, o lo concatenamos
    cout<<dp[1][1]<<'\n';
    return 0;
}


