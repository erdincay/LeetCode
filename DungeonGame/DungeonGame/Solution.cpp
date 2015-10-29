#include "Solution.h"
#include <iostream>


int main(int argc, char* argv[])
{
	Solution sln;
	vector<vector<int>> dungeon{ {0, 0} };
	cout << sln.calculateMinimumHP(dungeon) << endl;
	system("PAUSE");
	return 0;
}

