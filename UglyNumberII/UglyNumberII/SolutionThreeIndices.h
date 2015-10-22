#pragma once
#include <vector>
#include <algorithm>

using namespace std;

struct factor_index_pair
{
	size_t factor;
	size_t index;
	int cur_val;

	explicit factor_index_pair(size_t fct)
		:factor(fct),
		index(0)
	{
	}
};

class Solution {
public:
	int min(int a, int b) {
		return a < b ? a : b;
	}

	int min(int a, int b, int c) {
		return min(min(a, b), c);
	}

	int nthUglyNumber(int n)
	{
		vector<int> sequence{ 1 };
		vector<factor_index_pair> ugly_vector{ factor_index_pair(2), factor_index_pair(3), factor_index_pair(5) };

		while (sequence.size() < n)
		{
			auto min_iterator = min_element(ugly_vector.begin(), ugly_vector.end(),
				[&sequence](factor_index_pair& left, factor_index_pair& right)
			{
				left.cur_val = sequence[left.index] * left.factor;
				right.cur_val = sequence[right.index] * right.factor;
				return left.cur_val < right.cur_val;
			});

			sequence.push_back(min_iterator->cur_val);
			for (auto& ugly : ugly_vector)
			{
				if(ugly.cur_val == min_iterator->cur_val)
				{
					ugly.index++;
				}
			}
		}

		
		return sequence.back();
	}

	int nthUglyNumber02(int n) {

		static int i = 0;
		static int j = 0;
		static int k = 0;
		static vector<int> v{ 1 };

		if (v.size() >= n) return v[n - 1];

		while (v.size() < n) {
			int next = min(v[i] * 2, v[j] * 3, v[k] * 5);
			if (next == v[i] * 2) i++;
			if (next == v[j] * 3) j++;
			if (next == v[k] * 5) k++;
			v.push_back(next);
		}

		return v.back();
	}

};