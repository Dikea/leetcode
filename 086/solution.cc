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
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0), right(0);
        ListNode *l = &left, *r = &right;
        while(head) {
            if(head->val < x) {
                l->next = head;
                l = l->next;
            }
            else {
                r->next = head;
                r = r->next;
            }
            head = head->next;
        }
        l->next = right.next;
        r->next = NULL;
        return left.next;
    }
};
