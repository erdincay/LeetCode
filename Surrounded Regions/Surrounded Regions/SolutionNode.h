#include <unordered_set>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class node
{
private:
	char val_;
	bool edge_;
	vector<node *> neighbors_;

private:
	void setEdgeNode(bool val)
	{
		edge_ = val;
	}

public:
	explicit node(char val)
	{
		val_ = val;
		edge_ = false;
		neighbors_.clear();
	}

	~node()
	{
	}

	char getnodeval()
	{
		return val_;
	}

	void setnodeval(char val)
	{
		val_ = val;
	}

	void addneighbor(node* val)
	{
		if (val == nullptr)
		{
			setEdgeNode(true);
		}
		else
		{
			neighbors_.push_back(val);
		}
	}

	bool beConnected(unordered_set<node *> partition)
	{
		for (auto neighbor : neighbors_)
		{
			if (getnodeval() == neighbor->getnodeval() && partition.count(neighbor) > 0)
			{
				return true;
			}
		}

		return false;
	}

	vector<pair<unordered_set<node *>, bool>> assign(vector<pair<unordered_set<node *>, bool>> partitions)
	{
		unordered_set<size_t> indexs;
		for (int IDX = 0; IDX < partitions.size(); ++IDX)
		{
			if(beConnected(partitions[IDX].first))
			{
				indexs.insert(IDX);
			}
		}

		auto new_set = unordered_set<node *>({ this });
		auto alive = edge_;
		if (indexs.empty())
		{
			partitions.push_back(make_pair<unordered_set<node *>, bool>(move(new_set), move(alive)));
			return partitions;
		}

		vector<pair<unordered_set<node *>, bool>> ret;
		for (int IDX = 0; IDX < partitions.size(); ++IDX)
		{
			if (indexs.count(IDX) > 0)
			{
				if (alive && !partitions[IDX].second)
				{
					for (auto node : partitions[IDX].first)
					{
						node->setEdgeNode(true);
					}
				}

				if (!alive && partitions[IDX].second)
				{
					for (auto node : new_set)
					{
						node->setEdgeNode(true);
					}
				}

				alive |= partitions[IDX].second;
				new_set.insert(partitions[IDX].first.begin(), partitions[IDX].first.end());
			}
			else
			{
				ret.push_back(partitions[IDX]);
			}
		}

		ret.push_back(make_pair<unordered_set<node *>, bool>(move(new_set), move(alive)));

		return ret;
	}
};


class Solution
{
public:
	void solve(vector<vector<char>>& board)
	{
		//init nodes
		vector<vector<node>> node_board;
		for (int l = 0; l < board.size(); l++)
		{
			vector<node> node_line;
			for (int r = 0; r < board[l].size(); r++)
			{
				node nd(board[l][r]);
				node_line.push_back(nd);
			}
			node_board.push_back(node_line);
		}

		//init nodes neighbor relation
		for (int l = 0; l < node_board.size(); l++)
		{
			for (int r = 0; r < node_board[l].size(); r++)
			{
				node_board[l][r].addneighbor(getNode(l - 1, r, node_board));
				node_board[l][r].addneighbor(getNode(l + 1, r, node_board));
				node_board[l][r].addneighbor(getNode(l, r - 1, node_board));
				node_board[l][r].addneighbor(getNode(l, r + 1, node_board));
			}
		}

		//partition every node
		vector<pair<unordered_set<node *>, bool>> partitions;
		for (int l = 0; l < node_board.size(); l++)
		{
			for (int r = 0; r < node_board[l].size(); r++)
			{
				partitions = node_board[l][r].assign(partitions);
			}
		}

		//change the dead node
		for (auto const & partition : partitions)
		{
			if (!partition.second && (*partition.first.begin())->getnodeval() == 'O')
			{
				for (auto node : partition.first)
				{
					node->setnodeval('X');
				}
			}
		}

		//write result
		for (int l = 0; l < node_board.size(); l++)
		{
			for (int r = 0; r < node_board[l].size(); r++)
			{
				board[l][r] = node_board[l][r].getnodeval();
			}
		}
	}

private:
	node* getNode(int line, int row, vector<vector<node>>& node_board)
	{
		if (line < 0 || row < 0 || line >= node_board.size() || row >= node_board[line].size())
		{
			return nullptr;
		}

		return &node_board[line][row];
	}
};