#include <iostream>
#include <algorithm>

using namespace std;
typedef int64_t ll;

const int maxL = 100005;
ll b,p;
int l,n;
ll bit[maxL], powersOfB[maxL], inversePowers[maxL];
ll bytes[maxL];
int topeP, topeI;

//limpiar los arreglos para cada caso
void clean();

//manejo de potencias de b
ll binPow(ll base, ll exp);
ll powers(int k);
ll inverses(int k);

//BIT
void update(int pos, ll x);
ll query(int pos);
ll query(int pos1, int pos2);


int main(){
    ios_base::sync_with_stdio(0);
    cin>>b>>p>>l>>n;
    while(!(b == 0 && p == 0 && l == 0 && n == 0)){
        clean();
        char type;
        int j, k;
        ll v ,updateValue;
        for(int i = 0; i < n; ++i){
            cin>>type;
            if(type == 'E'){
                cin>>j>>v;
                // quita el valor anterior y pon el nuevo
                // si vas en el j, en el arrego te toca el l - j +1 
                update(j, (-bytes[j] + p) * powers(l-j));
                update(j, v*powers(l-j));
                bytes[j] = v;
            }
            else
            {
                cin>>j>>k;
                //quiere el hash de j a k
                //entonces le damos el de la query de l - k a l - j
                cout<<query(j, k)<<'\n';
            }
        }
        cout<<"-\n";
        cin>>b>>p>>l>>n;
    }

    return 0;
}

void clean(){
    fill(bit, bit + l + 5, 0);
    fill(powersOfB, powersOfB + l + 5, 0);
    fill(inversePowers, inversePowers + l + 5, 0);
    fill(bytes, bytes + l + 5, 0);

    powersOfB[0] = inversePowers[0] = 1;
    powersOfB[1] = b;
    inversePowers[1] = binPow(b, p-2);
    topeP = topeI = 1;
}

ll binPow(ll base, ll exp){
	ll r = 1;
	while (exp > 0){
		if(exp & 1)
			r = (r*base) % p;
		exp >>= 1;
		base = (base * base) % p;
	}
	return r%p;
} 

ll powers(int k){
    for(; topeP < k; ++topeP)
        powersOfB[topeP+1] = (powersOfB[topeP] * b)%p;
    return  powersOfB[k];
}

//el inverso de b^i es (b^i)^p-2 = (b^p-2)^i
ll inverses(int k){
    for(; topeI < k; ++topeI)
        inversePowers[topeI+1] = (inversePowers[topeI] * inversePowers[1])%p;
    return  inversePowers[k];
}

void update(int pos, ll x){
    x = x%p;
    while(pos <= l){
        bit[pos] = (bit[pos] + x)%p;
        pos += pos&(-pos);
    }

}

ll query(int pos){
    ll suma = 0;
    while(pos > 0){
        suma = (suma + bit[pos])%p;
        pos -= pos&(-pos);
    }
    return suma;
}

ll query(int pos1, int pos2){
    ll resp = (query(pos2) - query(pos1-1) + p)%p;
    resp = (resp * inverses(l - pos2)) %p;
    if(resp < 0)
        resp += p;
    return resp;
}