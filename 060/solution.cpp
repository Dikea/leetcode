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
		int vis[10];
		scale[1] = 1;
		memset(vis, 0, sizeof( vis ));
		for(int i = 2; i < 10; i++)
			scale[i] = scale[i - 1] * i;
		int pos = 0;
		string res = "";
		while(k && pos < n){
			if( k == scale[n - pos] ){
				int index;
				for( index  = n; index >= 1; index--)
					if( !vis[index] ) res += '0' + index;
				break;
			}
			else if(k > scale[n - pos - 1] ) {
				int t = k / scale[n - pos - 1];
				if(k % scale[n - pos - 1] == 0) t--;
				int index , cnt = 0;
				for( index  = 1; index <= n; index ++){
					if( !vis[index] ) cnt++;
					if( cnt == t ) break;
				}
				vis[index] = 1;
				k -= t * scale[n - pos - 1];
				res += '0' + index;	
			}
			else if( k < scale[n - pos + 1]) {
				int index;
				for( index = 1; index <= n; index++)
					if( !vis[index] ) break;
				vis[index] = 1;
				res += '0' + index;
			}
//			cout << "pos : " << pos << "  res : " << res << endl;
			pos++;
		}
		return res;
	}
};


int main(){
	Solution s;
	for( int i = 1; i <= 24; i++){
		cout << s.getPermutation(4, i) << endl;
	}
	cout << s.getPermutation(4, 4) << endl;
//	cout << s.getPermutation(3, 2) << endl;
//	cout << s.getPermutation(4, 24) << endl;
//	cout << s.getPermutation(4, 5) << endl;
	return 0;
}
