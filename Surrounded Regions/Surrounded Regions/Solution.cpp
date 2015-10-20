#include <filesystem>
#include <iostream>

//Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//For example,
// X X X X
// X O O X
// X X O X
// X O X X
//After running your function, the board should be :
// X X X X
// X X X X
// X X X X
// X O X X

const char X = 'X';
const char O = 'O';
const char N = 'N';

#include <vector>
#include "SolutionQueue.h"

int main(int argc, char* argv[])
{
	Solution sln;
	auto board = std::vector<std::vector<char>>{ { O,O,O, }, { O, O, O, }, { O, O, O, } };

	sln.print(board);
	sln.solve(board);
	sln.print(board);

	system("PAUSE");

	return 0;
}