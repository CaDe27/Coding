// 2 3 5 7 
// 1 4 9
// 0, 6, 8 ignore 
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k; cin>>k;
    string s; cin>>s;
    for(char c : s)
        if(c == '0' || c == '8' || c == '6')
            --k;
    cout<<k<<"\n";
    return 0;
}