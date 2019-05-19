class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        find_combination(res, candidates, vector<int> {}, target, 0);
        return res;
    }
private:
    void find_combination(vector<vector<int>>& res, vector<int> candidates, vector<int> now, int target, int pos) {
        if(target == 0) {
            res.push_back(now);
        }
        for(; pos < candidates.size(); pos++) {
            if(candidates[pos] > target) { 
                continue; 
            }
            now.push_back(candidates[pos]);
            find_combination(res, candidates, now, target - candidates[pos], pos + 1);
            now.pop_back();
            while(pos + 1 < candidates.size() && candidates[pos] == candidates[pos + 1]) {
                pos++;
            }
        }
    }
};
