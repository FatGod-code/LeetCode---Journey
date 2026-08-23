struct TrieType {
    TrieType* lchar[26] = {0};
    bool end = false;
};

class Solution
{
	public:
		bool dfs(int ind, int indi, int indj, vector<vector < char>> &board, string &search, int &row, int &col)
		{
			if (ind == search.size())
				return true;
			if (indi >= 0 and indi < row and indj >= 0 and indj < col)
			{
				if (board[indi][indj] != search[ind])
					return false;
				char originalchar = board[indi][indj];
				board[indi][indj] = '$';
				bool ans = dfs(ind + 1, indi + 1, indj, board, search, row, col) ||
					dfs(ind + 1, indi - 1, indj, board, search, row, col) ||
					dfs(ind + 1, indi, indj + 1, board, search, row, col) ||
					dfs(ind + 1, indi, indj - 1, board, search, row, col);
				board[indi][indj] = originalchar;
				return ans;
			}
			else
				return false;
		}
	vector<string> findWords(vector<vector < char>> &board, vector< string > &words)
	{
		int row = board.size();
		int col = board[0].size();
		vector<string> ans;
		vector<vector<pair<int, int>>> vp(27);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				vp[board[i][j] - 'a'].push_back({ i, j });
		}
		int starta = 0;
		int enda = 0;
		for (auto ele: words)
		{
			if (ele[0] == 'a')
				starta++;
			if (ele[ele.size() - 1] == 'a')
				enda++;
		}
		bool reversehaikya = false;
		if (starta > enda)
		{
			reversehaikya = true;
			for (int i = 0; i < words.size(); i++)
				reverse(words[i].begin(), words[i].end());
		}
		for (auto search: words)
		{
			bool flag = false;
			for (auto ele: vp[search[0] - 'a'])
			{
				flag = dfs(0, ele.first, ele.second, board, search, row, col);
				if (flag)
				{
					if (reversehaikya)
						reverse(search.begin(), search.end());

					ans.push_back(search);
					break;
				}
			}
		}
		return ans;
	}
};