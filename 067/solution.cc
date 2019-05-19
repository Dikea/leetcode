class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int tmp = 0;
        string s = "";
        while(i >= 0 || j >= 0 || tmp > 0) {
            tmp += i >= 0 ? a[i--] - '0' : 0;
            tmp += j >= 0 ? b[j--] - '0' : 0;
            s = char(tmp % 2 + '0') + s;
            tmp = tmp / 2;
        }
        return s;
    }
};
