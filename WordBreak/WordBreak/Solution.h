#pragma once
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> segmented(s.size(), false);

		for (int i = 0; i < s.size(); ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if(j==i)
				{
					segmented[i] = segmented[i] | wordDict.count(s.substr(0, i + 1)) > 0;
				}
				else
				{
					segmented[i] = segmented[i] | (segmented[j] && wordDict.count(s.substr(j + 1, i - j)) > 0);
				}
				
			}
		}

		return segmented.back();
	}
};
