#include <iostream>
#include <string>

#define loop(i, a, b) for(int i = a; i < b; ++i)
using namespace std;


bool isVowel(char c){
    return c == 'A' || c=='E' || c == 'I' || c=='O' || c == 'U';
}

bool sameType(char c, char a){
    return (isVowel(c) && isVowel(a)) || (!isVowel(c) && !isVowel(a));
}  

int cost(string &s){
    //we check the min for each letter
    int minCost = 200, testCost;
    char base;
    loop(i, 0, 'Z'-'A' +1){
        testCost = 0;
        base = char('A' + i);
        for(char c : s){
            if(base != c)
                testCost += sameType(base, c)? 2:1;
        }
        minCost = min(minCost, testCost);
    }
    return minCost;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    string s;
    loop(i, 0, t){
        cin>>s;
        cout<<"Case #"<<(i+1)<<": "<<cost(s)<<"\n";    
    }
    return 0;
}