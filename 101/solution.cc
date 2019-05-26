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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        TreeNode *left, *right;
        left = root->left, right = root->right;
        queue<TreeNode*> q1, q2;
        q1.push(left);
        q2.push(right);
        while(!q1.empty()) {
            left = q1.front();
            right = q2.front();
            q1.pop();
            q2.pop();
            if(left == NULL && right == NULL) {
                continue;
            }
            if(left == NULL || right == NULL) {
                return false;
            }
            if(left->val != right->val) {
                return false;
            }
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};
