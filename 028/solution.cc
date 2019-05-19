class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for(int i = 0; i < m - n + 1; i++) {
            int j = 0;
            while(j < n && needle[j] == haystack[i + j]) {
                j++;
            }
            if(j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};
