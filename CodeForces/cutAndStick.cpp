/*
    https://codeforces.com/contest/1514/problem/D
    If M is the frequency of the most frquent value in the range of size n,
    the answer of the query is  2M - n

    my key idea was counting the number of elements you could have of some number is you had k odd partitions
    then you arrive to having M = (n+k)/2
    so you need 2M - n  odd partitions 
    but 2M - n has the same parity as n, so you need (2M-n)*odd elements, and you have those 

    we only care about the most frequent subvalue if it has more than  (n+1)/2 occurences, 
    then we can construct a ST, since it has to occur at least (n+1)/4 in one of the halves. 

    the sg tree will check the most frequent values of their children and see which one of these occurs more 
    in the segment (the st returns the most frequent value if it occurs at least half of the time)

    we can know the occurences of an element in a range [a,b] in log(n)
    having the indexes of occurence of the element in increasing order
    and doing upper_bound(b) - lower_bound(a)
*/

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define loop(i, a, b) for(int i = a; i < b; ++i)
const int maxN = 3*1e5 + 5;
int arr[maxN], n;
vector<int> indxesOfOccurence[maxN];

int frequencyInRange(int value, int a, int b){
    vector<int> *v = &(indxesOfOccurence[value]);
    return upper_bound(v->begin(),v->end(), b) - lower_bound(v->begin(), v->end(), a);
}

int l[4*maxN], r[4*maxN], mostFrequentValue[4*maxN]; 
    void init(int i, int a, int b){
        l[i] = a;
        r[i] = b;
        if(a != b){
            int m = (a+b)/2;
            init(2*i, a, m);
            init(2*i+1, m+1, b);
            int contL, contR;
            contL = frequencyInRange(mostFrequentValue[2*i], a, b);
            contR = frequencyInRange(mostFrequentValue[2*i+1], a, b);
            mostFrequentValue[i] = contL > contR? mostFrequentValue[2*i] : mostFrequentValue[2*i+1];
        }
        else
            mostFrequentValue[i] = arr[a];
    }

    void SegmentTree(){
        init(1, 0, n-1);
    }

    int query(int i, int a, int b){
        if(b < l[i] || r[i] < a)
            return 0;

        if(a <= l[i] && r[i] <= b)
            return mostFrequentValue[i];

        int leftQ =  query(2*i, a, b);
        int rightQ = query(2*i+1, a, b);

        int contL, contR;
            contL = frequencyInRange(leftQ, a, b);
            contR = frequencyInRange(rightQ, a, b);
        return contL > contR? leftQ : rightQ;
    }

    int query(int a, int b){return query(1, a, b);}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	int q;
    cin>>n>>q; 
    loop(i, 0, n){
        cin>>arr[i];
        indxesOfOccurence[arr[i]].push_back(i);
    }
    
    SegmentTree();
    int l,r, mostFrequent, freq, resp, size;
	for(int i = 0; i < q; ++i){
        cin>>l>>r;
        --l; --r;
        size = r-l + 1;
        mostFrequent = query(l, r);
        freq = frequencyInRange(mostFrequent, l, r);
        resp = max(1, 2*freq - size);
        cout<<resp<<"\n";
    }
	return 0;
}