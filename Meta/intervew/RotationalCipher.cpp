#include <iostream>
#include <iterator>
using namespace std;

bool isNumber(char c){
    return '0'<=c && c<='9';
}

bool isUpperCase(char c){
    return 'A'<=c && c <= 'Z';
}

bool isLowerCase(char c){
    return 'a'<=c && c <='z';
}

string rotationalCipher(string input, int rotationFactor) {
  // Write your code here
  string :: iterator it;
  string output = input;
  
  string lowerCaseLetters, upperCaseLetters, numbers;
  upperCaseLetters.resize('Z'-'A' + 1);
  lowerCaseLetters.resize('z'-'a' + 1);
  numbers.resize('9' - '0' + 1);
  for(int i = 0; i <='Z'-'A' + 1; ++c) lowerCaseLetters[i]

  
  for(it = input.begin(); it != input.end(); ++it){
      
  }
  
  return "";
}