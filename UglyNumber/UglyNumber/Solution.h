#pragma once

class Solution {

public:
	bool isUgly(int num) {
		if (num == 1)
		{
			return true;
		}

		num = reduce(num, 2);
		num = reduce(num, 3);
		num = reduce(num, 5);

		return num == 1;
	}


private:
	int reduce(int num, int div)
	{
		if (num == 0)
		{
			return num;
		}

		while (num % div == 0)
		{
			num /= div;
		}

		return num;
	}
};