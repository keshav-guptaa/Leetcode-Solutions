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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = NULL, *curr = slow, *ahead = NULL;
        while(curr != NULL){
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        ListNode *start = head, *end = prev;
        while(start && end){
            if(start->val != end->val) return false;
            start = start->next;
            end = end->next;
        }
        return true;
    }
};