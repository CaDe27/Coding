#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string p;
    int s;
    cin>>s>>p;
	int memo2[s], memo3[s], memo1[s];
	auto m1 = &memo1;
    auto m2 = &memo2;
    auto m3 = &memo3;
	decltype(m1) aux;
	
	fill(memo3, memo3+s, 0);
	fill(memo2, memo2+s, 0);
	
    for(int l = 2; l <= s; ++l){
        for(int i = 0; i <= s-l; ++i){
            if(p[i] == p[i+l-1])
                (*m1)[i] = (*m3)[i+1];
            else
                (*m1)[i] = 1+min((*m2)[i], (*m2)[i+1]);
        }
        aux = m3;
        m3 = m2;
        m2 = m1;
        m1 = aux;
    }
    
    cout<<(*m2)[0]<<'\n';
}