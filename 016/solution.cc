class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3){
            return 0;
        }
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int cur_sum = nums[i] + nums[left] + nums[right];
                if(abs(cur_sum - target) < abs(closest - target)){
                    closest = cur_sum;
                }
                if(cur_sum < target){
                    left += 1;
                }
                else if(cur_sum > target){
                    right -= 1;
                }
                else{
                    return cur_sum;
                }
            }
        }
        return closest;
    }
};
