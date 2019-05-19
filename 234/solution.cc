/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *pre = NULL, *cur = slow->next;
        slow->next = NULL;
        while(cur) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        while(head && pre) {
            cout << head->val << " " << pre->val << endl;
            if(head->val != pre->val) {
                return false;
            }
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};
