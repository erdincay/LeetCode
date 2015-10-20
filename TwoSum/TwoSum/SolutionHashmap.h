#pragma once
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		unordered_map<int, int> num_index_map;
		for (auto i = 0; i < nums.size(); i++)
		{
			auto findRet = num_index_map.find(nums[i]);
			if(findRet != num_index_map.end())
			{
				return vector<int>{findRet->second + 1, i + 1};
			}

			num_index_map[target - nums[i]] = i;
		}

		return vector<int>();
	}
};
