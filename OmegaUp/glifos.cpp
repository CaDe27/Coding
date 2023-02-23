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

using namespace std;

typedef int64_t ll;

#define loop(i,a,b) for(int i = a; i < b; ++i)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int g, n;
    cin>>g>>n;

    int w[59], cont[59], contW;

    fill(w, w+59, 0);
    fill(cont, cont+59, 0);

    string wa;
    cin>>wa;
    loop(i, 0, g)
        ++w[ wa[i]-'A'];

    contW = 0;
    int pos;

    string s;
    cin>>s;

    loop(i, 0, g){
        pos = s.at(i) - 'A';
        if(w[pos] > 0){
            if(cont[pos] < w[pos])
                ++contW;
            ++cont[pos];
        }
    }

    int resp = 0;
    if(contW == g)
        ++resp;

    loop(i, g, n){
        pos = s.at(i) - 'A';
        if(w[pos] > 0){
            if(cont[pos] < w[pos])
                ++contW;
            ++cont[pos];
        }

        pos = s.at(i-g) - 'A';
        if(w[pos] > 0){
            if(cont[pos] <= w[pos])
                --contW;
            --cont[pos];
        }

        if(contW == g)
            ++resp;
    }
        
    cout<<resp<<"\n";

    return 0;

}