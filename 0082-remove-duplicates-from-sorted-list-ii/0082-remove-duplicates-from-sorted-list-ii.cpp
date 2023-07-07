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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode *new_head = new ListNode(101, head);
        ListNode *curr = head, *temp = NULL, *prev = new_head;
        bool f = 0;
        while(curr){
            temp = curr->next;
            f = 0;
            while(temp && curr->val == temp->val){
                temp = temp->next;
                f = 1;
            }
            if(f){
                prev->next = temp;
            }
            else prev = curr;
            curr = temp;
        }
        return new_head->next;
    }
};