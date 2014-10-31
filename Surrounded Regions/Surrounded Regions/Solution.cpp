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

#include "Solution.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

void print_board(vector<vector<char>>& board)
{
	for (vector<vector<char>>::iterator line = board.begin(); line != board.end(); ++line)
	{
		for (vector<char>::iterator row = (*line).begin(); row != (*line).end(); ++row)
		{
			cout << (*row) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

shared_ptr<vector<vector<char>>> InitBoard(string filename)
{
	ifstream ifs(filename, ifstream::in);
	string str((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
	vector<string> SplitVec;
	split(SplitVec, str, boost::is_any_of(","));


	auto board = make_shared<vector<vector<char>>>();
	for (auto const & strLine : SplitVec)
	{
		vector<char> line;
		for (auto const & ch : strLine)
		{
			if (ch == 'X' || ch == 'O')
			{
				line.push_back(ch);
			}
		}
		board->push_back(line);
	}

	return board;
}

int main(int argc, char* argv[])
{
	auto char_board = InitBoard("test.txt");

	print_board(*char_board);
	Solution s;
	s.solve(*char_board);
	print_board(*char_board);

	system("PAUSE");

	return 0;
}