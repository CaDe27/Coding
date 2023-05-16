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
#include <unordered_map>

using namespace std;
#define loop(i,a,b) for(int i = a; i < b; ++i)
int n;
unordered_map<string, bool> uniqueInitials;

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


        if(uniqueInitials.find(initials) == uniqueInitials.end()){
            uniqueInitials[initials] = true;
        }
        else{
            uniqueInitials[initials] = false;
        }
    }

    int resp = 0;
    for(pair<string, bool> par : uniqueInitials){
        if(par.second == true)
            resp += 1;
    }
    cout<<resp<<"\n";

    return 0;
}