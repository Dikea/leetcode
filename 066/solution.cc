class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add = 1;
        for(int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + add;
            digits[i] = sum % 10;
            add = sum / 10;
        }
        if(add) {
            digits.insert(digits.begin(), add);
        }
        return digits;
    }
};
