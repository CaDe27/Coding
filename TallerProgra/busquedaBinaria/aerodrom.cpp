#include <iostream>
using namespace std;
typedef int64_t ll;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m;
    cin>>n>>m;
		int t[n], i;
    for(i=0; i<n; ++i)
        cin>>t[i];
		
    ll ini, mitad, fin, suma;
		ini = 1; 
    fin = ((ll)t[0])*m;
	
    while(ini!=fin){
        suma = 0;
        mitad= (ini+fin)/2;
      	i = 0;
        
        while(i<n && suma < m)
            suma += mitad/t[i++];

        if(suma >= m)
            fin=mitad;
        else
            ini=mitad+1;
    }
    cout<<ini<<'\n';
}