#include <iostream>
#include <stack>
#include <math.h>

using namespace std;
typedef pair<int,int> pii;
typedef long double ld;

#define loop(i, a, b) for(int i = a; i < b; ++i)
#define loopi(i, a, b) for(int i = a; i <= b; ++i)

ld FBinomial(ld n, ld p, ld x){
    ld coef, q, pAcum, qAcum;
    coef = 1;
    q = 1-p;
    pAcum = 1;
    qAcum = pow(q, 220);

    ld resp = qAcum;
    loopi(i, 1, x){
        pAcum *= p;
        qAcum /=q;
        coef *= (220 - i);
        coef /= (i);
        resp += coef*pAcum*qAcum;
    }
    return resp;
}

ld FPoisson(ld lambda, ld x){
    ld lambdaAcum = 1, fact = 1;
    ld sum  = lambdaAcum;
    loopi(i, 1, x){
        lambdaAcum *= lambda;
        fact *= i;
        sum += lambdaAcum/fact;
    }
    return sum*exp(-lambda);
}

int main(){
    int maxN = 1000000;
    cout<<maxN<<endl;
    int ini = 0, fin = ((1<<30) - 2);
    for(int i = 0; i < maxN-1; ++i){
        cout<<ini<<" "<<fin<<" "<<1000<<"\n";
        ini++;
        fin--;
    }
    cout<<( (1<<30) - 1)<<" "<<(1<<30)<<" "<<1000<<endl;;
    
    return 0;
}