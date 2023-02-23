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
string s;
int it;
int val(int total){
    int countP = 0, v = 0;
    while(countP < total){
        if(s[it] == '*')
            ++v;
        else if(s[it] == '('){
            v<<=1;
        }
        else 
            ++countP;
        ++it;
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    loop(i, 0, t){
        cin>>s;
        it = 0;
        cout<<"Case "<<(i+1)<<": ";
        cout<<val(2)<<val(4)<<":"<<val(3)<<val(4)<<":"<<val(3)<<val(4)<<"\n";
    }
    return 0;

}