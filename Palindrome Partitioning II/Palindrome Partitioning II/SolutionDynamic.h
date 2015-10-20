class Solution {
public:
	int minCut(string s) {
		return minCuts(s);
	}

private:
	int minCuts(string & s) {
		//res[] is for minimal cut DP
		vector<int>res(s.size(), 0);
		//mp[][] is for palindrome checking DP
		bool ** mp = new bool*[s.size()];
		for (int i = 0; i < s.size();i++)
		{
			mp[i] = new bool[s.size()];
		}

		//construct the pailndrome checking matrix
		//  1) matrix[i][j] = true;     if (i==j)                   -- only one char
		//  2) matrix[i][j] = true;     if (i==j+1) && s[i]==s[j]   -- only two chars
		//  3) matrix[i][j] = matrix[i+1][j-1];   if s[i]==s[j]     -- more than two chars
		//
		//note:  1) and 2) can be combined together
		for (int i = s.size() - 1; i >= 0; i--) {
			for (int j = i; j<s.size(); j++) {
				if ((s[i] == s[j]) && (j - i<2 || mp[i + 1][j - 1])) {
					mp[i][j] = true;
				}
				else {
					mp[i][j] = false;
				}
			}
		}
		//minimal cut dp
		for (int i = 0; i<s.size(); i++) {
			//if s[0..i] is palindrome, then no need to cut
			if (mp[0][i] == true) {
				res[i] = 0;
			}
			else {
				// if s[0..i] isn't palindrome 
				// then, for each 0 to i, find a "j" which meets two conditions:
				//    a) s[j+1..i] are palindrome.
				//    b) res[j]+1 is minimal   
				int ms = s.size();
				for (int j = 0; j<i; j++) {
					if (mp[j + 1][i] && ms>res[j] + 1) {
						ms = res[j] + 1;
					}
				}
				res[i] = ms;
			}
		}

		for (int i = 0; i < s.size(); i++)
		{
			delete[] mp[i];
		}
		delete[] mp;

		return res[s.size() - 1];
	}
};