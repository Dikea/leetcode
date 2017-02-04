#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

class Solution{
public:
	string getPermutation(int n, int k){
		int a[10], vis[10];
		a[0] = a[1] = 1;
		memset( vis, 0, sizeof( vis ) );
		for( int i = 2; i <= 10; i++) a[i] = a[i - 1] * i;
		string res = "";
		int pos = 0;

		while(k > 0){
			if( k == a[n - pos] ){
				for( int i = n; i >= 1; i--)
					if( !vis[i]) res += '0' + i;
				break;
			}
			else if( k < a[n - pos] )
			


			int index;

			for( index = n; index >= 1; index-- )
				if( k >= a[index] ) break;
			if( k == a[index] ) {
				for( int i = n; i >= 1; i-- )
					if( !vis[i] ) res += '0' + i;
				break;
			}
			else {
				int t = k / a[index];
				int cnt = 0;
				for( int i = 1; i <= n; i++){
					if( !vis[i] ) cnt++;
					if( cnt == t + 1 )
						break;
					res += '0' + i;
				}
				k -= t * a[index];
				res += '0' + 
			}
//			cout << k << endl;
		}
		return res;
	}
};

int main(){
	Solution s;
	for( int i = 1; i <= 24; i++)
		cout << s.getPermutation(4, i) << endl;
	return 0;

