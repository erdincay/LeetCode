#pragma once
class Solution
{
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.size() <= 0)
		{
			return false;
		}
		else
		{
			auto sum = 0;
			for (auto const & row : matrix)
			{
				sum += row.size();
			}

			if (sum <= 0)
			{
				return false;
			}
		}

		if (target < matrix.front().front() || target > matrix.back().back())
		{
			return false;
		}


		return iterMatrix(matrix, target, make_pair<int, int>(0, 0), make_pair<int, int>(matrix.size() - 1, matrix.back().size() - 1));
	}

private:
	bool iterMatrix(const vector<vector<int> > &matrix, int target, pair<int, int> startIndex, pair<int, int> endIndex)
	{
		auto rowIndex = endIndex.first - startIndex.first;

		if (rowIndex <= 0)
		{
			return binarySearch(matrix, target, startIndex.first, startIndex.second, endIndex.second);
		}
		else
		{
			rowIndex = startIndex.first + rowIndex / 2;

			if (target < matrix[rowIndex].front())
			{
				return iterMatrix(matrix, target, startIndex, make_pair<int, int>(rowIndex - 1, matrix[rowIndex - 1].size() - 1));
			}
			else if (target > matrix[rowIndex].back())
			{
				return iterMatrix(matrix, target, make_pair<int, int>(rowIndex + 1, 0), endIndex);
			}
			else
			{
				return binarySearch(matrix, target, rowIndex, 0, matrix[rowIndex].size() - 1);
			}
		}
	}

	bool binarySearch(const vector<vector<int> > &matrix, int target, int rowIndex, int startIndex, int endIndex)
	{
		auto mIndex = endIndex - startIndex;

		if (mIndex < 0)
		{
			return false;
		}
		else if (mIndex == 0)
		{
			return target == matrix[rowIndex][startIndex];
		}

		mIndex = startIndex + mIndex / 2;
		auto mVal = matrix[rowIndex][mIndex];
		if (mVal == target)
		{
			return true;
		}
		else if (target < mVal)
		{
			return binarySearch(matrix, target, rowIndex, startIndex, mIndex - 1);
		}
		else
		{
			return binarySearch(matrix, target, rowIndex, mIndex + 1, endIndex);
		}
	}
};

