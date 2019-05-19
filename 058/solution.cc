class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx = s.size() - 1;
        while(idx >= 0 && s[idx] == ' ') {
            idx -= 1;
        }
        int ans = 0;
        while(idx >= 0 && s[idx] != ' ') {
            ans += 1;
            idx -= 1;
        }
        return ans;
    }
};
