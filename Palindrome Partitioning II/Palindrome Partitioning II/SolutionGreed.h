class Solution {
public:
    int minCut(string s) {
        int left = subStr(s,true);
		int right = subStr(s,false);
		
		return (left < right ? left : right) - 1;
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

	string getSubStr(string strSrc, int len, bool bLeft) {
		if(bLeft) {
			return strSrc.substr(0,len);
		}
		else {
			return strSrc.substr(strSrc.length() - len, len);
		}
	}

	string getLeftStr(string strSrc, int len, bool bLeft) {
		if(bLeft) {
			return strSrc.substr(len);
		}
		else {
			return strSrc.substr(0,strSrc.length() - len);
		}
	}

    int subStr(string strSrc, bool bLeft) {
		for(int len = strSrc.length(); len > 0; len--) {
			string sub = getSubStr(strSrc,len,bLeft);
			if(checkPalindrome(sub)) {
				if(len < strSrc.length()) {
					int ret = subStr(getLeftStr(strSrc,len,bLeft),bLeft);
					if(ret > 0) {
						return ret + 1;
					}
				}
				else {
					return 1;
				}
			}
		}

		return 0;
    }
};