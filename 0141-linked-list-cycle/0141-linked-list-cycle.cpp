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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        bool flag = 0;
        while(slow != NULL && fast != NULL && fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow){
                flag = 1;
                break;
            }
        }
        return flag;
    }
};