class Solution {
public:
	int minCut(string s) {
		vector<int> out;
		subStr(0,s,out);

		int min = s.size();
		for (vector<int>::iterator line = out.begin(); line != out.end(); line++) {
			if(*line < min) {
				min = *line;
			}
		}

		return min - 1;
	}

private:
	map<string, bool> mem_;

private:
	bool checkPalindrome(string strPd) {
		int strLen = strPd.length();
		if(strLen == 1) {
			return true;
		}

		try {
			bool ret = mem_.at(strPd);
			return ret;
		}
		catch (const std::out_of_range& oor) {
			//std::cerr << "Out of Range error: " << oor.what() << '\n';
		}

		int mid = (strLen / 2) + (strLen % 2);

		int i =0;
		for(; i<mid; i++)
		{
			if(strPd.at(i) != strPd.at(strLen - 1 -i)) {
				break;
			}
		}

		if(i == mid) {
			mem_[strPd] = true;
			return true;
		}
		else {
			mem_[strPd] = false;
			return false;
		}
	}

	int subStr(int minSubLen, string strSrc, vector <int> & countSub) {
		int strLen = strSrc.length();
		int plrLen = 0;
		string strPlr = "";

		for(int len = minSubLen + 1; len <= strLen; len++) {
			if(checkPalindrome(strSrc.substr(0,len))) {
				strPlr = strSrc.substr(0,len);
				plrLen = len;
				break;
			}
		}

		if (plrLen > 0)	{
			if(strLen - plrLen > 0) {
				vector<int> countLeft;
				if(subStr(0,strSrc.substr(plrLen),countLeft) > 0) {
					for (vector<int>::iterator line = countLeft.begin(); line != countLeft.end(); line++) {
						countSub.push_back(*line + 1);
					}
				}

				vector<int> countLonger;
				if(subStr(plrLen, strSrc, countLonger) > 0) {
					for (vector<int>::iterator line = countLonger.begin(); line != countLonger.end(); line++) {
						countSub.push_back(*line);
					}
				}
			}
			else {
				countSub.push_back(1);
			}
		}

		return plrLen;
	}
};