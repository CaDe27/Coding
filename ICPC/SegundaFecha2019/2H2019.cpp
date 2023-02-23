#include <iostream>
#include <algorithm>
using namespace std;

/*
	http://coj.uci.cu/24h/problem.xhtml?pid=4255
	Given a list of numbers, find the first positive integer that can't be 
	expressed as the sum of a subsequence of the list

	the key is to sort the list and realize that if you can expressed all numbers
	from 1 to k using the first i elements, and element i+1 > k+1, the k+1 is our
	answer
*/
int main() {
	// read elements and store them in array s, and sort s
	int n;
	cin>>n;
	int s[n];
	for(int i = 0; i < n; ++i)
		cin>>s[i];
	sort(s, s+n);
	
	// x is going to be our answer
	// sum is going to represent the sum of the first i elements of s
	long x = 0, sum;
	/*
	//if 1 is not in the list, the 1 cannot be represented as a sum from the 
	//elements of s
	*/
	if(s[0]!=1){
		x = 1;
	}
	/*
	//else we start checking if s[i+1] > sum+1 (k+1)
	//the arguments is kind of inductive
	//base case:
	//	notice that from the first element "1" we can express all numbers from 1 to 1
	//	as a sum of elements from s
	//inductive step:
	//	if we can express all numbers from 1 to k with the first i elements of s
	//	if k+1 < s[i+1] then k+1 surely cannot be expressed as we would of course 
	//					need more than the first i elements, but anything the next
	//					number that can be represented is k+s[i+1]
	//	if k+1 >= s[i+1] the we can have all numbers from k+1 to k+s[i+1]
	//					 if we want k' <= k + s[i+1], then k'>= k+1 >= s[i+1]
	//					and k' = s[i+1] + k'' with k'' <= k, and k'' can be expressed
	//					as a sum of a subsequence from the first i elements of s because
	//					of the inductive hypothesis 
	//	then we have all elements from 1 to the sum of the first i+1 elements
	//in conclusion, we just have to check is sum+1 (sum of first i-1 elements) is 
	// less then s[i+1] for all values of i
	*/
	else{
		sum = s[0];
		for(int i = 0; i < n-1; ++i){
			if (s[i+1] > sum+1) 
				x = sum+1;
			else
				sum+= s[i+1];
		}
	}
	/*
	//if it alway happen that if (s[i+1] > sum+1) then all numbers from 1 to the
	//sum of elements of s can be expressed as a sum of a subsequence and our 
	//answer will be the sum of elements plus one
	*/
	if(x == 0)
		x = sum+1;
	cout<<x<<'\n';
	return 0;
}