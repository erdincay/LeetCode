#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if(grid.size() == 0 || grid.front().size() == 0)
		{
			return 0;
		}

		return minPathRecursize(grid, grid.size(), grid.front().size());
	}

	int minPathRecursize(vector<vector<int>>& grid, int height, int width) {
		if(height == 1)
		{
			return accumulate(grid.back().begin(), grid.back().end(), 0);
		}

		if(width == 1)
		{
			auto sum = 0;
			for (auto& line : grid)
			{
				sum += line.back();
			}

			return sum;
		}

		auto cur = grid[grid.size() - height][grid.front().size() - width];

		return min(cur + minPathRecursize(grid, height - 1, width), cur + minPathRecursize(grid, height, width - 1));
	}
};