#pragma once
#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		size_t zero_index = 0, none_zero_index = 0;
		while (zero_index < nums.size() && none_zero_index < nums.size())
		{
			while (nums[zero_index] == 0)
			{
				zero_index++;
			}	

			if(zero_index < nums.size())
			{
				nums[none_zero_index] = nums[zero_index];
				none_zero_index++;
			}

			zero_index++;
		}

		fill(nums.begin() + none_zero_index, nums.end(), 0);
	}
};