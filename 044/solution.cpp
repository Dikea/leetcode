class Solution {
public:
    bool isMatch(string s, string p) {
        int len_p = p.size();
        int len_s = s.size();
        
        vector<vector<bool>> dp(len_p + 1, vector<bool>(len_s + 1, false));
        
        dp[0][0] = true;
        
        int cnt = 0;
        while(p[cnt++] == '*'){
            dp[cnt][0] = true;
        }
        
        for(int i = 0; i < len_p; i++){
            for(int j = 0; j < len_s; j++){
                if(p[i] == s[j]) dp[i + 1][j + 1] = dp[i][j];
                else if(p[i] == '?') dp[i + 1][j + 1] = dp[i][j];
                else if(p[i] == '*') dp[i + 1][j + 1] = dp[i][j] || dp[i + 1][j] || dp[i][j + 1];
            }
        }
        
        return dp[len_p][len_s];
    }
};
