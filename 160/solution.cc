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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count_a = 0, count_b = 0;
        ListNode *tmp_a = headA, *tmp_b = headB;
        while(tmp_a) {
            tmp_a = tmp_a->next;
            count_a++;
        }
        while(tmp_b) {
            tmp_b = tmp_b->next;
            count_b++;
        }
        int sub = abs(count_a - count_b);
        if(count_a > count_b) {
            while(sub--) headA = headA->next;
        }
        else {
            while(sub--) headB = headB->next;
        }
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
