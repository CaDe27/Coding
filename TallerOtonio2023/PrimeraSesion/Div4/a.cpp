#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int testCases;
    cin>>testCases;

    for(int t = 0; t<testCases; ++t){
        int digits[3];
        for(int i = 0; i < 3; ++i){
            cin>>digits[i];
        }
        sort(digits, digits+3);

        if(digits[2] + digits[1] >= 10)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}