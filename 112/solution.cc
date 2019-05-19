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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return get_sum(root, root->val, sum);
    }

private:
    bool get_sum(TreeNode* cur, int cur_sum, int sum) {
        if(!cur->left && !cur->right && cur_sum == sum) {
            return true;
        }
        if(cur->left && get_sum(cur->left, cur_sum + cur->left->val, sum)) {
            return true;
        }
        if(cur->right && get_sum(cur->right, cur_sum + cur->right->val, sum)) {
            return true;
        }
        return false;
    }
};
