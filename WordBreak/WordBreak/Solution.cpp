#include "Solution.h"
#include <iostream>


int main(int argc, char* argv[])
{
	const string s = "leetcode";
	unordered_set<string> dict{ "leet", "code" };
	Solution sln;
	cout << sln.wordBreak(s, dict) << endl;
	system("PAUSE");
	return 0;
}