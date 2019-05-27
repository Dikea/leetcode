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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if(!root) return sum;
        reverse(root, root->val, sum);
        return sum;
    }

private:
    void reverse(TreeNode* tree, int val, int& sum) {
        if(!tree->left && !tree->right) {
            sum += val;
            return ;
        }
        if(tree->left) reverse(tree->left, val * 10 + tree->left->val, sum);
        if(tree->right) reverse(tree->right, val * 10 + tree->right->val, sum);
    }
};
