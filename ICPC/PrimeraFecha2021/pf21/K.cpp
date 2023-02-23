#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(){
    string s;
    cin>>s;
    s = '0' + s;
    int size = s.size();
    vector<int> resp;

    if( (s[size - 1]-'0') % 2 == 0)
        resp.push_back(2);
    
    int suma = 0;
    for(char c : s)
        suma = (suma + c-'0')%3;
    if(suma % 3 == 0)
        resp.push_back(3);

    if( (10*(s[size-2]-'0') + (s[size-1]-'0')) % 4 ==0)
        resp.push_back(4);

    if( (s[size-1]-'0') % 5 == 0)
        resp.push_back(5);
    
    if( (suma % 3 ==0) && (s[size - 1] - '0') % 2 == 0)
        resp.push_back(6);

    if(resp.size() == 0){
        cout<<"-1\n";
    }else{
        cout<<resp[0];
        for(int i = 1; i < resp.size(); ++i)
            cout<<" "<<resp[i];
        cout<<"\n";
    }
    
    
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    for(int i = 0; i < t; ++i)
        solve();
    return 0; 
}