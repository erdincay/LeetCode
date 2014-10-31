#include <unordered_set>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class node
{
private:
	char val_;
	bool* aliveMem_;
	vector<node *> neighbors_;

private:
	void setEdgeNode(bool val)
	{
		if (aliveMem_ == nullptr)
		{
			aliveMem_ = new bool(val);
		}
		else
		{
			*aliveMem_ = val;
		}
	}

public:
	explicit node(char val)
	{
		val_ = val;
		aliveMem_ = nullptr;
		neighbors_.clear();
	}

	~node()
	{
		if (aliveMem_ != nullptr)
		{
			delete aliveMem_;
		}
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

	bool alive(unordered_set<node *> & request_nodes)
	{
		if (aliveMem_ != nullptr)
		{
			return *aliveMem_;
		}

		request_nodes.insert(this);
		for (vector<node *>::iterator it = neighbors_.begin(); it != neighbors_.end(); ++it)
		{
			if ((request_nodes.count(*it) <= 0 ) && ((*it)->getnodeval() == getnodeval()))
			{
				if ((*it)->alive(request_nodes))
				{
					setEdgeNode(true);
					return true;
				}
			}

		}

		setEdgeNode(false);
		return false;
	}
};

//shoulde be right, but recursive call make stack over flow while the borad is large( > 3000 elenment)
class Solution1
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

		//check every node
		for (int l = 0; l < node_board.size(); l++)
		{
			for (int r = 0; r < node_board[l].size(); r++)
			{
				unordered_set<node *> request_set;
				request_set.clear();
				if ((node_board[l][r].getnodeval() == 'O') && (node_board[l][r].alive(request_set) == false))
				{
//					node_board[l][r].setnodeval('X');
					board[l][r] = 'X';
				}
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