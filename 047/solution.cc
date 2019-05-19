class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        permute(res, nums, 0);
        return res;
    }

private:
    void permute(vector<vector<int>>& res, vector<int> nums, int pos) {
        if(pos == nums.size()) {
            res.push_back(nums);
        }
        for(int i = pos; i < nums.size(); i++) {
            if(i != pos && nums[i] == nums[pos]) {
                continue;
            }
            swap(nums[i], nums[pos]);
            permute(res, nums, pos + 1);
        }
    }
};
