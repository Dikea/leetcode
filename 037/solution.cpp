class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		vector<pair<int, int>> v;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++) if(board[i][j] == '.') {
				v.push_back(make_pair(i, j));
			}
		}
		dfs(board, v, 0);
	}
	
	bool dfs(vector<vector<char>> &board, vector<pair<int, int>> v, int cnt){
		if(cnt == v.size()) return true;
		
		pair<int, int> P = v[cnt];
		int x = P.first;
		int y = P.second;
		
		if(board[x][y] != '.'){
			dfs(board, v, cnt + 1);
		}
		else{
			for(char val = '1'; val <= '9'; val++) {
				if(check(board, x, y, val)){
					board[x][y] = val;
					if(dfs(board, v, cnt + 1)) return true;
					board[x][y] = '.';
				}
			}
		}
		return false;
	}
	
	bool check(vector<vector<char>> board, int x, int y, char val){
		for(int i = 0; i < 9; i++)
			if(board[x][i] == val || board[i][y] == val || board[x - x%3 + i/3][y - y%3 + i%3] == val) {
				return false;
			}
		return true;
	}

};
