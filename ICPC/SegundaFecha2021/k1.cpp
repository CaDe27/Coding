#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 12;

    for(int i=1;i<=n;i++){
        set<string> S;
        for(int j=1;j<i;j++){
            if(i%j == 0){
                for(int k=0;k<(1<<j);k++){
                    string s = "";
                    for(int p=0;p<j;p++){
                        if(k&(1<<p)){
                            s += '1';
                        }
                        else{
                            s += '0';
                        }
                    }
                    string w = "";
                    for(int p=0;p<i/j;p++){
                        w += s;
                    }
                    S.insert(w);
                }
            }
        }



        cout << i << " " << S.size() << "\n";

     //   for(auto u:S){
   //         cout << u << "\n";
      //  }
    }


    return 0;
}
