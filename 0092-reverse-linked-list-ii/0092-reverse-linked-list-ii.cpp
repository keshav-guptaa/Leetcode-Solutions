/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curr = head, *temp = head, *prev = NULL, *ahead = NULL, *st = NULL;
        ListNode *h = NULL;
        int ct = 0;
        while(temp){
            ct++;
            if(ct == left-1) h = temp;
            if(ct == left) curr = temp;
            temp = temp->next;
        }
        st = curr;
        int tot = right-left+1;
        while(tot--){
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        if(h != NULL){
            h->next = prev;
        }
        else head = prev;
        st->next = curr;
        return head;
        
    }
};