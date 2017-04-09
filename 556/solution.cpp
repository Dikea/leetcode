class Solution {
public:
    int nextGreaterElement(int n) {
        char s[12];
        sprintf(s, "%d", n);
        int len = strlen(s);
        sort(s, s + len);
        long long ans = 1e12;
        do{
            long long x = atoll(s);
            if(x > n && x < ans) {
                std::cout << x << std::endl;
                ans = x;
                break;
            }
        }while(next_permutation(s, s + len));
        return (ans > INT_MAX ? -1 : ans);
    }
};
