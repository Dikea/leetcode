class Solution {
public:
    string strWithout3a3b(int A, int B) {
        if(A == 0) return string(B, 'b');
        else if(B == 0) return string(A, 'a');
        else if(A == B) return "ab" + strWithout3a3b(A - 1, B - 1);
        else if(A > B) return "aab" + strWithout3a3b(A - 2, B - 1);
        else return "bba" + strWithout3a3b(A - 1, B - 2);
    }
};
