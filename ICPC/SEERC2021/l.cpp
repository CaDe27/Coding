/*
    answer is always at most 2
    iterate over the string until one letter has n occurrences
    then complete the others

    then we need to check for 0 and 1
    checking for cero is trivial 
    checking for 1 can be done with two pointer
*/
#include <iostream>
#include <string>
#include <unordered_map>
#define loop(i, a, b) for(int i = a; i < b; ++i)
using namespace std; 


int n; 
unordered_map<char, int> bucket;
string s, alphabet = "ABC"; 

bool oneMover(){
    char m, other1, other2;
    if(bucket['A'] < n){
        m = 'A';
        other1 = 'B';
        other2 = 'C';
    }
    else if(bucket['B'] < n)
    {
        m = 'B';
        other1 = 'A';
        other2 = 'C';
    }
    else{
        m = 'C'; 
        other1 = 'B';
        other2 = 'A';
    }
    
    unordered_map<char, int> have, limit;
    int izq = 0, der = 0;
    loop(i, 0, 3){
        char c = alphabet[i];
        have[c] = 0;
        if(c != m)
            limit[c] = bucket[c] - n;
    }
    ++have[s[0]];
    while(der < 3*n-1 && (limit[other1] != have[other1] || limit[other2] != have[other2]) ){
        if(limit[other1] >= have[other1] && limit[other2] >= have[other2]){
            ++have[s[++der]];
        }
        else{
            --have[s[izq++]];
        }
    }
    if(limit[other1] == have[other1] && limit[other2] == have[other2]){
        ++izq; ++der;
        cout<<"1\n";
        cout<<izq<<" "<<der<<" "<<m<<"\n";
        return true;
    }
    else
        return false;
}

void twoMover(){
    //I check until one of the letters is full and the I complete the others
    cout<<"2\n";
    bucket['A'] = bucket['B'] = bucket['C'] = 0;
    bool someOneComplete = false;
    int it = 0;
    while(!someOneComplete){
        ++bucket[s[it]];
        if(bucket[s[it]] == n)
            someOneComplete = true;
        ++it;
    }
    //I complete the other characters
    loop(i, 0, alphabet.size()){
        if(bucket[alphabet[i]] < n){
            cout<<it+1<<" "<<it + n - bucket[alphabet[i]]<<" "<<alphabet[i]<<"\n";
            it = it + n - bucket[alphabet[i]];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>s;
    bucket['A'] = bucket['B'] = bucket['C'] = 0;
    loop(i, 0, s.size())
        ++bucket[s[i]];
    int lessThanN = 0;
    loop(i, 0, 3)
        lessThanN += bucket[alphabet[i]] < n;
    
    if(lessThanN == 0)
        cout<<"0\n";
    else if(lessThanN == 1){
        if(!oneMover())
            twoMover();
    }
    else
        twoMover();
    return 0; 
}



