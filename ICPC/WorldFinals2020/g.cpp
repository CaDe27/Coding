/*
    the idea is divide in cases
        for a given phone 
        the expression is easily computed if you know wich terms are zero
        then we can divide in the cases where we determine which terms are zero 
        and which are not, and then taking the maximum value of all cases 

        this is still not trivial since, for example, for the case
        xi - x = 0, yi - y >= 0, zi - z =0
        for a phone you need to know which phones are bigger in y and lower in x and z
    
        the real key idea is that a case might be inside another one that is easier
        to calculate

        if you have the case where xi - x = 0, yi - y >= 0, zi - z =0,
        the expression is yi - y
        then we can take the phone with greatest y coordinate and the expression of the
        opCost is greater than or equal than with the phones of the this case 
            (if the phone with the greatest y is lower in x and z this is the anser of 
                the case, but if x is greater the expression is bigger with this phone
                than with the phone with th biggest y whose x and y are lower
            )
            
    this applies to all cases
    so we just update all phones with the phone that
        maximizes x coord
        maximizes y coord
        maximizes z coord
        maximizes x+y 
        maximizes x+z
        maximizes y+z
        maximizes x+y+z
        case for where all are zero doesnt need to be considered 
*/

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

typedef int64_t ll;
typedef pair<int,int> pii;
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 200005;
int n; 

ll x[maxN], y[maxN], z[maxN], opCost[maxN];
void updateOpCost(int indx, int reference){
    opCost[indx] = max(opCost[indx], 
                          max((ll)0, x[reference] - x[indx])
                        + max((ll)0, y[reference] - y[indx])
                        + max((ll)0, z[reference] - z[indx])
                        );
}

void updateAllWith(int p){
    loop(i, 0, n)
        updateOpCost(i, p);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    loop(i, 0, n)
        cin>>x[i]>>y[i]>>z[i];
    
    int indxMax = 0;
    loop(i, 1, n)
        if(x[i] > x[indxMax])
            indxMax = i;
    updateAllWith(indxMax);

    indxMax = 0;
    loop(i, 1, n)
        if(y[i] > y[indxMax])
            indxMax = i;
    updateAllWith(indxMax);

    indxMax = 0;
    loop(i, 1, n)
        if(z[i] > z[indxMax])
            indxMax = i;
    updateAllWith(indxMax);

    indxMax = 0;
    loop(i, 1, n)
        if(x[i] + y[i] > x[indxMax] + y[indxMax])
            indxMax = i;
    updateAllWith(indxMax);

    indxMax = 0;
    loop(i, 1, n)
        if(x[i] + z[i] > x[indxMax] + z[indxMax])
            indxMax = i;
    updateAllWith(indxMax);

    indxMax = 0;
    loop(i, 1, n)
        if(y[i] + z[i] > y[indxMax] + z[indxMax])
            indxMax = i;
    updateAllWith(indxMax);

    indxMax = 0;
    loop(i, 1, n)
        if(x[i] + y[i] + z[i] > x[indxMax] + y[indxMax] + z[indxMax])
            indxMax = i;
    updateAllWith(indxMax);

    int resp = 0;
    ll opMin = opCost[resp];
    loop(i, 1, n){
        if(opCost[i] < opCost[resp])
            resp = i;
    }
    cout<<opCost[resp]<<" "<<resp+1<<"\n";
    
    return 0; 
}
