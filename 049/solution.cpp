class Solution{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ret;
		int len = strs.size();
		int cnt = 0;
		map<string, int> mm[len];
		for(int i = 0; i < len; i++){
			string str = strs[i];
			sort(str.begin(), str.end());
			if(!mm[str]) {
				mm[str] = cnt++;
				ret[cnt - 1].push_back(str);
			}
			else {
				ret[mm[str]].push_back(str);
			}
		}
		return ret;
	 }
};


