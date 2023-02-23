#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stack>

using namespace std;

typedef pair<int,double> pid;

double radioChoco(const pid &g, const pid &c){
    double h = g.first - c.first;
    return min( h*h/(4*c.second), g.second);
}


int main(){
    int n; 
    scanf("%d", &n);

    stack<pid> g;
    pid a;
    for(int i = 0; i < n; ++i){
        scanf("%d %lf", &a.first, &a.second);
        while( !g.empty() && (a.second = radioChoco(a, g.top())) >= g.top().second )
            g.pop();
        g.push(a);
        printf("%.6lf\n", a.second);
    }
    return 0;

}