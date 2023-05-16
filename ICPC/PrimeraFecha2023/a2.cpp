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

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 100005;
int n;

set<string> unicos, repetidos;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>n;
    int size; 
    string name, initials;
    loop(i, 0, n){
        cin>>size;
        initials = "";
        loop(j, 0, size){
            cin>>name;
            initials += name[0];
        }

        if(unicos.find(initials) != unicos.end()){
            repetidos.insert(initials);
            unicos.erase(initials);
        }
        else if(repetidos.find(initials) == repetidos.end()){
            unicos.insert(initials);
        }
    }

    cout<<unicos.size()<<"\n";

    return 0;
}