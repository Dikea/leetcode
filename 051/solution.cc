# 1. Solve it by my self with see any solution !

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<pair<int, int>> path;
        vector<int> vis_row(n, 0);
        vector<int> vis_add(2 * n - 1, 0);
        vector<int> vis_sub(2 * n - 1, 0);
        for(int row = 0; row < n; row++) {
            vis_row[row] = 1;
            vis_add[row + 0] = 1;
            vis_sub[row - 0 + n - 1] = 1;
            path.push_back(make_pair(row, 0));
            dfs(res, vis_row, vis_add, vis_sub, path, 1, n);
            vis_row[row] = 0;
            vis_add[row + 0] = 0;
            vis_sub[row - 0 + n - 1] = 0;
            path.pop_back();
        }
        return res;
    }

private:
    void dfs(vector<vector<string>> &res, vector<int> vis_row, vector<int> vis_add,
             vector<int> vis_sub, vector<pair<int, int>>path, int col, int n) {
        if(col == n) {
            vector<string> tmp(n, string(n, '.'));
            for(auto item : path) {
                tmp[item.first][item.second] = 'Q';
            }
            res.push_back(tmp);
            return ;
        }
        for(int row = 0; row < n; row++) {
            int add_id = row + col;
            int sub_id = row - col + n - 1;
            if(!vis_row[row] && !vis_add[add_id] && !vis_sub[sub_id]) {
                vis_row[row] = 1;
                vis_add[add_id] = 1;
                vis_sub[sub_id] = 1;
                path.push_back(make_pair(row, col));
                dfs(res, vis_row, vis_add, vis_sub, path, col + 1, n);
                vis_row[row] = 0;
                vis_add[add_id] = 0;
                vis_sub[sub_id] = 0;
                path.pop_back();
            }
        }
    }
};

# 2. Another beautiful solution with same thought.

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string>> result; vector<int> r (n, -1);
    solve(result, r, 0);
    return result;
}

void solve(vector<vector<string> >& result, vector<int>& r, int curRow) {
    for(int xPos = 0; xPos<r.size(); xPos++) {
        r[curRow] = xPos;
        bool isSafe = true;
        for(int i = 0; i<curRow; i++) {
            if(r[i] == xPos || abs(curRow - i) == abs(xPos - r[i])) {
                isSafe = false;
                break;
            }
        }

        if(isSafe && curRow == r.size() - 1) {
            vector<string> v (r.size(), string(r.size(), '.'));
            for(int i = 0; i<r.size(); i++)
                v[i][r[i]] = 'Q';
            result.push_back(v);
        }
        else if(isSafe) {
            solve(result, r, curRow + 1);
        }
    }
}
