class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        if(strs.size() == 0) return -1;
        int ret = -1;
        
        for(int i = 0; i < strs.size(); i++){
            bool possible = true;
            for(int j = 0; j < strs.size(); j++){
                if(i == j || strs[i].size() > strs[j].size()) continue;
                if(isSubsequence(strs[i], strs[j])) {
                    possible = false;
                    break;
                }
            }
            if(possible) ret = max(ret, (int)strs[i].size());
        }
        
        return ret;
    }
    
    bool isSubsequence(string str1, string str2){
        int i, j;
        for(i = 0, j = 0; i < str1.size() && j < str2.size(); j++){
            if(str1[i] == str2[j]) {
                i++;
            }
        }
        return (i == str1.size());
    }
};
