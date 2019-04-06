class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans(1, vector<int>());
        for(auto num : nums) {
            vector<vector<int>> new_ans;
            for(auto vec : ans) {
                for(int offset = 0; offset <= vec.size(); offset++) {
                    vector<int> temp(vec);
                    temp.insert(temp.begin() + offset, num);
                    new_ans.push_back(temp);
                }
            }
            ans = new_ans;
        }
        return ans;
    }
};
