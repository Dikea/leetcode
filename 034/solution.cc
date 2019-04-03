class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int lower = lower_bound(nums, target);
        int higher = lower_bound(nums, target + 1);
        if(lower == higher) {
            return vector<int> {-1, -1};
        }
        else {
            return vector<int> {lower, higher - 1};
        }
    }
    
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};
