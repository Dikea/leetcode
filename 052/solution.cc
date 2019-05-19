class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<pair<int, int>> vis; 
        findSolution(count, 0, n, vis);
        return count;
    }

private:
    void findSolution(int& count, int pos, int n, vector<pair<int, int>> vis) {
        if(pos == n) {
            count++;
            return;
        }
        for(int row = 0; row < n; row++) {
            bool is_conflict = false;
            for(auto v : vis) {
                if(v.first == row || abs(row - v.first) == abs(pos - v.second)) {
                    is_conflict = true;
                    break;
                }
            }
            if(is_conflict) continue;
            vis.push_back(make_pair(row, pos));
            findSolution(count, pos + 1, n, vis);
            vis.pop_back();
        }
    }
};
