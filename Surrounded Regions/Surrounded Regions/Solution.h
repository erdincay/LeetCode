class node
{
private:
	char val_;
	bool * aliveMem_;
	bool asked_;
	vector<node *> neighbors_;

private:
	void setnodeval(char val) {
		val_ = val;
	}

	void setAsked(bool val) {
		asked_ = val;
	}

	void setAliveMem(bool val) {
		if(aliveMem_ == NULL) {
			aliveMem_ = new bool(val);
		}
		else {
			*aliveMem_ = val;
		}
	}

public:
	node(char val) {
		val_ = val;
		asked_ = false;
		aliveMem_ = NULL;
		neighbors_.clear();
	}

	~node() {
		delete aliveMem_;
	}

	char getnodeval() {
		return val_;
	}

	bool getAsked() {
		return asked_;
	}

	void addneighbor(node * val) {
		neighbors_.push_back(val);
		if(val == NULL) {
			setAliveMem(true);
		}
	}

	bool alive(node * request) {
		if(aliveMem_ != NULL) {
			return *aliveMem_;
		}

		bool ret = false;
		setAsked(true);
		for(vector<node *>::iterator it = neighbors_.begin(); it != neighbors_.end(); it++)	{
			if(*it == NULL) {
				ret = true;
				break;
			}

			if((*it != request) && (!(*it)->getAsked()) && ((*it)->getnodeval() == getnodeval())) {
				if((*it)->alive(this)) {
					ret = true;
					break;
				}
			} 
		}

		setAliveMem(ret);
		//setAsked(false);
		return ret;
	}
};

class Solution
{
public:
	void solve(vector<vector<char>> &board) {
		//init nodes
		vector<vector<node>> node_board;
		for(int l=0; l<board.size(); l++) {
			vector<node> node_line;
			for(int r=0; r<board[l].size(); r++) {
				node nd(board[l][r]);
				node_line.push_back(nd);
			}
			node_board.push_back(node_line);
		}

		//init nodes neighbor relation
		for(int l=0; l<node_board.size(); l++) {
			for(int r=0; r<node_board[l].size(); r++) {
				node_board[l][r].addneighbor(getNode(l-1,r,node_board));
				node_board[l][r].addneighbor(getNode(l+1,r,node_board));
				node_board[l][r].addneighbor(getNode(l,r-1,node_board));
				node_board[l][r].addneighbor(getNode(l,r+1,node_board));
			}
		}

		for(int l=0; l<node_board.size(); l++) {
			for(int r=0; r<node_board[l].size(); r++) {
				if((node_board[l][r].getnodeval() == 'O') && (node_board[l][r].alive(NULL) == false)) {
					board[l][r] = 'X';
				}
			}
		}
	}

private:
	node * getNode(int line, int row, vector<vector<node>> & node_board) {
		if(line < 0 || row < 0 || line >= node_board.size() || row >= node_board[line].size()) {
			return NULL;
		}

		return &node_board[line][row];
	}
};

