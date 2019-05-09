class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.length(), tLen = t.length(), si = 0;
        for(int ti = 0; ti < tLen && si < sLen; ti++) {
            if(t[ti] == s[si]) si++;
        }
        return si == sLen;
    }
};
