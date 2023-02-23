#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector <int> findMaxProduct(vector <int> arr) {
  // Write your code here
  priority_queue<int, vector<int>, greater<int> > heap;
  
  int size = arr.size();
  vector<int> output(size);
  int64_t product = 1;
  for(int i = 0; i < size; ++i){
    product *= arr[i];
    heap.push(arr[i]);
    
    if(heap.size() >= 3){
      while(heap.size() > 3){
        product /= heap.top();
        heap.pop();
      }
      output[i] = product;
    }
    else{
      output[i] = -1;
    }
  }
  return output;
}

int main(){
    vector<int> input;
    for(int i = 0; i < 6;++i)
        input.push_back(i+1);
    
    vector<int> output = findMaxProduct(input);
    for(int i = 0; i < output.size() ;++i){
        cout<<output[i]<<" ";
    }
    cout<<endl;
}