//Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
//For example,
//Consider the following matrix :
//[
//	[1, 3, 5, 7],
//	[10, 11, 16, 20],
//	[23, 30, 34, 50]
//]

#include <string>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

#include "Solution.h"

int main(int argc, char* argv[])
{
	Solution s;

	vector<int> r1;	
	r1.push_back(-10);
	r1.push_back(-7);
	r1.push_back(5);
//	r1.push_back(7);
//	r1.push_back(-4);
//	r1.push_back(-2);

	vector<int> r2;
	r2.push_back(10);
	r2.push_back(11);
	r2.push_back(16);
	r2.push_back(20);
//	r2.push_back(-1);
//	r2.push_back(1);

	vector<int> r3;
	r3.push_back(22);
	r3.push_back(30);
	r3.push_back(34);
	r3.push_back(50);
//	r3.push_back(5);
//	r3.push_back(7);

	vector<int> r4;
	r4.push_back(10);
	r4.push_back(10);
	r4.push_back(12);
	r4.push_back(12);
	r4.push_back(12);
	r4.push_back(12);

	vector<int> r5;
	r5.push_back(15);
	r5.push_back(16);
	r5.push_back(18);
	r5.push_back(18);
	r5.push_back(20);
	r5.push_back(20);

	vector<vector<int>> m;
	m.push_back(r1);
//	m.push_back(r2);
//	m.push_back(r3);
//	m.push_back(r4);
//	m.push_back(r5);

	cout << s.searchMatrix(m, -10) << endl;

	return 0;
}