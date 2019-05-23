class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& v1, const vector<int> &v2) {
            return v1[0] < v2[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0, pre = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < intervals[pre][1]) {
                res++;
                if(intervals[i][1] < intervals[pre][1]) {
                    pre = i;
                }
            }
            else pre = i;
        }
        return res;
    }
};
