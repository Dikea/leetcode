class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int u = 0, d = n - 1, l = 0, r = n - 1;
        vector<vector<int>> res(n, vector<int> (n, 0));
        int cnt = 1;
        while(u < d && l < r) {
            for(int j = l; j < r; j++) res[u][j] = cnt++;
            for(int i = u; i < d; i++) res[i][r] = cnt++;
            for(int j = r; j > l; j--) res[d][j] = cnt++;
            for(int i = d; i > u; i--) res[i][l] = cnt++;
            u++, d--, l++, r--;
        }
        if(l == r) {
            for(int i = u; i <= d; i++) res[i][l] = cnt++;
        }
        else if(u == d) {
            for(int j = l; j <= r; j++) res[u][j] = cnt++;
        }
        return res;
    }
};
