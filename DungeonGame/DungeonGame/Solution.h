#pragma once
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if(dungeon.size() == 0 || dungeon.front().size() == 0)
		{
			return 1;
		}

		return minReverseDP(dungeon);
	}

	int minRecursive(vector<vector<int>>& dungeon, int width, int height)
	{
		if (width == 1)
		{
			int sum = 0;
			for (vector<vector<int>>::iterator it = dungeon.begin() + dungeon.size() - height; it != dungeon.end(); ++it)
			{
				sum += it->back();
			}

			return -sum;
		}

		if(height == 1)
		{
			return -accumulate(dungeon.back().begin() + dungeon.back().size() - width, dungeon.back().end(), 0);
		}

		return min(minRecursive(dungeon, width - 1, height), minRecursive(dungeon, width, height - 1));
	}

	int minDP(vector<vector<int>>& dungeon)
	{
		vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon.front().size()));
		dp[0][0] = max(1 - dungeon[0][0], 1);

		for (int i = 0; i < dungeon.size(); ++i)
		{
			for (int j = 0; j < dungeon[i].size(); ++j)
			{
				if(i - 1 >= 0 && j - 1 >= 0)
				{
					dp[i][j] = min(max(dp[i - 1][j] - dungeon[i][j], 1), max(dp[i][j - 1] - dungeon[i][j], 1));
				}
				else if(i - 1 >= 0)
				{
					dp[i][j] = max(dp[i - 1][j] - dungeon[i][j], 1);
				}
				else if(j - 1 >= 0)
				{
					dp[i][j] =  max(dp[i][j - 1] - dungeon[i][j], 1);
				}
				
			}
		}

		return dp[dungeon.size() - 1][dungeon.front().size() - 1];
	}

	int minReverseDP(vector<vector<int> > &dungeon) 
	{
		int row = dungeon.size();
		int col = row > 0 ? dungeon[0].size() : 0;
		if (row <= 0 || col <= 0) return 0;

		//dp[r][c] = min( max( dp[r+1][c] - dungeon[r][c], 1), max( dp[r][c+1] - dungeon[r][c], 1) );
		vector<vector<int>> dp(row, vector<int>(col));

		for (int r = row - 1; r >= 0; r--) {
			for (int c = col - 1; c >= 0; c--) {

				if (r == row - 1 && c == col - 1) {
					dp[r][c] = max(1 - dungeon[r][c], 1);
				}
				else {
					int h1 = (c == col - 1) ? INT_MAX : max(dp[r][c + 1] - dungeon[r][c], 1);
					int h2 = (r == row - 1) ? INT_MAX : max(dp[r + 1][c] - dungeon[r][c], 1);

					dp[r][c] = min(h1, h2);
				}

			}
		}

		return dp[0][0];
	}
};

