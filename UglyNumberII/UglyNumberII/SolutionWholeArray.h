#pragma once
#include <array>
#include <vector>

using namespace std;

struct index_val_pair
{
	int val;
	int index;

	index_val_pair(int val, int index)
		:val(val),
		index(index)
	{
	}
};

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<index_val_pair> ugly_sequence{ index_val_pair(1, 0) };

		size_t count = 0;
		while (ugly_sequence.size() < n)
		{
			bool move_iterator = false;
			int ugly_val = 0;
			tie(move_iterator, ugly_val) = nextUglyValue(ugly_sequence, count);

			ugly_sequence.push_back(index_val_pair(ugly_val, 0));
			if(move_iterator)
			{
				count++;
			}
		}

		return ugly_sequence[n - 1].val;
	}

private:
	tuple<bool, int> nextUglyValue(vector<index_val_pair> & sequence, int curIndex)
	{
		const array<size_t, 3> ugly_factors{ 2, 3, 5 };
		
		unsigned int min_val = sequence.back().val * ugly_factors.back();
		vector<int> min_indices;
		for (int index = curIndex; index < sequence.size(); ++index)
		{
			unsigned int cur_val = sequence[index].val * ugly_factors[sequence[index].index];
			if(cur_val < min_val)
			{
				min_val = cur_val;
				min_indices.clear();
				min_indices.push_back(index);
			}
			else if(cur_val == min_val)
			{
				min_indices.push_back(index);
			}
		}

		for (auto& min_index : min_indices)
		{
			sequence[min_index].index = (sequence[min_index].index + 1) % ugly_factors.size();
		}		

		return make_tuple(sequence[curIndex].index == 0, min_val);
	}
};