/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> path;
        getPath(root, path, res, sum);
        return res;
    }
    
private:
    void getPath(TreeNode* root, vector<int> path, vector<vector<int>>& res, int val) {
        if(!root->left && !root->right && val == root->val) {
            path.push_back(root->val);
            res.push_back(path);
            return;
        }
        if(root->left) {
            path.push_back(root->val);
            getPath(root->left, path, res, val - root->val);
            path.pop_back();
        }
        if(root->right) {
            path.push_back(root->val);
            getPath(root->right, path, res, val - root->val);
            path.pop_back();
        }
    }
};
