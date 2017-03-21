class Solution {
public:
	string multiply(string num1, string num2) {
		string ret(num1.size() + num2.size(), '0');
		if(num1.size() < num2.size()) swap(num1, num2);
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		
		for(int i = 0, j; i < num2.size(); i++){
			int n2 = num2[i] - '0'; 
			int temp = 0;
			for(j = 0; j < num1.size(); j++){
				int n1 = num1[j] - '0';
				temp += n1 * n2 + (ret[i + j] - '0');
				ret[i + j] = temp % 10 + '0';
				temp /= 10;
			}
			if(temp) ret[i + j] = temp + '0';
		}
		
		while(ret.size() > 1 && ret[ret.size() - 1] == '0') ret.resize(ret.size() - 1);
		reverse(ret.begin(), ret.end());
		
		return ret;
	}
};
