#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>

using namespace std;
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int A,B;
    char c;
    
    
    int index = 1;
    
    cin >> A;
    
    while(A != -1){
        cin >> B >> c;
        
        ll n = A;
        ll m = B;
        
        if(n == 0 || m == 0){
            cout << "Case " << index << ": " << n << " x " << m << " = 0\n";
            index++;
            cin >> A;
            continue;
        }
        
        vector<ll> V;
        while(n > 0){
            if(n%2){
                V.push_back(m);
            }
            m *= 2;
            n /= 2;
        }
        
        if(c == 'b') reverse(V.begin(),V.end());
        
        cout << "Case " << index << ": " << A << " x " << B << " = ";
        for(auto u:V){
            cout << u;
            if(u != V[V.size()-1]) cout << " + ";
        }
        cout << "\n";
        index++;
        cin >> A;
    }

    
    return 0;
}