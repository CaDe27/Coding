#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> refs;
    string s;
    while(getline(cin, s)){
        refs.push_back(s);
    }
    sort(refs.begin(), refs.end());
    for(string s : refs){
        cout<<s<<"\n";
    }
    return 0;
}