//Given a m x n grid filled with non - negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.

#include "Solution.h"
#include <iostream>

int main(int argc, char* argv[])
{
	vector<vector<int>> v{ {1} };
	Solution sln;
	cout << sln.minPathSum(v);
	system("PAUSE");
	return 0;
}

