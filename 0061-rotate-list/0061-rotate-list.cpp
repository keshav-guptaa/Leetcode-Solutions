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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int ct = 0;
        ListNode *curr = head, *prev = NULL;
        while(curr){
            ct++;
            prev = curr;
            curr = curr->next;
        }
        prev->next = head;
        
        k %= ct;
        ct -= k;
        //cout<<ct<<endl;
        curr = head;
        while(ct > 1){
            curr = curr->next;
            ct--;
        }
        cout << curr->val << endl;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};