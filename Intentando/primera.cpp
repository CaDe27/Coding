#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

    unordered_map<int, int> map;
    for(int i = 0; i < 10; ++i)
        map.insert(make_pair(i, 10000*i));
    
    cout<<map[6]<<"\n";
    return 0;
}