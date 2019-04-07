class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int waters = 0, level = 0;
        while(left <= right){
            int lower = height[left] < height[right] ? height[left++] : height[right--];
            level = max(level, lower);
            waters += level - lower;
        }
        return waters;
    }
};
