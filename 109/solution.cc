/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        return sortList(head, NULL);
    }

private:
    TreeNode* sortList(ListNode *head, ListNode *tail) {
        if(head == tail) {
            return NULL;
        }
        if(head->next == tail) {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode *slow = head, *fast = head;
        while(fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortList(head, slow);
        root->right = sortList(slow->next, tail);
        return root;
    } 
};
