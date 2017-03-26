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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> left, right, leave, ans;
        if(!root) return ans;
        left.push_back(root->val);
        right.push_back(root->val);
        
        if(root->left) leftBoundary(root, left);
        if(root->right) rightBoundary(root, right);
        if(root->left || root->right)leaveBoundary(root, leave);
        /*
        for(int i = 0; i < left.size(); i++) printf("%d ", left[i]); printf("\n");
        for(int i = 0; i < right.size(); i++) printf("%d ", right[i]); printf("\n");
        for(int i = 0; i < leave.size(); i++) printf("%d ", leave[i]); printf("\n");
        */
        
        for(int i = 0; i < left.size(); i++) {
            ans.push_back(left[i]);
        }
        
        int i;
        i = !(root->left) ? 0 : 1;
        for( ; i < leave.size(); i++){
            ans.push_back(leave[i]);
        }
        
        reverse(right.begin(), right.end());
        i = !(root->right) ? 0 : 1;
        for( ; i < right.size() - 1; i++){
            ans.push_back(right[i]);
        }
        
        return ans;
    }
    
    void leftBoundary(TreeNode* T, vector<int>& left){
        if(T->left) {
            left.push_back(T->left->val);
            leftBoundary(T->left, left);
        }
        else if(T->right) {
            left.push_back(T->right->val);
            leftBoundary(T->right, left);
        }
    }
        
    void rightBoundary(TreeNode* T, vector<int>& right){
        if(T->right){
            right.push_back(T->right->val);
            rightBoundary(T->right, right);
        }
        else if(T->left){
            right.push_back(T->left->val);
            rightBoundary(T->left, right);
        }
    }
    
    void leaveBoundary(TreeNode* T, vector<int>& leave){
       if(!(T->left) && !(T->right)){
           leave.push_back(T->val);
       }
       if(T->left)leaveBoundary(T->left, leave);
       if(T->right)leaveBoundary(T->right, leave);
    }
};