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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    loop(i, 0, t){
        vector<int> arre;
        int aux;
        loop(i, 0, 10){
            cin>>aux;
            arre.push_back(aux);
        }
        bool asc  =true , desc = true; 
        loop(i, 0, 9){
            if(arre[i] > arre[i+1])
                asc = false;
            else if(arre[i] < arre[i+1])
                desc = false;
        }
        if(!asc && !desc)
            cout<<"Unordered\n";
        else
            cout<<"Ordered\n";
    }
    return 0;

}