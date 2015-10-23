#pragma once
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<vector<string>> segmented(s.size());

		for (int i = 0; i < s.size(); ++i)
		{
			auto curString = s.substr(0, i + 1);
			if (wordDict.find(curString) != wordDict.end())
			{
				i + 1 == s.size() ? segmented[i].push_back(curString) : segmented[i].push_back(curString + " ");
			}

			for (int j = 0; j < i; ++j)
			{				
				auto segString = s.substr(j + 1, i - j);
				if(segmented[j].size() > 0 && wordDict.find(segString) != wordDict.end())
				{
					for (auto& subStrJ : segmented[j])
					{
						auto newStr = i + 1 == s.size() ? subStrJ + segString : subStrJ + segString + " ";
						segmented[i].push_back(newStr);
					}
				}				
			}
		}

		return segmented.back();
	}
};
