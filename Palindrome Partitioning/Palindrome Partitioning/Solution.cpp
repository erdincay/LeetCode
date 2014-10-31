//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return all possible palindrome partitioning of s.
//For example, given s = "aab",
//Return
//  [
//	["aa", "b"],
//	["a", "a", "b"]
//  ]

#include <string>
#include <iostream>
#include<vector>

using namespace std;

#include "Solution.h"

int main(int argc, char* argv[])
{
	Solution s;

	vector<vector<string>> ret = s.partition("abbab");
	for(vector<vector<string>>::iterator line = ret.begin(); line != ret.end(); line++) {
		cout<<"[ ";
		for(vector<string>::iterator it = (*line).begin(); it != (*line).end(); it++) {
			cout<<"'"<< *it <<"', ";
		}
		cout<<" ]"<<endl;
	}

	system("PAUSE");

	return 0;
}