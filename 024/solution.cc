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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode tmp(0);
        ListNode *pre = &tmp, *cur = head;
        pre->next = head;
        while(cur && cur->next){
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre = pre->next;
            pre->next = cur;
            pre = cur;
            cur = cur->next;
        }
        return tmp.next;
    }
};
