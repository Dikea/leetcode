class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        vector<int> endPos(26, 0), res;
        for(int i = 0; i < n; i++) endPos[S[i] - 'a'] = i;
        int maxEnd = INT_MIN, lastId = 0;
        for(int i = 0; i < n; i++) {
            maxEnd = max(maxEnd, endPos[S[i] - 'a']);
            if(maxEnd == i) {
                res.push_back(i - lastId + 1);
                lastId = i + 1;
            }
        }
        return res;
    }
};
