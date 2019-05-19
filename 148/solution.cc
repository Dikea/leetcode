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
    ListNode* sortList(ListNode* head) {
        ListNode* root = merge_sort(head);
        return root;
    }
    
private:
    ListNode* merge_sort(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *slow, *fast;
        slow = head, fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *heada = head, *headb = slow->next;
        slow->next = NULL;
        return merge_list(merge_sort(heada), merge_sort(headb));
    }
    
    ListNode* merge_list(ListNode* heada, ListNode *headb) {
        ListNode *res = new ListNode(0);
        ListNode *p = res;
        while(heada || headb) {
            if(heada && (!headb || heada->val < headb->val)) {
                res->next = new ListNode(heada->val);
                res = res->next;
                heada = heada->next;
            }
            if(headb && (!heada || heada->val >= headb->val)) {
                res->next = new ListNode(headb->val);
                res = res->next;
                headb = headb->next;
            }
        }
        return p->next;
    }
};
