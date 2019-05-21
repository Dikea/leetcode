class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int res = 0, score = 0, n = tokens.size();
        int low = 0, high = n - 1;
        while(low <= high) {
            if(P >= tokens[low]) {
                P -= tokens[low++];
                res = max(res, ++score);
            }
            else if(score > 0) {
                score--;
                P += tokens[high--];
            }
            else break;
        }
        return res;
    }
};
