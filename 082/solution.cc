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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode res = ListNode(head->val + 1);
        ListNode *pre = &res, *ptr = &res;
        while(head) {
            if(head->val != pre->val && (!head->next || head->val != head->next->val)) {
                ptr->next = head;
                ptr = ptr->next;
            }
            pre = head;
            head = head->next;
        }
        ptr->next = NULL;
        return res.next;
    }
};
