#pragma once

class Solution {
public:
	int uniquePaths(int m, int n) {
		return findPaths(m, n);
	}

private:
	int findPaths(int m, int n)
	{
		if(m == 1 || n == 1)
		{
			return 1;
		}

		return findPaths(m - 1, n) + findPaths(m, n - 1);
	}
};