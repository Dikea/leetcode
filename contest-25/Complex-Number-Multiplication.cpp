// solve I
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int x[4], cnt = 0;
        int len = 0;
        string num = "";
        string c = a + b;
        string ans = "";
        
        while(len < c.size()){
            if((c[len] <= '9' && c[len] >= '0') || (c[len] == '-') ) {
                num += c[len];
            }
            else {
                x[cnt++] = atoi(num.c_str());
                num = "";
            }
            len++;
        }
        
        int A = x[0] * x[2] - x[1] * x[3];
        int B = x[0] * x[3] + x[1] * x[2];
        ans = to_string(A) + '+' + to_string(B) + 'i';
        
        return ans;
    }
};

// solve II
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int real_a, imag_a, real_b, imag_b;
        sscanf(a.c_str(), "%d+%di", &real_a, &imag_a);
        sscanf(b.c_str(), "%d+%di", &real_b, &imag_b);
        int real = real_a * real_b - imag_a * imag_b;
        int imag = real_a * imag_b + real_b * imag_a;
        return to_string(real) + "+" + to_string(imag) + "i";
    }
};