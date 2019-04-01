class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long dvd = labs(dividend), dvs = labs(divisor);
        long ans = 0;
        while(dvs <= dvd){
            long tmp = dvs, m = 1;
            while(tmp << 1 < dvd){
                tmp <<= 1;
                m <<= 1;
            }
            dvd -= tmp;
            ans += m;
        }
        return ans * sign;
    }
};
