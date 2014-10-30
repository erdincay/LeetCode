class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> out;
		subStr(0,s,out);
        return out;
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

    int subStr(int minSubLen, string strSrc, vector<vector <string>> & out) {
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
				vector<vector<string>> strLeft;
				if(subStr(0,strSrc.substr(plrLen),strLeft) > 0) {
					for (vector<vector<string>>::iterator line = strLeft.begin(); line != strLeft.end(); line++) {
						(*line).insert((*line).begin(), strPlr);
						out.push_back(*line);
					}
				}

				vector<vector<string>> strLonger;
				if(subStr(plrLen, strSrc, strLonger) > 0) {
					for (vector<vector<string>>::iterator line = strLonger.begin(); line != strLonger.end(); line++) {
						out.push_back(*line);
					}
				}
			}
			else {
				vector<string> vTmp;
				vTmp.push_back(strPlr);
				out.push_back(vTmp);
			}
		}

		return plrLen;
    }
};