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
        if(head == NULL || head->next == NULL){
            return false;
         } 
        ListNode* sptr = head;
        ListNode* fptr = head;

        while(fptr->next != NULL && fptr->next->next != NULL){
            sptr = sptr->next;
            fptr = fptr->next->next;
            if(sptr == fptr){
                return true;
            }
         
        }
        return false;
        }
};