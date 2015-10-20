// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//#include "SolutionGreed.h"
//#include "SolutionMemorey.h"
#include "SolutionDynamic.h"



int main(int argc, char* argv[])
{
	Solution s;

	cout<<s.minCut("cdd");
	cout<<endl;

	system("PAUSE");

	return 0;
}



