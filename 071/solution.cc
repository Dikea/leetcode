class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stack;
        stringstream ss(path);
        while(getline(ss, tmp, '/')) {
            if(tmp == "" or tmp == ".") { 
                continue; 
            }
            if(tmp == "..") {
                if(!stack.empty()) {
                    stack.pop_back();
                }
            }
            else { 
                stack.push_back(tmp); 
            }
        }
        for(auto s : stack) {
            res += "/" + s;
        }
        return res.empty() ? "/" : res;
    }
};
