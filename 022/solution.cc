class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> f(n + 1);
        f[0] = {""};
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                for(string &s1 : f[j]){
                    for(string &s2 : f[i -j - 1]){
                        f[i].push_back("(" + s1 + ")" + s2);
                    }
                }
            }
        }
        return f[n];
    }
};
