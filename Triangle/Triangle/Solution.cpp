#include "Solution.h"
#include <iostream>


int main(int argc, char* argv[])
{
	vector<vector<int>> triangle{ {2}, { 3, 4 }, { 6,5,7 }, { 4,1,8,3 }};
	Solution sln;
	cout << sln.minimumTotal(triangle) << endl;
	system("PAUSE");
	return 0;
}

