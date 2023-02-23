#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool esPalindromo(string s){
    for(int i = 0; i < s.size(); ++i)
        s[i] = tolower(s[i]);
        
    unordered_map<char, int>  cubeta;
    for(char c : s){
        if(cubeta.find(c) == cubeta.end())
            cubeta[c] = 1;
        else
            cubeta[c] = cubeta[c] + 1;
    }
    int oddChars = 0;
    for(pair<char, int> mapTuple : cubeta){
        if(mapTuple.second%2 == 1)
            ++oddChars;
    }
    if(oddChars > 1)
        return false;
    else
        return true;
}


int main(){
    string s;
    cout<<"Dame la palabra"<<endl;
    cin>>s;

    bool resp = esPalindromo(s);
    if(resp)
        cout<<"Si es palindromo"<<endl;
    else
        cout<<"No es palindromo"<<endl;

}