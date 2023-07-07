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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *new_head = new ListNode(-1, head);
        ListNode *curr = head, *temp = NULL;
        int ct = 0;
        while(curr){
            curr = curr->next;
            ct++;
        }
        ct -= n;
        curr = new_head;
        while(ct--) curr = curr->next;
        temp = curr->next;
        curr->next = temp->next;
        temp->next = NULL;
        return new_head->next;
    }
};