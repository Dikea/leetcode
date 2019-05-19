# 1. My solution

class Solution {
public:
    int mySqrt(int x) {
        int n = 1;
        while(long(n) * n <= x) {
            n <<= 1;
        }
        while(long(n) * n > x) {
            n--;
        }
        return n;
    }
};

# 2. Binary search solution.

class Solution {
public:
    int mySqrt(int x) {
        int low = 0,  high = x, mid;
        if(x<2) return x; // to avoid mid = 0
        while(low<high)
        {
            mid = (low + high)/2;
            if(x/mid >= mid) low = mid+1;
            else high = mid;
        }
        return low-1;  
    }
};
