#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if(triangle.size() == 0)
		{
			return 0;
		}

		vector<vector<int>> path(triangle.size());

		path[0] = triangle.front();

		for (int i = 1; i < triangle.size(); ++i)
		{
			int left = numeric_limits<int>::max();
			int right = numeric_limits<int>::max();
			for (int j = 0; j < triangle[i].size(); ++j)
			{
				if(j - 1 >= 0)
				{
					left = path[i - 1][j - 1];
				}

				if(j < path[i-1].size())
				{
					right = path[i - 1][j];
				}

				path[i].push_back(min(left, right) + triangle[i][j]);
			}
		}

		auto min = min_element(path.back().begin(), path.back().end());

		return *min;
	}

};