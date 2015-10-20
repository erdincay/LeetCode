#pragma once
#include <queue>

using namespace std;

struct coordinate
{
	int row_;
	int col_;

	coordinate(int row, int col)
	{
		row_ = row;
		col_ = col;
	}
};

class Solution 
{
public:
	void solve(vector<vector<char>>& board) 
	{
		if(board.size() <= 0 || board.front().size() <= 0)
		{
			return;
		}

		auto rowSize = board.size();
		auto colSize = board.front().size();

		queue<coordinate> aliveQueue;

		const char targetChar = O;

		// left & right edge
		for (auto rowIndex = 0; rowIndex < rowSize; ++rowIndex)
		{
			auto colIndex = 0;
			if(board[rowIndex][colIndex] == targetChar)
			{
				board[rowIndex][colIndex] = N;
				aliveQueue.push(coordinate(rowIndex, colIndex));
			}

			if(colSize > 1)
			{
				colIndex = colSize - 1;
				if (board[rowIndex][colIndex] == targetChar)
				{
					board[rowIndex][colIndex] = N;
					aliveQueue.push(coordinate(rowIndex, colIndex));
				}
			}
		}

		// top & bottom edge
		for (int colIndex = 0; colIndex < colSize; ++colIndex)
		{
			auto rowIndex = 0;
			if (board[rowIndex][colIndex] == targetChar)
			{
				board[rowIndex][colIndex] = N;
				aliveQueue.push(coordinate(rowIndex, colIndex));
			}

			if(rowSize > 1)
			{
				rowIndex = rowSize - 1;
				if (board[rowIndex][colIndex] == targetChar)
				{
					board[rowIndex][colIndex] = N;
					aliveQueue.push(coordinate(rowIndex, colIndex));
				}
			}
		}

		while(!aliveQueue.empty())
		{
			auto node = aliveQueue.front();
			aliveQueue.pop();

			// up
			if(node.row_ - 1 > 0 && board[node.row_ - 1][node.col_] == targetChar)
			{
				board[node.row_ - 1][node.col_] = N;
				aliveQueue.push(coordinate(node.row_ - 1, node.col_));
			}

			// down
			if(node.row_ + 1 < rowSize - 1 && board[node.row_ + 1][node.col_] == targetChar)
			{
				board[node.row_ + 1][node.col_] = N;
				aliveQueue.push(coordinate(node.row_ + 1, node.col_));
			}

			// left
			if(node.col_ - 1 > 0 && board[node.row_][node.col_ - 1] == targetChar)
			{
				board[node.row_][node.col_ - 1] = N;
				aliveQueue.push(coordinate(node.row_, node.col_ - 1));
			}

			// right
			if(node.col_ + 1 < colSize - 1 && board[node.row_][node.col_ + 1] == targetChar)
			{
				board[node.row_][node.col_ + 1] = N;
				aliveQueue.push(coordinate(node.row_, node.col_ + 1));
			}
		}

//		print(board);

		for (int r = 0; r<rowSize; r++) {
			for (int c = 0; c<colSize; c++) {
				if (board[r][c] == 'O') {
					board[r][c] = 'X';
				}
				else if (board[r][c] == 'N') {
					board[r][c] = 'O';
				}
			}
		}
	}

	void print(vector< vector<char> > &board) {
		for (int i = 0; i<board.size(); i++) {
			for (int j = 0; j<board[i].size(); j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
};