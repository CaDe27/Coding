#include<iostream>
using namespace std;

void solveCase(){
    int n; 
    cin>>n;
    int idResp = -1, ar, br;
    int ai, bi;
    for(int i = 1; i <= n; ++i){
        cin>>ai>>bi;
        if(ai > 10) 
            continue;

        if(idResp == -1 || bi > br){
            idResp = i;
            ar = ai;
            br = bi;
        }
    }
    cout<<idResp<<"\n";
}

int main(){
    int t; 
    cin>>t;
    for(int testCases = 0; testCases < t; ++testCases){
        solveCase();
    }
    return 0;
}