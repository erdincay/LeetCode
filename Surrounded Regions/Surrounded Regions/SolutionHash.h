#pragma once
#include <vector>
#include <unordered_set>
#include <memory>

using namespace std;

struct coordinate
{
	int row_;
	int col_;

	coordinate(int x, int y)
	{
		row_ = x;
		col_ = y;
	}
};

struct hashFunc {
	size_t operator()(const coordinate &k) const {
		size_t h1 = std::hash<int>()(k.row_);
		size_t h2 = std::hash<int>()(k.col_);
		return (51 + h1) * 51 + h2;
	}
};

struct equalsFunc {
	bool operator()(const coordinate& lhs, const coordinate& rhs) const {
		return lhs.row_ == rhs.row_ && lhs.col_ == rhs.col_;
	}
};

typedef unordered_set<coordinate, hashFunc, equalsFunc> coordinate_set;

class LinkedNodes : public coordinate_set
{
	bool alive_;


public:
	LinkedNodes(bool alive, const coordinate & node)
	{
		alive_ = alive;
		this->insert(node);
	}

	void InsertNode(const coordinate & node, bool alive)
	{
		alive_ |= alive;
		this->insert(node);
	}

	bool Alive() const
	{
		return alive_;
	}

	void Merge(LinkedNodes & oth)
	{
		for (auto& othNode : oth)
		{
			InsertNode(othNode, oth.Alive());
		}
	}
};

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if(board.size() <= 0 || board.front().size() <= 0)
		{
			return;
		}

		auto rowSize = board.size();
		auto colSize = board.front().size();

		unique_ptr<vector<LinkedNodes>> xLinks(new vector<LinkedNodes>());
		unique_ptr<vector<LinkedNodes>> oLinks(new vector<LinkedNodes>());

		for (auto i = 0; i < rowSize; ++i)
		{
			for (auto j = 0; j < colSize; ++j)
			{
				bool alive = i == 0 || i == rowSize - 1 || j == 0 || j == colSize - 1;
				auto curNode = coordinate(i, j);
				if(board[i][j] == X)
				{
					xLinks = addNode(curNode, alive, *xLinks, getNeighbors(curNode, rowSize, colSize));
				}
				else
				{
					oLinks = addNode(curNode, alive, *oLinks, getNeighbors(curNode, rowSize, colSize));
				}
			}
		}

		for (auto& link : *xLinks)
		{
			if(!link.Alive())
			{
				for (const auto& node : link)
				{
					board[node.row_][node.col_] = O;
				}
			}
		}

		for (auto& link : *oLinks)
		{
			if(!link.Alive())
			{
				for (const auto& node : link)
				{
					board[node.row_][node.col_] = X;
				}
			}
		}
	}

private:
	unique_ptr<vector<LinkedNodes>> addNode(const coordinate& node, bool alive, vector<LinkedNodes> & allLinks, const vector<coordinate>& neighbors)
	{
		unique_ptr<vector<LinkedNodes>> ret(new vector<LinkedNodes>);

		LinkedNodes mergedLink(alive, node);
		for (auto& link : allLinks)
		{
			bool merged = false;
			for (auto& neighbor : neighbors)
			{
				if (link.count(neighbor) > 0)
				{
					merged = true;
					mergedLink.Merge(link);
					break;
				}
			}

			if(!merged)
			{
				ret->push_back(link);
			}
		}

		ret->push_back(mergedLink);

		return ret;
	}

	vector<coordinate> getNeighbors(const coordinate & node, size_t rowSize, size_t colSize)
	{
		vector<coordinate> ret;
		if(node.row_ - 1 >= 0)
		{
			ret.push_back(coordinate(node.row_ - 1, node.col_));
		}

		if(node.row_ + 1 < rowSize)
		{
			ret.push_back(coordinate(node.row_ + 1, node.col_));
		}

		if(node.col_ - 1 >= 0)
		{
			ret.push_back(coordinate(node.row_, node.col_ - 1));
		}

		if(node.col_ + 1 < colSize)
		{
			ret.push_back(coordinate(node.row_, node.col_ + 1));
		}

		return ret;
	}
};
