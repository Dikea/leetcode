class Solution {
public:
    bool isHappy(int n) {
        int sum = n, new_sum = 0;
        set<int> vals = {sum};
        while(sum != 1) {
            while(sum) {
                new_sum += pow(sum % 10, 2);
                sum /= 10;
            }
            sum = new_sum;
            new_sum = 0;
            if(vals.find(sum) != vals.end()) {
                return false;
            }
            vals.insert(sum);
        }
        return true;
    }
};
