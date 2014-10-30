class Solution {
public:
	int minCut(string s) {
		return subStr(s) - 1;
	}

private:
	bool checkPalindrome(string strPd) {
		int strLen = strPd.length();
		if(strLen == 1) {
			return true;
		}

		int mid = (strLen / 2) + (strLen % 2);

		int i =0;
		for(; i<mid; i++)
		{
			if(strPd.at(i) != strPd.at(strLen - 1 -i)) {
				break;
			}
		}

		return i == mid;
	}

	int subStr(string strSrc) {
		
		list<string> strList;
		for (int len=0; len<strSrc.size(); len++)
		{
			strList.push_back(strSrc.substr(len,1));
		}

		for (int len=2; len<=strSrc.size(); len++)
		{
			for (list<string>::iterator it = strList.begin(); it != strList.end(); it++)
			{
				string newStr = "";
				list<string>::iterator itt = it;
				for (int j=0; j<len; j++)
				{
					if (itt != strList.end())
					{
						newStr += *itt;
						itt++;
					}
				}

				if (checkPalindrome(newStr))
				{
					strList.erase(it,itt);
					strList.insert(strList.begin(),newStr);
				}
			}
		}

		return strList.size();
	}
};