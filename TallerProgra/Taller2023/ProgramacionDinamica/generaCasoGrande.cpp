#include <iostream>
using namespace std;

int main(){
    int n = 1000;
    cout<<n<<endl;
    for(int i = 0; i < n; i++){
        cout<<1<<(i < n? " ":"\n");
    }
}