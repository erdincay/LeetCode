#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		auto copy = nums;
		vector<bool> retrieved(nums.size(), false);

		std::sort(nums.begin(), nums.end());

		for (int left = 0, right = nums.size() - 1; left < right;)
		{
			auto sum = nums[left] + nums[right];
			if(sum == target)
			{
				auto posL = findElem(copy, retrieved, nums[left]);
				auto posR = findElem(copy, retrieved, nums[right]);
				return posL < posR ? vector<int>{posL, posR} : vector<int>{ posR, posL };
			}

			sum > target ? right-- : left++;
		}

		return vector<int>();
	}

private:
	int findElem(vector<int>& nums, vector<bool>& retrieved, int target)
	{
		for (int index = 0; index < nums.size(); ++index)
		{
			if(nums[index] == target && !retrieved[index])
			{
				retrieved[index] = true;
				return index + 1;
			}
		}

		return -1;
	}
};