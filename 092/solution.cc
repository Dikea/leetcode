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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next) {
            return head;
        }
        
        ListNode *dummy = new ListNode(0), *p, *q;
        dummy->next = head, p = dummy;
        for(int i = 0; i < m - 1; i++) {
            p = p->next;
        }
        
        n = n - m + 1;
        ListNode *pre, *cur;
        pre = NULL, q = cur = p->next;
        // Reverse the node from m-th to n-th.
        while(n--) {
            ListNode *tmp = cur;
            cur = cur->next;
            tmp->next = pre;
            pre = tmp;
        }
        
        // Concat the start and the end.
        p->next = pre;
        q->next = cur;
        return dummy->next;
    }
};
