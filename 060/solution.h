#include <set>
#include <map>	
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
	
using namespace std;

class Solution{
public:
	string getPermutation(int n, int k){
		int scale[10];
		scale[1] = 1;
		for(int i = 2; i < 10; i++)
			scale[i] = scale[i - 1] * i;
		int pos = 0;
		string res = "";
		while(k){
			if ( scale[n - pos] > k){
				res += ( char(pos) + 1 );
			}
			else{
				int t = k / scale[n - pos];
				res += ( char(pos) + 1 + t);
				k %= scale[n - pos];
			}
		}
		return res;
	}
};


int main(){
	Solution s;
	cout << s.getPermutation(3, 1) << endl;
	return 0;
}
