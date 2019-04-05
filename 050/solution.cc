class Solution {
public:
    double myPow(double x, int n) {
        long t = n;
        if(n < 0){
            x = 1 / x;
            t = -t;
        }
        double ans = 1.0;
        while(t){
            if(t & 1){
                ans *= x;
            }
            t >>= 1;
            x *= x;
        }
        return ans;
    }
};
