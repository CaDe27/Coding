#include <iostream>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <map>
#include <stdlib.h>
#define LL int64_t

using namespace std;
typedef int64_t ll;

map<LL,int>fact;
LL power(LL x, LL n, LL mod)
{
    LL res = 1;
    while(n){
        if(n&1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

bool millerRabinTest(LL s, LL n){
    LL a = (rand() % (n - 4)) + 2;
    //dividimos entre la pot mas grande de dos que divide a s
    LL mod = power(a, s, n);
    if(mod == 1 or mod == (n - 1))
        return true;

    while(s != (n-1))
    {
        mod = power(a, s, n);
        s *=2;

        if(mod == (n - 1))
            return true;
        else if(mod == 1)
            return false;
        
    }
    return false;
}

//fermats primality test
bool isprime(LL n)
{
    if(n == 2 or n == 3) return true;
    if(n < 2 or n%2==0) return false;
    LL d = n-1;
    d /= d&(-d);
    for(int i = 0; i < 10; i++)
        if(!millerRabinTest(d, n))
            return false;
    return true;
}

LL gcd(LL a, LL b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

LL pollard_rho(LL n)
{
    if(n % 2 == 0) return 2;
    LL x = rand() % n + 1;
    LL c = rand() % n + 1;
    LL y = x;
    LL d =  1;
    while(d == 1)
    {
        x = (power(x,2,n) + c ) % n;
        y = (power(y,2,n) + c ) % n;
        y = (power(y,2,n) + c ) % n;
        d = gcd(abs(x-y),n);
        if(d == n) 
            return pollard_rho(n);
    }
    return d;

}
void factorize(LL n)
{
    if(n == 1)
        return;
    if( isprime(n) )
    {
        fact[n]++;
        return;
    }
    LL div = pollard_rho(n);
    factorize(div);
    factorize(n/div);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //srand(time(NULL));
    int cases = 1;
    ll num;
    cin>>num;    
    factorize(num);
    ll resp = 1;
    for(auto a: fact)
        if(a.second & 1) resp *= a.first;
    cout<<resp<<"\n";
}  
