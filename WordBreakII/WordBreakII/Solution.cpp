#include "Solution.h"
#include <iostream>

int main(int argc, char* argv[])
{
	const string s = "catsanddog";
	unordered_set<string> dict{ "cat", "cats", "and", "sand", "dog" };
	Solution sln;
	for (auto soluntion : sln.wordBreak(s, dict))
	{
		cout << soluntion << endl;
	}
	system("PAUSE");
	return 0;
}