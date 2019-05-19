class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0, len = prices.size();
        for(int i = 1; i < len; i++) {
            if(prices[i] > prices[i - 1]) {
                sum += prices[i] - prices[i - 1];
            }
        }
        return sum;
    }
};
