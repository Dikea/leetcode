class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> table(n1 + 1, vector<int> (n2 + 1, 0));
        for(int i = 1; i <= n1; i++) table[i][0] = i;
        for(int j = 1; j <= n2; j++) table[0][j] = j;
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                // remove word1[i] or word2[j]
                table[i][j] = min(table[i - 1][j], table[i][j - 1]) + 1; 
                // replace word1[i] with word2[j]
                table[i][j] = min(table[i][j], table[i - 1][j - 1] + 1);
                if(word1[i - 1] == word2[j - 1]) {
                    table[i][j] = min(table[i][j], table[i - 1][j - 1]);
                }
            }
        }
        return table[n1][n2];
    }
};
