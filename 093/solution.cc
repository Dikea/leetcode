class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] != '0') {
                dp[i] = dp[i + 1];
                int tmp = (s[i] - '0') * 10 + s[i + 1] - '0';
                if(i < n - 1 && tmp >= 10 && tmp <= 26) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
};
