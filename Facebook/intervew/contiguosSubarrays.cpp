#include <iostream>
#include <stack>
#include <vector>

// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

void insertToStack(stack<pair<int,int> > &s, int element, int index, vector<int> &limitArray, bool leftLimit){
  int indexTop;  
  while(!s.empty() && s.top().first < element){
      indexTop = s.top().second;
      limitArray[indexTop] = index + (leftLimit? 1 : -1);
      s.pop();
   }
   s.push(make_pair(element, index));
}

vector <int> CountSubarrays(vector <int> arr) {
  int size = arr.size();
  vector<int> leftLimit(size), rightLimit(size);
  stack<pair<int,int> > s;
  
  //we first compute the rightLimit of each element
  
  //we insert the first element
  //for all the others, we pop elements if the numbers is bigger
  //then I insert the number
  for(int i = 0; i < size; ++i)
    insertToStack(s, arr[i], i, rightLimit, false);
  
  //we are missing numbers who reached the end
  int MAX = 1000000000;
  insertToStack(s, MAX + 1, size, rightLimit, false);
  s.pop();
  
  
  //we now compute the leftLimit of each element
  for(int i = size-1; i > -1; --i)
    insertToStack(s, arr[i], i, leftLimit, true);
  insertToStack(s, MAX + 1, -1, leftLimit, true);
  
  vector<int> resp;
  resp.resize(size);
  for(int i = 0; i < size; ++i)
    resp[i] = rightLimit[i] - leftLimit[i] + 1; 
  return resp;
}


// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size(); 
  int output_size = output.size(); 
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  if (result) {
    cout << "Test #" << test_case_number << "\n";
  }
  else {
    cout << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {
    int t1[]={3, 4, 1, 6, 2};
  vector <int> test_1(t1, t1+5);
    int e1[]= {1, 3, 1, 5, 1};
  vector <int> expected_1 (e1, e1+5);

  vector <int> output_1 = CountSubarrays(test_1);
  check(expected_1, output_1);

    /*
  vector <int> test_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{1, 2, 6, 1, 3, 1};
  vector <int> output_2 = CountSubarrays(test_2);
  check(expected_2, output_2);
*/
  // Add your own test cases here
  
}