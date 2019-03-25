class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        if (n < 4){
            return results;
        }
        
        for(int i = 0; i < n - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if(nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            
            for(int j = i + 1; j < n - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                int left = j + 1;
                int right = n - 1;
                while(left < right){
                    int val = nums[i] + nums[j] + nums[left] + nums[right];
                    if(val < target) left++;
                    else if(val > target) right--;
                    else{
                        results.push_back(
                            vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        do{
                            left++;
                        }while(left < right && nums[left - 1] == nums[left]);
                        do{
                            right--;
                        }while(left < right && nums[right + 1] == nums[right]);
                    }
                }
            }
        }
        return results;
    }
};
