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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* temp = head;
        int sum = 0;
        int carry = 0;
        int c = 0;
        
        while(l1 != NULL && l2 != NULL){
            if(c == 0){
                head = new ListNode();
                temp = head;
                c++;
            }
            else {
                temp -> next = new ListNode();
                temp = temp -> next;
            }
            sum = (l1 -> val) + (l2 -> val) + carry;
            if(sum > 9) carry = 1;
            else carry = 0;
            temp -> val = sum%10;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        while(l1 != NULL){
            temp -> next = new ListNode();
            temp = temp -> next;
            sum = (l1 -> val) + carry;
            if(sum > 9) carry = 1;
            else carry = 0;
            temp -> val = sum%10;
            l1 = l1 -> next;
            }
        
        while(l2 != NULL){
            temp -> next = new ListNode();
            temp = temp -> next;
            sum = (l2 -> val) + carry;
            if(sum > 9) carry = 1;
            else carry = 0;
            temp -> val = sum%10;
            l2 = l2 -> next;
        }
        
        while(carry != 0){
            temp -> next = new ListNode();
            temp = temp -> next;
            sum = carry;
            temp -> val = sum;
            carry = 0;
        }
        return head;
    }
};