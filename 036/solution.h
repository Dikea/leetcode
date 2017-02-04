#include <set>
#include <map>	
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
	
using namespace std;
class Solution {
public:
	bool isValidSudoku(const vector<vector<char> > &board){
		bool used[9];
		for (int i = 0; i < 9; i++){
			fill(used, used + 9, false);
			for (int j = 0; j < 9; j++){
				if( !check(board[i][j], used) ) return false;
			}
		}

		for (int j = 0; j < 9; j++){
			fill(used, used + 9, false);
			for (int i = 0; i < 9; i++){
				if( !check(board[i][j], used) ) return false;
			}
		}

		for(int m = 0; m < 9; m += 3){
			for(int n = 0; n < 9; n += 3){
				fill(used, used + 9, false);
				for(int i = m; i < m + 3; i++){
					for(int j = n; j < n + 3; j++){
						if( !check(board[i][j], used) ) return false;
					}
				}
			}
		}

		return true;
	}

	bool check(char ch, bool used[9]){
		if(ch == '.') return true;
		if(used[ch - '1']) return false;
		return used[ch - '1'] = true;
	}
};
