#pragma once
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {

		return s1.size() == s2.size() && s1.size() != 0 && ListScrambles(s1).count(s2) > 0;
	}

private:
	unordered_set<string> ListScrambles(string s) {
		vector<vector<unordered_set<string>>> scrambles(s.size() + 1, vector<unordered_set<string>>(s.size()));

		// substr.len = 0, ignore just for readable code
		// substr.len = 1
		for (int pos = 0; pos < s.size(); ++pos)
		{
			scrambles[1][pos].insert(s.substr(pos, 1));
		}

		for (int len = 2; len <= s.size(); ++len)
		{
			for (int pos = 0; pos + len - 1 < s.size(); ++pos)
			{
				for (int j = pos; j - pos < len - 1; ++j)
				{
					auto leftLen = j - pos + 1;
					auto rightLen = len - (j - pos + 1);
					for (auto left : scrambles[leftLen][pos])
					{
						for (auto& right : scrambles[rightLen][j + 1])
						{
							scrambles[len][pos].insert(left + right);
							scrambles[len][pos].insert(right + left);
						}
					}

				}
			}
		}

		return scrambles.back().front();
	}

	bool isScramble_recursion(string s1, string s2) {

		if (s1.size() != s2.size() || s1.size() == 0 || s2.size() == 0) {
			return false;
		}
		if (s1 == s2) {
			return true;
		}
		string ss1 = s1;
		string ss2 = s2;
		sort(ss1.begin(), ss1.end());
		sort(ss2.begin(), ss2.end());
		if (ss1 != ss2) {
			return false;
		}

		for (int i = 1; i<s1.size(); i++) {
			if (isScramble_recursion(s1.substr(0, i), s2.substr(0, i)) &&
				isScramble_recursion(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i))) {
				return true;
			}
			if (isScramble_recursion(s1.substr(0, i), s2.substr(s2.size() - i, i)) &&
				isScramble_recursion(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i))) {
				return true;
			}
		}

		return false;
	}
};

